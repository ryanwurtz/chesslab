#include "RookPiece.hh"

using Student::RookPiece;

RookPiece::RookPiece(ChessBoard &board, Color color, int row, int column) : ChessPiece(board,color,row,column) { }

bool RookPiece::canMoveToLocation(int toRow, int toColumn) {
    int row = this->getRow();
    int column = this->getColumn();

    //checking if move horizontal or vertical
    if (row != toRow && column != toColumn) {return false;}
    
    return true;   
}

const char* RookPiece::toString() {
    if (this->getColor() == Black) {return "\u265C";}
    return "\u2656";

}