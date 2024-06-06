#include <iostream>
using namespace std;

int encontrarcuantasveceshay(char matriz[][8], int filas) {
    int total = 0;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (matriz[i][j] == 'A' || matriz[i][j] == 'a') {
                total++;
            }
        }
    }
    return total;
}

int main() {
    char matriz[8][8] = {
        {'A', '3', 'a', 'a', 'u', 'a', 'a', 'a'},
        {'a', 'p', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'A', 'a', 'a', 'a', 'P', 'a', 'a'},
        {'a', 'a', 'Q', 'a', 'A', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'H', 'a'},
        {'a', 'k', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'T', 'a', 'a', 'a', 'n'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'A'}
    };

    int total = encontrarcuantasveceshay(matriz, 8);
    cout << "En total, la letra 'A' se repite " << total << " veces en la matriz." << endl;
    return 0;
}
