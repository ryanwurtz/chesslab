#include "ChessPiece.hh"

using Student::ChessBoard;

//constructor
ChessPiece::ChessPiece(ChessBoard &board, Color color, int row, int column) : board(board), color(color), row(row), column(column) { }

//destructor
ChessPiece::~ChessPiece() { }

//getColor
Color ChessPiece::getColor() {return color;}

//getType
Type ChessPiece::getType() { }

//getRow
int ChessPiece::getRow() {return row;}

//getColumn
int ChessPiece::getColumn() {return column;}

//setPosition
void ChessPiece::setPosition(int row,int column) {
    row=row; 
    column=column;
}






