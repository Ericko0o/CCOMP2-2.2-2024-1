#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

int main() {
    array<int, 5> n; // n es un arreglo de 5 valores int

    // inicializar los elementos del arreglo n a 0
    for (size_t i{0}; i < n.size(); ++i) {
        n[i] = 0; // establecer el elemento en la posición i a 0
    }

    cout << "Element" << setw(10) << "Value" << endl;

    // salida del valor de cada elemento del arreglo
    for (size_t j{0}; j < n.size(); ++j) {
        cout << setw(7) << j << setw(10) << n[j] << endl;
    }
    return 0;
}
