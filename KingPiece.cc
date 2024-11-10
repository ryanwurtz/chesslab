#include "KingPiece.hh"

using Student::KingPiece;

KingPiece::KingPiece(ChessBoard& board, Color color, int row, int column) : ChessPiece(board,color,row,column) { }

bool KingPiece::canMoveToLocation(int toRow, int toColumn) {
    int row = this->getRow();
    int col = this->getColumn();
    if ((toRow-row==-1 || toRow-row==0 || toRow-row==1)&&(toColumn-col==-1 || toColumn-col==0 || toColumn-col==1)) {return true;}
    return false;
}

const char* KingPiece::toString() {
    if (this->getColor() == Black) {return "\u265A";}
    return "\u2654";
}