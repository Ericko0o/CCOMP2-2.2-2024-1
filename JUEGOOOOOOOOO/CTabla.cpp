#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;
#include "CTabla.h"

CTabla::CTabla() : tamX{8},tamY{8}, numPiezas{32} {
}

void CTabla::imprimirTabla(){
    string tabla[tamY][tamX];

    //creamos espacios vacios
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            tabla[i][j] = "";
            }
    }
 
    //dibujamos las lineas divisorias
    for(int i=7; i>=0; i--){
        // Parte separadora
        cout << endl << string(2,' ');
        for(int j=0; j<8; j++){
            cout << setfill('-') << setw(5) << left << '+';
        }
        cout << '+' << endl;
        
        // Parte de las casillas
        cout << setfill(' ') << setw(2) << left << i+1;//imprimimos asignacion de cada fila //setw->establece ancho de campo
        for(int j=0; j<8; j++){
            cout << setfill(' ') << setw(2) << left << '|';
            cout << setfill(' ') << setw(3) << left << tabla[i][j];
        }
        cout << '|';
    
    }

    cout << endl << string(2,' ');
        for(int j=0; j<8; j++){
            cout << setfill('-') << setw(5) << left << '+';
        }
    cout << '+' << endl;  
    
    //LETRAS
    cout << string(2,' ');
    for(int i=0; i<8; i++){
        cout << setfill(' ') << setw(2) << left << ' ';
        cout << setfill(' ') << setw(3) << left << char('A'+i);
    }
    cout << ' ' << endl;


}

bool CTabla::posicionValida (string pos) const {
    if(pos.size()!=2) {
        return false;}
    if(not(pos[0]>='A' and pos[0]<'A'+tamX)) {
        return false;}
    if(not(pos[1]>='1' and pos[1]<'1'+tamY)) {
        return false;}
    
    return true;
}