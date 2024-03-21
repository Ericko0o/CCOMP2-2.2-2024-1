#include <iostream>
using namespace std;

int sumaRecursiva(const int array[], const int tam, int indice = 0) {
    if (indice == tam) {
        return 0;
    }
    
    return array[indice] + sumaRecursiva(array, tam, indice + 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    cout << "Suma de elementos: " << sumaRecursiva(arr, 12) << endl;
    return 0;
}
