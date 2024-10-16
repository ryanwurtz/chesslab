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
                if (==Rook) {std::cout << "Rook\n" << std::endl;}  
                else if (ty==Bishop) {std::cout << "Bishop\n" << std::endl;}
                else if (ty==Pawn) {std::cout << "Pawn\n" << std::endl;}
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


int main()
{
    //test_part1_4x4_1();
    Student::ChessBoard cboard(8,8);
    cboard.createChessPiece(Black,Pawn,2,2);
    cboard.createChessPiece(Black,Rook,3,2);
    cboard.createChessPiece(White,Pawn,3,1);
    cboard.createChessPiece(Black,Pawn,5,4);
    cboard.createChessPiece(Black,Rook,5,0);
    cboard.createChessPiece(Black,Pawn,1,1);
    cboard.createChessPiece(White,Rook,0,1);
    cboard.createChessPiece(White,Pawn,1,3);
    std::cout << cboard.displayBoard().str() << std::endl;
    isValidScan(cboard);
    return EXIT_SUCCESS;
}

