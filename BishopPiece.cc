#include "BishopPiece.hh"

using Student::ChessBoard;

BishopPiece::BishopPiece(ChessBoard &board, Color color, int row, int column) : ChessPiece(board,color,row,column) { }

BishopPiece::~BishopPiece() { }

bool BishopPiece::canMoveToLocation(int toRow, int toColumn) {
    Color color = getColor();
    int row = getRow();
    int column = getColumn();

    //checking if move is diagonal
    if ((toRow-row != toColumn-column) && (toRow-row != column-toColumn)) {return false;}
    
    return true;
}

const char *BishopPiece::toString() {
    if (getColor() == Black) {return "\u265D"}
    else {return "\u2657"}
}