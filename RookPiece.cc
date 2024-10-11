#include "RookPiece.hh"

using Student::ChessBoard;

//constructor
RookPiece::RookPiece(ChessBoard &board, Color color, int row, int column) : ChessPiece(board,color,row,column) { }

//destructor
RookPiece::~RookPiece() { }

//setPosition
void RookPiece::setPosition(int row, int column) {
    row=row;
    column=column;
}

//canMoveToLocation
bool RookPiece::canMoveToLocation(int toRow, int toColumn) {

}

//toString
const char *RookPiece::toString() {

}