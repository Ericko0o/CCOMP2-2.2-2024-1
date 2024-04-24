// Fig. 7.19: GradeBook.h
// Definition of class GradeBook that uses a
// two-dimensional array to store test grades.
#include <array>
#include <string>
#include <iostream>
#include <iomanip> // parameterized stream manipulators

// GradeBook class definition
class GradeBook {
public:
    // Constants
    static const size_t students{10}; // For example, set to 10
    static const size_t tests{3}; // For example, set to 3

    // Two-argument constructor initializes courseName and grades array
    GradeBook(const std::string& name, std::array<std::array<int, tests>, students>& gradesArray)
        : courseName(name), grades(gradesArray) {
    }

    // Function to set the course name
    void setCourseName(const std::string& name) {
        courseName = name; // Store the course name
    }

    // Function to retrieve the course name
    const std::string& getCourseName() const {
        return courseName;
    }

    // Display a welcome message to the GradeBook user
    void displayMessage() const {
        // Call getCourseName to get this GradeBook’s course name
        std::cout << "Welcome to the grade book for\n" << getCourseName() << "!" << std::endl;
    }

    // Perform various operations on the data
    void processGrades() const {
        outputGrades(); // Output grades array

        // Call functions getMinimum and getMaximum
        std::cout << "\nLowest grade in the grade book is " << getMinimum()
            << "\nHighest grade in the grade book is " << getMaximum() << std::endl;

        outputBarChart(); // Display grade distribution chart
    }

    // Find minimum grade in the entire gradebook
    int getMinimum() const {
        int lowGrade{100}; // Assume lowest grade is 100

        // Loop through rows of grades array
        for (auto const& student : grades) {
            // Loop through columns of current row
            for (auto const& grade : student) {
                if (grade < lowGrade) { // If grade is lower than lowGrade
                    lowGrade = grade; // Grade is new lowest grade
                }
            }
        }

        return lowGrade; // Return lowest grade
    }

    // Find maximum grade in the entire gradebook
    int getMaximum() const {
        int highGrade{0}; // Assume highest grade is 0

        // Loop through rows of grades array
        for (auto const& student : grades) {
            // Loop through columns of current row
            for (auto const& grade : student) {
                if (grade > highGrade) { // If grade is higher than highGrade
                    highGrade = grade; // Grade is new highest grade
                }
            }
        }

        return highGrade; // Return highest grade
    }

    // Determine average grade for particular set of grades
    double getAverage(const std::array<int, tests>& setOfGrades) const {
        int total{0}; // Initialize total

        // Sum grades in array
        for (int grade : setOfGrades) {
            total += grade;
        }

        // Return average of grades
        return static_cast<double>(total) / setOfGrades.size();
    }

    // Output bar chart displaying grade distribution
    void outputBarChart() const {
        std::cout << "\nOverall grade distribution:" << std::endl;

        // Stores frequency of grades in each range of 10 grades
        const size_t frequencySize{11};
        std::array<unsigned int, frequencySize> frequency{}; // Initialize to 0s

        // For each grade, increment the appropriate frequency
        for (auto const& student : grades) {
            for (auto const& test : student) {
                ++frequency[test / 10];
            }
        }

        // For each grade frequency, print bar in chart
        for (size_t count{0}; count < frequencySize; ++count) {
            // Output bar label ("0-9:", ..., "90-99:", "100:")
            if (0 == count) {
                std::cout << " 0-9: ";
            } else if (10 == count) {
                std::cout << " 100: ";
            } else {
                std::cout << count * 10 << "-" << (count * 10) + 9 << ": ";
            }

            // Print bar of asterisks
            for (unsigned int stars{0}; stars < frequency[count]; ++stars) {
                std::cout << '*';
            }

            std::cout << std::endl; // Start a new line of output
        }
    }

    // Output the contents of the grades array
    void outputGrades() const {
        std::cout << "\nThe grades are:\n\n";
        std::cout << " "; // Align column heads

        // Create a column heading for each of the tests
        for (size_t test{0}; test < tests; ++test) {
            std::cout << "Test " << test + 1 << " ";
        }

        std::cout << "Average" << std::endl;

        // Create rows/columns of text representing array grades
        for (size_t student{0}; student < grades.size(); ++student) {
            std::cout << "Student " << std::setw(2) << student + 1;

            // Output student's grades
            for (size_t test{0}; test < grades[student].size(); ++test) {
                std::cout << std::setw(8) << grades[student][test];
            }

            // Call member function getAverage to calculate student's
            // average; pass one row of grades as the argument
            double average{ getAverage(grades[student]) };
            std::cout << std::setw(9) << std::setprecision(2) << std::fixed
                << average << std::endl;
        }
    }

private:
    std::string courseName; // Course name for this grade book
    std::array<std::array<int, tests>, students> grades; // Two-dimensional array of student grades
};
