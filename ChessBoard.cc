#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"

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

//constructor
ChessBoard::ChessBoard(int numRow, int numCol) : numRows(numRow), numCols(numCol), board(numRow, std::vector<ChessPiece*>(numCols,nullptr)) { }

//createChessPiece
void ChessBoard::createChessPiece(Color col, Type ty, int startRow, int startColumn) {
    ChessPiece* piece;
    if (ty==Rook) {piece = new RookPiece(col,startRow,startColumn);}   
    else if (ty==Bishop) {piece = new BishopPiece(col,startRow,startColumn);}
    else if (ty==Pawn) {piece = new PawnPiece(col,startRow,startColumn);}
    //add king in later
    if (board[startRow][startColumn] != NULL) {delete board[startRow][startColumn];}
    board[startRow][startColumn] = piece;
}

//movePiece
bool ChessBoard::movePiece(int fromRow, int fromColumn, int toRow, int toColumn) {
    //dummy part 1
    return true;
}

//isValidMove
bool ChessBoard::isValidMove(int fromRow, int fromColumn, int toRow, int toColumn) {

}

//isPieceUnderThreat
bool ChessBoard::isPieceUnderThreat(int row, int column) {
    //dummy part 1
    return true;
}

