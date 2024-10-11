#include "BishopPiece.hh"

using Student::ChessBoard;

//constructor
BishopPiece::BishopPiece(ChessBoard &board, Color color, int row, int column) : ChessPiece(board,color,row,column) { }

//destructor
BishopPiece::~BishopPiece() { }

//setPosition
void BishopPiece::setPosition(int row, int column) {
    row=row;
    column=column;
}

//canMoveToLocation
bool BishopPiece::canMoveToLocation(int toRow, int toColumn) {

}

//toString
const char *BishopPiece::toString() {

}