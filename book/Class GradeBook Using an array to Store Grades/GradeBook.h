#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <array>
#include <iomanip> // Librería para formateo de salida
#include <iostream>
#include <string>

class GradeBook {
public:
  // Definir constantes para el número de estudiantes y pruebas
  static const size_t students = 10; // Estudiantes: 10
  static const size_t tests = 3; // Pruebas: 3

  // Constructor que inicializa el nombre del curso y las calificaciones
  GradeBook(const std::string &name,
            std::array<std::array<int, tests>, students> &gradesArray)
      : courseName(name), grades(gradesArray) {}

  // Función para establecer el nombre del curso
  void setCourseName(const std::string &name) {
    courseName = name; // Asignar el nombre del curso
  }

  // Función para obtener el nombre del curso
  const std::string &getCourseName() const { return courseName; }

  // Mostrar mensaje de bienvenida
  void displayMessage() const {
    std::cout << "Bienvenido al libro de calificaciones de\n"
              << getCourseName() << "!" << std::endl;
  }

  // Procesar las calificaciones
  void processGrades() const { 
    outputGrades(); // Mostrar calificaciones

    std::cout << "\nLa calificación más baja es "
              << getMinimum()
              << "\nLa calificación más alta es "
              << getMaximum() << std::endl;

    outputBarChart(); // Mostrar gráfico de barras
  }

  // Encontrar la calificación mínima
  int getMinimum() const {
    int lowGrade{100}; // Inicializar calificación mínima

    for (auto const &student : grades) {
      for (auto const &grade : student) {
        if (grade < lowGrade) { // Si la calificación es menor
          lowGrade = grade; // Actualizar calificación mínima
        }
      }
    }

    return lowGrade; // Devolver calificación mínima
  }

  // Encontrar la calificación máxima
  int getMaximum() const {
    int highGrade{0}; // Inicializar calificación máxima

    for (auto const &student : grades) {
      for (auto const &grade : student) {
        if (grade > highGrade) { // Si la calificación es mayor
          highGrade = grade; // Actualizar calificación máxima
        }
      }
    }

    return highGrade; // Devolver calificación máxima
  }

  // Calcular promedio de un conjunto de calificaciones
  double getAverage(const std::array<int, tests> &setOfGrades) const {
    int total{0}; // Inicializar total

    for (int grade : setOfGrades) {
      total += grade; // Sumar calificaciones
    }

    return static_cast<double>(total) / setOfGrades.size(); // Calcular promedio
  }

  // Mostrar gráfico de barras
  void outputBarChart() const {
    std::cout << "\nDistribución de calificaciones:\n";

    const size_t frequencySize{11};
    std::array<unsigned int, frequencySize> frequency{}; // Inicializar frecuencia

    for (auto const &student : grades) { 
      for (auto const &test : student) {
        ++frequency[test / 10]; // Incrementar frecuencia
      }
    }

    for (size_t count{0}; count < frequencySize; ++count) {
      // Mostrar rango de calificaciones
      if (0 == count) {
        std::cout << "  0-9: ";
      } else if (10 == count) {
        std::cout << "  100: ";
      } else {
        std::cout << count * 10 << "-" << (count * 10) + 9 << ": ";
      }

      // Mostrar barras
      for (unsigned int stars{0}; stars < frequency[count]; ++stars)
        std::cout << '*';

      std::cout << std::endl; // Nueva línea
    }
  }

  // Mostrar calificaciones
  void outputGrades() const {
    std::cout << "\nCalificaciones:\n\n";
    std::cout << "            "; // Encabezado de columna

    for (size_t test{0}; test < tests; ++test) { //
      std::cout << "Prueba " << test + 1 << "  "; //
    }

    std::cout << "Promedio" << std::endl;

    // Mostrar calificaciones de cada estudiante
    for (size_t student{0}; student < grades.size(); ++student) {
      std::cout << "Estudiante " << std::setw(2) << student + 1;

      // Mostrar calificaciones
      for (size_t test{0}; test < grades[student].size(); ++test) {
        std::cout << std::setw(8) << grades[student][test];
      }

      // Calcular y mostrar promedio del estudiante
      double average = getAverage(grades[student]);
      std::cout << std::setw(9) << std::setprecision(2) << std::fixed << average
                << std::endl;
    }
  }

private:
  std::string courseName; // Nombre del curso
  std::array<std::array<int, tests>, students> &grades;
};

#endif // GRADEBOOK_H
