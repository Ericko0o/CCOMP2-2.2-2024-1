// Fig. 7.21: fig07_21.cpp
// Demonstrating C++ Standard Library class template vector.
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void outputVector(const vector<int>& items); // Display the vector
void inputVector(vector<int>& items); // Input values into the vector

int main() {
    vector<int> integers1; // Create a vector of ints
    vector<int> integers2(7); // Create a vector of 7 ints
    vector<int> integers3; // Create an empty vector

    // Print integers1 size and contents
    cout << "Size of vector integers1 is " << integers1.size()
        << "\nvector after initialization:";
    outputVector(integers1);

    // Print integers2 size and contents
    cout << "\nSize of vector integers2 is " << integers2.size()
        << "\nvector after initialization:";
    outputVector(integers2);

    // Input and print integers1 and integers2
    cout << "\nEnter 17 integers:" << endl;
    inputVector(integers1);
    inputVector(integers2);

    cout << "\nAfter input, the vectors contain:\n"
        << "integers1:";
    outputVector(integers1);
    cout << "integers2:";
    outputVector(integers2);

    // Use inequality (!=) operator with vector objects
    cout << "\nEvaluating: integers1 != integers2" << endl;

    if (integers1 != integers2) {
        cout << "integers1 and integers2 are not equal" << endl;
    }

    // Create vector integers3 using integers1 as an initializer; print size and contents
    integers3 = integers1; // Copy integers1 to integers3

    cout << "\nSize of vector integers3 is " << integers3.size()
        << "\nvector after initialization: ";
    outputVector(integers3);

    cout << "integers1: ";
    outputVector(integers1);
    cout << "integers2: ";
    outputVector(integers2);

    // Use equality (==) operator with vector objects
    cout << "\nEvaluating: integers1 == integers2" << endl;

    if (integers1 == integers2) {
        cout << "integers1 and integers2 are equal" << endl;
    }

    // Use square brackets to use the value at location 5 as an rvalue
    cout << "\nintegers1[5] is " << integers1[5];

    // Use square brackets to create lvalue
    cout << "\n\nAssigning 1000 to integers1[5]" << endl;
    integers1[5] = 1000;

    cout << "integers1: ";
    outputVector(integers1);

    try {
        cout << "\nAttempt to display integers1.at(15)" << endl;
        cout << integers1.at(15) << endl; // ERROR: out of range
    }
    catch (out_of_range& ex) {
        cerr << "An exception occurred: " << ex.what() << endl;
    }

    // Changing the size of a vector
    cout << "\nCurrent integers3 size is: " << integers3.size() << endl;
    integers3.push_back(1000); // Add 1000 to the end of the vector
    cout << "New integers3 size is: " << integers3.size() << endl;
    cout << "integers3 now contains: ";
    outputVector(integers3);
}

// Output vector contents
void outputVector(const vector<int>& items) {
    for (int item : items) {
        cout << item << " ";
    }

    cout << endl;
}

// Input vector contents
void inputVector(vector<int>& items) {
    for (int& item : items) {
        cin >> item;
    }
}