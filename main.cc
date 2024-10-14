#include <assert.h>
#include "Chess.h"
#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include <stdlib.h>
#include <iostream>

void test_part1_4x4_1()
{
    // Config file content:
    // 0
    // 4 4
    // w r 3 2
    // b b 1 3
    // b r 1 1
    // w r 2 3
    // ~
    // isValidScan

    // Corresponding code
    Student::ChessBoard sBoard(4, 4);
    sBoard.createChessPiece(White, Rook, 3, 2);
    sBoard.createChessPiece(Black, Bishop, 1, 3);
    sBoard.createChessPiece(Black, Rook, 1, 1);
    sBoard.createChessPiece(White, Rook, 2, 3);

    // Calls isValidMove() from every position to every
    // other position on the chess board for all pieces.

    return;
}

int main()
{
    //test_part1_4x4_1();
    Student::ChessBoard cboard(4,4);
    cboard.createChessPiece(White,Pawn,2,1);
    std::cout << cboard.getPiece(2,1) <<std::endl;
    std::cout << cboard.displayBoard().str() << std::endl;
    std::cout << cboard.isValidMove(2,1,0,1) << std::endl;
    return EXIT_SUCCESS;
}
