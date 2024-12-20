#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"
#include "QueenPiece.hh"
#include "KnightPiece.hh"

using Student::ChessBoard;

std::ostringstream ChessBoard::displayBoard()
{
    std::ostringstream outputString;
    // top scale
    outputString << "  ";
    for (int i = 0; i < numCols; i++)
    {
        outputString << i;
    }
    outputString << std::endl
                 << "  ";
    // top border
    for (int i = 0; i < numCols; i++)
    {
        outputString << "-";
    }
    outputString << std::endl;

    for (int row = 0; row < numRows; row++)
    {
        outputString << row << "|";
        for (int column = 0; column < numCols; column++)
        {
            ChessPiece *piece = board.at(row).at(column);
            outputString << (piece == nullptr ? " " : piece->toString());
        }
        outputString << "|" << std::endl;
    }

    // bottom border
    outputString << "  ";
    for (int i = 0; i < numCols; i++)
    {
        outputString << "-";
    }
    outputString << std::endl
                 << std::endl;

    return outputString;
}

ChessBoard::ChessBoard(int numRow, int numCol) : numRows(numRow), numCols(numCol), board(numRow, std::vector<ChessPiece*>(numCols,nullptr)) {}

ChessBoard::~ChessBoard() {
    for (int i=0;i<numRows;i++) {
        for (int j=0;j<numCols;j++) {
            delete board[i][j];
        }
    }
}

void ChessBoard::createChessPiece(Color col, Type ty, int startRow, int startColumn) {
    //is row or column out of bounds
     if (startRow >= this->getNumRows() || startRow < 0 || startColumn >= this->getNumCols() || startColumn < 0) {return;}

    ChessBoard &boardref = *this;
    ChessPiece* piece;
    if (ty==Rook) {piece = new RookPiece(boardref,col,startRow,startColumn);}   
    else if (ty==Bishop) {piece = new BishopPiece(boardref,col,startRow,startColumn);}
    else if (ty==Pawn) {piece = new PawnPiece(boardref,col,startRow,startColumn);}
    else if (ty==King) {piece = new KingPiece(boardref,col,startRow,startColumn);}
    else if (ty==Queen) {piece = new QueenPiece(boardref,col,startRow,startColumn);}
    else if (ty==Knight) {piece = new KnightPiece(boardref,col,startRow,startColumn);}
    if (board[startRow][startColumn] != nullptr) {delete board[startRow][startColumn];}
    board[startRow][startColumn] = piece;
}

bool ChessBoard::movePiece(int fromRow, int fromColumn, int toRow, int toColumn) {
    //turn and valid move checking
    if (!this->isValidMove(fromRow,fromColumn,toRow,toColumn)) {return false;}
    //checking turn validity
    if (turn != this->getPiece(fromRow,fromColumn)->getColor()) {return false;}
    
    
    //deleting whatever is at move location
    delete this->getPiece(toRow,toColumn);
    //move piece 
    ChessPiece* temp= this->getPiece(fromRow,fromColumn);
    temp->setPosition(toRow,toColumn);
    board[toRow][toColumn] = temp;
    board[fromRow][fromColumn] = nullptr;
    //switching turn
    turn = (turn==White) ? Black : White;

    //pawn promotion
    if (board[toRow][toColumn]->getType()==Pawn && 
    ((toRow==0 && board[toRow][toColumn]->getColor()==White) || (toRow==this->getNumRows()-1 && board[toRow][toColumn]->getColor()==Black)))
    {this->createChessPiece(board[toRow][toColumn]->getColor(),Queen,toRow,toColumn);}
    
    return true;
}

bool ChessBoard::obstructed(int fromRow,int fromColumn,int toRow,int toColumn) {
    //defining row/column movers
    int r= (toRow<fromRow) ? -1: (toRow>fromRow) ? 1: 0;
    int c= (toColumn>fromColumn) ? 1: (toColumn<fromColumn) ? -1: 0;
    //defining start positions (not piece position)
    int cr= fromRow+r;
    int cc= fromColumn+c; 
    //iterating through the path
    if (cr==toRow) {
        while (cc != toColumn) {
            if (board[cr][cc]!=nullptr) {return true;}
            cr+=r;
            cc+=c;
        }
        return false;
    }
    if (cc==toColumn) {
        while (cr != toRow) {
            if (board[cr][cc]!=nullptr) {return true;}
            cr+=r;
            cc+=c;
        }
        return false;
    }
    while (cr != toRow && cc != toColumn) {
        if (board[cr][cc]!=nullptr) {return true;}
        cr+=r;
        cc+=c;
    }
    return false;
}

bool ChessBoard::isValidMove(int fromRow, int fromColumn, int toRow, int toColumn) {
    //calling helper function to determine move validity 
    if(!validChecker(fromRow, fromColumn, toRow, toColumn)) {return false;}
    //king check status)
    int rows = this->getNumRows();
    int cols = this->getNumCols();
    ChessPiece* temp= this->getPiece(fromRow,fromColumn);
    ChessPiece* temp2= this->getPiece(toRow,toColumn);
    ChessPiece* k;
    temp->setPosition(toRow,toColumn);
    board[toRow][toColumn] = temp;
    board[fromRow][fromColumn] = nullptr;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if (board[i][j]->getColor()==temp->getColor() && board[i][j]->getType()==temp->getType()) {k=board[i][j];}
        }
    }
    bool check = isPieceUnderThreat(k->getRow(),k->getColumn());
    board[fromRow][fromColumn] = temp;
    board[fromRow][fromColumn]->setPosition(fromRow,fromColumn);
    board[toRow][toColumn] = temp2;

    return !check;
}

bool ChessBoard::validChecker(int fromRow, int fromColumn, int toRow, int toColumn) {   
    //is there a piece at the start location
    if (this->getPiece(fromRow,fromColumn) == nullptr) {return false;}
    //is the new location different
    if (fromRow == toRow && fromColumn == toColumn) {return false;}
    //is row or column of desired move out of bounds
    if (toRow >= this->getNumRows() || toRow < 0 || toColumn >= this->getNumCols() || toColumn < 0) {return false;}
    //does the new location have a piece of the same color if any at all
    if (board[toRow][toColumn] != nullptr) {
        if (board[fromRow][fromColumn]->getColor()==board[toRow][toColumn]->getColor()) {return false;}
    }
    //is move valid for specific piece type
    if (!board[fromRow][fromColumn]->canMoveToLocation(toRow,toColumn)) {return false;}
    //are there any obstructions
    if (board[fromRow][fromColumn]->getType()!=Knight && this->obstructed(fromRow,fromColumn,toRow,toColumn)) {return false;}
    return true;
    
}

bool ChessBoard::isPieceUnderThreat(int row, int column) {
    //checking if piece is null and setting variables
    if (this->getPiece(row,column)==nullptr) {return false;}
    int rows = this->getNumRows();
    int cols = this->getNumCols();

    //scanning for any pieces that can capture the current piece
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if (this->validChecker(i,j,row,column)) {return true;}
        }
    }
    return false;
}

