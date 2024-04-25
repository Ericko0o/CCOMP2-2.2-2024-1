#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <string>
#include <array>
#include <iostream>
#include <iomanip>

// Clase GradeBook: Contiene funcionalidades para el manejo de calificaciones
class GradeBook {
public:
    // Número estático de estudiantes que realizaron el examen
    static const size_t students = 10;

    // Constructor que inicializa el nombre del curso y el arreglo de calificaciones
    GradeBook(const std::string& nombre,
              const std::array<int, students>& calificacionesArray)
        : nombreCurso{nombre}, calificaciones{calificacionesArray} {
    }

    // Función para establecer el nombre del curso
    void establecerNombreCurso(const std::string& nombre) {
        nombreCurso = nombre; // Guarda el nombre del curso
    }

    // Función para obtener el nombre del curso
    const std::string& obtenerNombreCurso() const {
        return nombreCurso;
    }

    // Muestra un mensaje de bienvenida al usuario del GradeBook
    void mostrarMensaje() const {
        // Obtiene el nombre del curso y muestra un mensaje de bienvenida
        std::cout << "¡Bienvenido al libro de calificaciones para\n" << obtenerNombreCurso()
                  << "!" << std::endl;
    }

    // Realiza varias operaciones en los datos (sin modificarlos)
    void procesarCalificaciones() const {
        mostrarCalificaciones(); // Muestra las calificaciones

        // Calcula y muestra el promedio de calificaciones
        std::cout << std::setprecision(2) << std::fixed; 
        std::cout << "\nEl promedio de la clase es: " << obtenerPromedio() << std::endl;

        // Muestra la calificación mínima y máxima
        std::cout << "La calificación más baja es: " << obtenerMinimo()
                  << "\nLa calificación más alta es: " << obtenerMaximo() << std::endl;

        mostrarGraficoBarras(); // Muestra el gráfico de distribución de calificaciones
    }

    // Encuentra la calificación mínima
    int obtenerMinimo() const {
        int calificacionBaja{100}; // Se asume que la calificación más baja es 100

        // Recorre el arreglo de calificaciones
        for (int calificacion : calificaciones) {
            // Si la calificación actual es menor que la calificaciónBaja, se actualiza
            if (calificacion < calificacionBaja) {
                calificacionBaja = calificacion; // Nueva calificación más baja
            }
        }

        return calificacionBaja; // Devuelve la calificación más baja
    }

    // Encuentra la calificación máxima
    int obtenerMaximo() const {
        int calificacionAlta{0}; // Se asume que la calificación más alta es 0

        // Recorre el arreglo de calificaciones
        for (int calificacion : calificaciones) {
            // Si la calificación actual es mayor que la calificaciónAlta, se actualiza
            if (calificacion > calificacionAlta) {
                calificacionAlta = calificacion; // Nueva calificación más alta
            }
        }

        return calificacionAlta; // Devuelve la calificación más alta
    }

    // Calcula el promedio de calificaciones para el examen
    double obtenerPromedio() const {
        int total{0}; // Inicializa el total

        // Suma las calificaciones en el arreglo
        for (int calificacion : calificaciones) {
            total += calificacion;
        }

        // Devuelve el promedio de las calificaciones
        return static_cast<double>(total) / calificaciones.size();
    }

    // Muestra el gráfico de barras que representa la distribución de calificaciones
    void mostrarGraficoBarras() const {
        std::cout << "\nDistribución de calificaciones:" << std::endl;

        // Almacena la frecuencia de las calificaciones en cada rango de 10
        const size_t tamanoFrecuencia{11};
        std::array<unsigned int, tamanoFrecuencia> frecuencia{}; // Inicializa a 0s

        // Para cada calificación, incrementa la frecuencia apropiada
        for (int calificacion : calificaciones) {
            ++frecuencia[calificacion / 10];
        }

        // Para cada frecuencia de calificación, imprime la barra en el gráfico
        for (size_t contador{0}; contador < tamanoFrecuencia; ++contador) {
            // Imprime etiquetas de barra ("0-9:", ..., "90-99:", "100:")
            if (0 == contador) {
                std::cout << "  0-9: ";
            } else if (10 == contador) {
                std::cout << "  100: ";
            } else {
                std::cout << contador * 10 << "-" << (contador * 10) + 9 << ": ";
            }

            // Imprime la barra de asteriscos
            for (unsigned int estrellas{0}; estrellas < frecuencia[contador]; ++estrellas) {
                std::cout << '*';
            }

            std::cout << std::endl; // Inicia una nueva línea de salida
        }
    }

    // Muestra el contenido del arreglo de calificaciones
    void mostrarCalificaciones() const {
        std::cout << "\nLas calificaciones son:\n\n";

        // Imprime la calificación de cada estudiante
        for (size_t estudiante{0}; estudiante < calificaciones.size(); ++estudiante) {
            std::cout << "Estudiante " << std::setw(2) << estudiante + 1 << ": "
                      << std::setw(3) << calificaciones[estudiante] << std::endl;
        }
    }

private:
    std::string nombreCurso; // Nombre del curso para este libro de calificaciones
    std::array<int, students> calificaciones; // Arreglo de calificaciones de estudiantes
};

#endif // GRADEBOOK_H
