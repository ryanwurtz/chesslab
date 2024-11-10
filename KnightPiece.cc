#include "KnightPiece.hh"

using Student::KnightPiece;

KnightPiece::KnightPiece(ChessBoard &board, Color color, int row, int column) : ChessPiece(board,color,row,column) { }

bool KnightPiece::canMoveToLocation(int toRow, int toColumn) {
    int row = this->getRow();
    int col = this->getColumn();

    if (((toRow-row==2 || toRow-row==-2) && (toColumn-col==1 || toColumn-col==-1)) || 
    ((toRow-row==1 || toRow-row==-1) && (toColumn-col==2 || toColumn-col==-2))) {
        return true;
    }
    return false;
}

const char *KnightPiece::toString() {
    if (this->getColor() == Black) {return "\u265E";}
    return "\u2658";
}