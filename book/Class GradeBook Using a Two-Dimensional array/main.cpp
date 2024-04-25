#include <array>
#include "GradeBook.h" // Incluimos la definición de la clase GradeBook
using namespace std;

int main() {
   // Definición del array de calificaciones de los estudiantes
   const array<int, GradeBook::students> calificaciones{ 
      87, 68, 94, 100, 83, 78, 85, 91, 76, 87}; // Suponiendo que GradeBook::students es el tamaño
   string nombreCurso{"CS101 Introducción a la programación en C++"};

   // Creación de un objeto GradeBook
   GradeBook miLibroCalificaciones(nombreCurso, calificaciones);
   miLibroCalificaciones.mostrarMensaje(); // Mostramos el mensaje de bienvenida
   miLibroCalificaciones.procesarCalificaciones(); // Procesamos las calificaciones
}
