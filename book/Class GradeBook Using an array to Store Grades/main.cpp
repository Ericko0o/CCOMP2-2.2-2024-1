#include "GradeBook.h" // Incluimos la definición de GradeBook
#include <array>

int main() {
  // Creación de una matriz bidimensional para almacenar calificaciones de estudiantes
  std::array<std::array<int, 3>, 10> grades{{{87, 96, 70},
                                             {68, 87, 90},
                                             {94, 100, 90},
                                             {100, 81, 82},
                                             {83, 65, 85},
                                             {78, 87, 65},
                                             {85, 75, 83},
                                             {91, 94, 100},
                                             {76, 72, 84},
                                             {87, 93, 73}}};

  // Creación de un objeto GradeBook
  GradeBook myGradeBook("CS101 Introducción a la programación en C++", grades);
  myGradeBook.displayMessage(); // Mostrar mensaje de bienvenida
  myGradeBook.processGrades(); // Procesar calificaciones
}
