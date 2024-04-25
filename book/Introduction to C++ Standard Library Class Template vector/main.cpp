#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept> // Para std::out_of_range

using namespace std;

void mostrarVector(const vector<int>&); // Función para mostrar el vector
void ingresarVector(vector<int>&);      // Función para ingresar valores en el vector

int main() {
    vector<int> enteros1(7); // Vector de 7 elementos
    vector<int> enteros2(10); // Vector de 10 elementos

    // Muestra el tamaño y contenido de enteros1
    cout << "Tamaño del vector enteros1: " << enteros1.size() << "\nContenido después de la inicialización: ";
    mostrarVector(enteros1);

    // Muestra el tamaño y contenido de enteros2
    cout << "\nTamaño del vector enteros2: " << enteros2.size() << "\nContenido después de la inicialización: ";
    mostrarVector(enteros2);


  
    // Ingresa y muestra enteros1 y enteros2
    cout << "\nIngrese 7 enteros para enteros1:" << endl;
    ingresarVector(enteros1);
    cout << "Ingrese 10 enteros para enteros2:" << endl;
    ingresarVector(enteros2);

    cout << "\nDespués de ingresar, los vectores contienen:\n"
         << "enteros1:";
    mostrarVector(enteros1);
    cout << "enteros2:";
    mostrarVector(enteros2);

    // Usa el operador de desigualdad (!=) con objetos vector
    cout << "\nEvaluando: enteros1 != enteros2" << endl;
    if (enteros1 != enteros2) {
        cout << "enteros1 y enteros2 no son iguales" << endl;
    }

    // Crea el vector enteros3 usando enteros1 como inicializador; muestra tamaño y contenido
    vector<int> enteros3{enteros1}; // Constructor de copia
    cout << "\nTamaño del vector enteros3: " << enteros3.size() << "\nContenido después de la inicialización: ";
    mostrarVector(enteros3);

    // Usa el operador de asignación sobrecargado (=)
    cout << "\nAsignando enteros2 a enteros1:" << endl;
    enteros1 = enteros2; // Asigna enteros2 a enteros1
    cout << "enteros1: ";
    mostrarVector(enteros1);
    cout << "enteros2: ";
    mostrarVector(enteros2);

    // Usa el operador de igualdad (==) con objetos vector
    cout << "\nEvaluando: enteros1 == enteros2" << endl;
    if (enteros1 == enteros2) {
        cout << "enteros1 y enteros2 son iguales" << endl;
    }

    // Usa corchetes para obtener el valor en la posición 5 como rvalue
    cout << "\nenteros1[5] es: " << enteros1[5] << endl;

    // Usa corchetes para crear lvalue
    cout << "\nAsignando 1000 a enteros1[5]" << endl;
    enteros1[5] = 1000;
    cout << "enteros1: ";
    mostrarVector(enteros1);

    // Intenta usar un índice fuera de rango
    try {
        cout << "Intento de mostrar enteros1.at(15)" << endl;
        cout << enteros1.at(15) << endl; // ERROR: fuera de rango
    } catch (out_of_range& ex) {
        cerr << "Se produjo una excepción: " << ex.what() << endl;
    }

    // Cambia el tamaño de un vector
    cout << "\nTamaño actual de enteros3: " << enteros3.size() << endl;
    enteros3.push_back(1000); // Agrega 1000 al final del vector
    cout << "Nuevo tamaño de enteros3: " << enteros3.size() << endl;
    cout << "enteros3 ahora contiene: ";
    mostrarVector(enteros3);

    return 0;
}

// Muestra el contenido del vector
void mostrarVector(const vector<int>& elementos) {
    for (int elemento : elementos) {
        cout << elemento << " ";
    }
    cout << endl;
}

// Ingresa contenido en el vector
void ingresarVector(vector<int>& elementos) {
    for (int& elemento : elementos) {
        cin >> elemento;
    }
}
