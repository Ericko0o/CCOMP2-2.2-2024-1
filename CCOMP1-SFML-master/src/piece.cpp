#include "piece.h"

sf::Texture Piece::whiteKing;
sf::Texture Piece::blackKing;
sf::Texture Piece::whiteQueen;
sf::Texture Piece::blackQueen;
sf::Texture Piece::whiteRook;
sf::Texture Piece::blackRook;
sf::Texture Piece::whiteBishop;
sf::Texture Piece::blackBishop;
sf::Texture Piece::whiteKnight;
sf::Texture Piece::blackKnight;
sf::Texture Piece::whitePawn;
sf::Texture Piece::blackPawn;

void Piece::setPiece(char type, bool player, int pos, bool moved){
    setType(type);
    setPlayer(player);
    setPosition(pos); //m_moved true
    setMoved(moved); // m_moved false

}

void Piece::move(){
    if(m_position<=-1 || 64<=m_position){
        m_position = -1;
        m_sprite.setColor(sf::Color(0x00000000));//transparente
        m_sprite.setPosition(sf::Vector2f((m_position % 8) * 64.f + 32.f, (m_position / 8) * 64.f + 32.f)); //con el resto obtenemos el indice de columna, con la div el indice de fila
        possibleMoves.clear();
        m_moved = true;
    }
    else{
        m_sprite.setPosition(sf::Vector2f((m_position % 8) * 64.f + 32.f, (m_position / 8) * 64.f + 32.f));
        m_moved = true;
    }
    return;
}

void Piece::loadTextures(){
    whiteKing.loadFromFile("Textures/w_king.png");
    blackKing.loadFromFile("Textures/b_king.png");
    whiteQueen.loadFromFile("Textures/w_queen.png");
    blackQueen.loadFromFile("Textures/b_queen.png");
    whiteRook.loadFromFile("Textures/w_rook.png");
    blackRook.loadFromFile("Textures/b_rook.png");
    whiteBishop.loadFromFile("Textures/w_bishop.png");
    blackBishop.loadFromFile("Textures/b_bishop.png");
    whiteKnight.loadFromFile("Textures/w_knight.png");
    blackKnight.loadFromFile("Textures/b_knight.png");
    whitePawn.loadFromFile("Textures/w_pawn.png");
    blackPawn.loadFromFile("Textures/b_pawn.png");

}

void Piece::setTexture(){
    // ELIMINAR : m_sprite = sf::Sprite();creando una nueva instancia de sf::sprite, es el constructor
    switch (m_type)
    {
        case 'K':
            m_sprite.setTexture(m_player ? whiteKing : blackKing);
            break;
        case 'Q':
            m_sprite.setTexture(m_player ? whiteQueen : blackQueen);
            break;
        case 'R':
            m_sprite.setTexture(m_player ? whiteRook : blackRook);
            break;
        case 'B':
            m_sprite.setTexture(m_player ? whiteBishop : blackBishop);
            break;
        case 'N':
            m_sprite.setTexture(m_player ? whiteKnight : blackKnight);
            break;
        case 'P':
            m_sprite.setTexture(m_player ? whitePawn : blackPawn);
            break;
        default:
            std::cerr << "Error piece type does not exist.\n";
            break;
    }
    m_sprite.setOrigin(sf::Vector2f(m_sprite.getTexture()->getSize().x/2 , m_sprite.getTexture()->getSize().y/2));//definimos el centro de la textura, el origen donde se realizaran transformaciones
    m_sprite.setScale(sf::Vector2f(0.150f,0.150)); //la sprite se escala a 0.150 veces su tamaño original, se hace mas pequeña
}

void Piece::draw(sf::RenderTarget& target, sf::RenderStates states) const{
        target.draw(m_sprite);  
    }