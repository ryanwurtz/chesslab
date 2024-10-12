#include "PawnPiece.hh"

using Student::ChessBoard;

PawnPiece::PawnPiece(ChessBoard &board, Color color, int row, int column) : ChessPiece(board,color,row,column) { }

PawnPiece::~PawnPiece() { }

bool PawnPiece::canMoveToLocation(int toRow, int toColumn) {
    //variable definitions
    Color color = getColor();
    int row = getRow();
    int column = getColumn();
    bool empty = board.getPiece(toRow,toColumn)==nullptr;
    bool samecol = toColumn==column;
    bool adjcol = ((toColumn-column)==1) || ((toColumn-column)=-1);
    int r = (color==Black) ? 1:-1; 

    //checking straight forward move validity
    if (((toRow-row==2 && row==1) || (toRow-row==-2 && row=board.getNumcols()-2) || (toRow==row+r)) && samecol && empty) {return true;}
    //checking diagonal move validity
    if ((toRow==row+r) && adjcol && !empty) {return true;}
    
    return false;
}

const char *PawnPiece::toString() {
    if (getColor() == Black) {return "\u265F"}
    else {return "\u2659"}
}