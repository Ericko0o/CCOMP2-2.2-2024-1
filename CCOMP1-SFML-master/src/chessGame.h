#ifndef _CHESSGAME_H
#define _CHESSGAME_H

#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include <iostream>
#include "board.h"
#include "piece.h"
using namespace std;

class ChessGame: public sf::Drawable{
private:
    Board board;
    array<Piece, 16> whitePieces;
    array<Piece, 16> blackPieces;
    sf::RectangleShape selectionBorder;
    
    Piece* selectedPiece; //seguira la pieza seleccionada y la usaremos en todo el codigo sin necesidad de copiar toda la info de la pieza

    bool selected;
    bool playerTurn; // true = White , false = Black 
    bool playerTurnCheck;
    bool mate;
    int turn;

    void createSelectSquare();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    ChessGame(sf::Color bordL_col, sf::Color bordD_col);

    bool getSelected(){
        return selected;
    }

    bool selectPiece(int pos);

    void moveSelected(int pos);

    void restart();
    


};


#endif