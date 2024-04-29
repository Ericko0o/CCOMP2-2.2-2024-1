/**
 * Implemente un programa que pida por teclado una cadena considerando espacios,
 * y convierta dicha cadena a Mayusculas
*/
#include <iostream>

using namespace std;
/* Paso por valor */
string stringToUppercaseXValor(string cad) {
    char c;
    for( int i = 0; i < cad.size(); i++ ) {        
        c = cad.at(i);
        int val = static_cast<int>(c);
        if(val >= 97 && val <= 122)
            cad.at(i) = c - 32;  //toupper(c);
    }
    return cad;
}

/* Paso por referencia */
void stringToUppercaseXRef(string &cad) {
    char c;
    for( int i = 0; i < cad.size(); i++ ) {        
        c = cad.at(i);
        int val = static_cast<int>(c);
        if(val >= 97 && val <= 122)
            cad.at(i) = c - 32;  //toupper(c);
    }
}

int main(){
    string cad;
    cout << "Ingrese una cadena por favor: ";
    getline(cin, cad);

    //cout << stringToUppercase(cad) << endl;
    stringToUppercaseXRef(cad);
    cout << cad << endl;
    return 0;
}

