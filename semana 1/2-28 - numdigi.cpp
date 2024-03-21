#include <iostream>
using namespace std;

int main() {
    int numero;
    cout << "numero entero: ";
    cin >> numero;

    int contador = 0;
    int a = numero;

    while (a != 0) {
        contador++;
        a /= 10;
    }

    cout << "el numero " << numero << " tiene " << contador << " digitos." << endl;

    return 0;
}
