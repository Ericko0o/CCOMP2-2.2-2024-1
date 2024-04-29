#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;


class CTabla {
private:
    unsigned int tamX;
    unsigned int tamY;
    unsigned int numPiezas;
   
public:
    CTabla();
    void imprimirTabla();
    bool posicionValida(string pos) const;
    void eliminarPieza(int y, int x);
    bool moverPieza(int y1, int x1, int y2, int x2, bool turno);
};