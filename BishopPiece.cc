#include "BishopPiece.hh"

using Student::ChessBoard;

BishopPiece::BishopPiece(ChessBoard &board, Color color, int row, int column) : ChessPiece(board,color,row,column) { }

BishopPiece::~BishopPiece() { }

Type BishopPiece::getType() {return type;}

bool BishopPiece::canMoveToLocation(int toRow, int toColumn) {
    Color color = this->getColor();
    int row = this->getRow();
    int column = this->getColumn();

    //checking if move is diagonal
    if ((toRow-row != toColumn-column) && (toRow-row != column-toColumn)) {return false;}
    
    return true;
}

const char *BishopPiece::toString() {
    if (this->getColor() == Black) {return "\u265D";}
    return "\u2657";
}