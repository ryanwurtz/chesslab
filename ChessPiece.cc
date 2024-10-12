#include "ChessPiece.hh"

using Student::ChessBoard;

ChessPiece::ChessPiece(ChessBoard &board, Color color, int row, int column) : board(board), color(color), row(row), column(column) { }

ChessPiece::~ChessPiece() { }

Color ChessPiece::getColor() {return color;}

Type ChessPiece::getType() {
    if (PawnPiece *p = dynamic_cast<PawnPiece*>(this)!=nullptr) {return Pawn;} 
    else if (RookPiece *r = dynamic_cast<RookPiece*>(this)!=nullptr) {return Rook;} 
    return Bishop;
 }

int ChessPiece::getRow() {return row;}

int ChessPiece::getColumn() {return column;}

void ChessPiece::setPosition(int row,int column) {
    row=row; 
    column=column;
}






