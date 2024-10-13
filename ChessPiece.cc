#include "ChessPiece.hh"

using Student::ChessPiece;

ChessPiece::ChessPiece(ChessBoard &board, Color color, int row, int column) : color(color), row(row), column(column), board(board) {}

Color ChessPiece::getColor() {return color;}

int ChessPiece::getRow() {return row;}

int ChessPiece::getColumn() {return column;}

void ChessPiece::setPosition(int row,int column) {
    row=row; 
    column=column;
}






