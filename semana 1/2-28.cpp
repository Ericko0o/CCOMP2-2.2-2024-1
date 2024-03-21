#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(){
    int numero=23456;
    int digito1 = numero % 10;
    int digito2 = (numero / 10) % 10;
    int digito3 = (numero / 100) % 10;
    int digito4 = (numero / 1000);

    cout << digito1 << "  ";
    if (digito2 != 0) {
        cout << digito2 << "  ";
    }
    if (digito3 != 0) {
        cout << digito3 << "  ";
    }
    if (digito4 != 0) {
        cout << digito4;
    }
    cout << endl;

    return 0;
}