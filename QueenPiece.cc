#include "QueenPiece.hh"

using Student::QueenPiece;

QueenPiece::QueenPiece(ChessBoard &board, Color color, int row, int column) : ChessPiece(board,color,row,column) { }

bool QueenPiece::canMoveToLocation(int toRow, int toColumn) {
    int row = this->getRow();
    int col = this->getColumn();

    if (toRow==row || toColumn==col || toRow-row == toColumn-col || toRow-row == col-toColumn) {
        return true;
    }
    return false;
}

const char *QueenPiece::toString() {
    if (this->getColor() == Black) {return "\u265A";}
    return "\u2654";
}