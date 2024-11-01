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

void isValidScan(Student::ChessBoard &cboard) 
{
    for(int i = 0; i < cboard.getNumRows(); i++)
    {
        for(int j = 0; j < cboard.getNumCols(); j++)
        {
            if(cboard.getPiece(i,j) != nullptr)
            {   
                for(int k = 0; k < cboard.getNumRows(); k++)
                {
                    for(int l = 0; l < cboard.getNumCols(); l++)
                    {
                        if(cboard.isValidMove(i,j,k,l))
                        {
                            std::cout << "Can move from (" << i << ", " << j << ") to (" << k << ", " << l << ")" << std::endl;
                        }
                    }
                }
            }
        }
    }
}

void underthreatscan(Student::ChessBoard &cboard) {
    for(int i = 0; i < cboard.getNumRows(); i++) {
        for(int j = 0; j < cboard.getNumCols(); j++) {
            if (cboard.isPieceUnderThreat(i,j)) {std::cout << "Piece is under threat: " << i <<","<< j << std::endl;}
        }
    }
}

int main()
{
    //test_part1_4x4_1();
    Student::ChessBoard cboard(4,4);
    cboard.createChessPiece(White,Rook,3,2);
    cboard.createChessPiece(Black,Bishop,1,3);
    cboard.createChessPiece(Black,Rook,1,1);
    cboard.createChessPiece(White,Rook,2,3);
    isValidScan(cboard);
    underthreatscan(cboard);
    std::cout << cboard.displayBoard().str() << std::endl;
    std::cout << cboard.movePiece(3,2,3,1) << std::endl;
    std::cout << cboard.getPiece(3,1)->getRow() << "," << cboard.getPiece(3,1)->getColumn() << std::endl;
    std::cout << cboard.getPiece(3,2) << std::endl;
    std::cout << cboard.displayBoard().str() << std::endl;
    return EXIT_SUCCESS;
}

