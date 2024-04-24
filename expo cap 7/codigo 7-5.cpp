#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

int main() {
    const size_t arraySize{5};
    array<int, arraySize> values; // el arreglo values tiene 5 elementos

    for (size_t i{0}; i < values.size(); ++i) { // establecer los valores
        values[i] = 2 + 2 * i;
    }

    cout << "Element" << setw(10) << "Value" << endl;

    // salida del contenido del arreglo en formato tabular
    for (size_t j{0}; j < values.size(); ++j) {
        cout << setw(7) << j << setw(10) << values[j] << endl;
    }

    return 0;
}
