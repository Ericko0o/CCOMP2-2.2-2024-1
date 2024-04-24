#ifndef CPARTIDA_H
#define CPARTIDA_H

#include "Header.h"
#include "CTabla.h"

class CPartida {
    CTabla tablero; //miembro, instancia de la clase tabla
    int opcion;
    string posOrigen;
    string posDestino;
    bool turno;  // true: Piezas blancas, false: Piezas negras
public:
    CPartida();
    void anunciarGanador() const;
    void ejecutarMovimiento();
    void ejecutarPartida();
};

#endif