#include "RookPiece.hh"

using Student::ChessBoard;

RookPiece::RookPiece(ChessBoard &board, Color color, int row, int column) : ChessPiece(board,color,row,column) { }

RookPiece::~RookPiece() { }

Type RookPiece::getType() {return type;}

bool RookPiece::canMoveToLocation(int toRow, int toColumn) {
    Color color = this->getColor();
    int row = this->getRow();
    int column = this->getColumn();

    //checking if move horizontal or vertical
    if (row != toRow && column != toColumn) {return false;}
    
    return true;   
}

const char *RookPiece::toString() {
    if (this->getColor() == Black) {return "\u265C";}
    return "\u2656";

}