#include "BishopPiece.hh"

using Student::BishopPiece;

BishopPiece::BishopPiece(ChessBoard &board, Color color, int row, int column) : ChessPiece(board,color,row,column) { }

bool BishopPiece::canMoveToLocation(int toRow, int toColumn) {
    int row = this->getRow();
    int column = this->getColumn();

    //checking if move is diagonal
    if ((toRow-row == toColumn-column) || (toRow-row == column-toColumn)) {return true;}
    
    return false;
}

const char* BishopPiece::toString() {
    if (this->getColor() == Black) {return "\u265D";}
    return "\u2657";
}