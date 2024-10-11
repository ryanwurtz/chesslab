#include "PawnPiece.hh"

using Student::ChessBoard;

//constructor
PawnPiece::PawnPiece(ChessBoard &board, Color color, int row, int column) : ChessPiece(board,color,row,column) { }

//destructor
PawnPiece::~PawnPiece() { }

//setPosition
void PawnPiece::setPosition(int row, int column) {
    row=row;
    column=column;
}

//canMoveToLocation
bool PawnPiece::canMoveToLocation(int toRow, int toColumn) {

}

//toString
const char *PawnPiece::toString() {

}