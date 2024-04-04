#include <iostream>
#include <string>
using std::cout;
using std:: cin;

class Student {
public:
    explicit Student(std::string n, int a): name(n), age(a) {} //constructor

    std::string getName() const {
        return name;
    }

    void setName(const std::string& n) {
        name = n;
    }

    int getAge() const {
        return age;
    }

    void setAge(int a) {
        age = a;
    }

    bool isOlder() const {
        return age >= 18;
    }

private:
    std::string name;
    int age;
};

int main() {
    std::string name;
    int age;

    cout << "Ingrese el nombre del estudiante: ";
    cin >> name;
    cout << "Ingrese la edad del estudiante: ";
    cin >> age;
    Student student(name, age);

    cout << "\nDatos del estudiante:" << std::endl;
    cout << "Nombre: " << student.getName() << std::endl;
    cout << "Edad: " << student.getAge() << std::endl;
    cout << "Es mayor de edad: " << (student.isOlder() ? "Si" : "No") << std::endl;

    return 0;
}
