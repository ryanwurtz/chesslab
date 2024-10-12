#include "RookPiece.hh"

using Student::ChessBoard;

RookPiece::RookPiece(ChessBoard &board, Color color, int row, int column) : ChessPiece(board,color,row,column) { }

RookPiece::~RookPiece() { }

bool RookPiece::canMoveToLocation(int toRow, int toColumn) {
    Color color = getColor();
    int row = getRow();
    int column = getColumn();

    //checking if move horizontal or vertical
    if (row != toRow && column != toColumn) {return false;}
    
    return true;   
}

const char *RookPiece::toString() {
    if (getColor() == Black) {return "\u265C"}
    else {return "\u2656"}

}