#include "KingPiece.hh"

using Student::KingPiece;

KingPiece::KingPiece(ChessBoard& board, Color color, int row, int column) : ChessPiece(board,color,row,column) { }

bool KingPiece::canMoveToLocation(int toRow, int toColumn) {
    if ((toRow-row==-1 || toRow-row==0 || toRow-row==1)&&(toColumn-column==-1 || toColumn-column==0 || toColumn-column==1)) {return true;}
    return false;
}

const char* KingPiece::toString() {
    if (this->getColor() == Black) {return "\u265A";}
    return "\u2654";
}