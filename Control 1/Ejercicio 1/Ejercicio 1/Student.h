#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
public:
    explicit Student(std::string n, int a);


    std::string getName() const;
    void setName(const std::string& n);
    int getAge() const;
    void setAge(int a);

    bool isOlder() const;

private:
    std::string name;
    int age;
};

#endif
