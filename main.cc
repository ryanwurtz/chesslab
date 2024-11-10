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
                std::cout << std::endl;
            }
        }
    }
    
}

void underThreatScan(Student::ChessBoard &cboard) {
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
    cboard.createChessPiece(White,Queen,3,1);
    cboard.createChessPiece(Black,Knight,3,2);
    // Starting sequence
    // isValidScan(cboard);
    // underThreatScan(cboard);

    // cboard.movePiece(3, 0, 2, 0);
    // isValidScan(cboard);

    // cboard.movePiece(1, 3, 0, 2);
    // isValidScan(cboard);

    // cboard.movePiece(2, 3, 1, 3);
    // isValidScan(cboard);

    // cboard.movePiece(1, 1, 0, 1);
    // isValidScan(cboard);
    std::cout << cboard.displayBoard().str() << std::endl;
    // cboard.movePiece(1, 2, 0, 3);
    // isValidScan(cboard);

    // underThreatScan(cboard);

    // cboard.movePiece(2, 0, 3, 0);
    // isValidScan(cboard);

    // cboard.movePiece(0, 1, 2, 1);
    // isValidScan(cboard);

    // cboard.movePiece(3, 2, 0, 2);
    // isValidScan(cboard);

    // cboard.movePiece(2, 1, 0, 1);
    // isValidScan(cboard);

    // cboard.movePiece(0, 1, 3, 2);
    // isValidScan(cboard);

    // underThreatScan(cboard);

    // cboard.movePiece(1, 3, 1, 0);
    // isValidScan(cboard);

    // cboard.movePiece(0, 0, 1, 0);
    // isValidScan(cboard);

    // cboard.movePiece(0, 2, 3, 2);
    // isValidScan(cboard);

    // cboard.movePiece(1, 0, 1, 1);
    // isValidScan(cboard);

    // cboard.movePiece(2, 0, 3, 3);
    // isValidScan(cboard);

    // underThreatScan(cboard);

    // cboard.movePiece(3, 2, 3, 1);
    // isValidScan(cboard);

    // cboard.movePiece(1, 1, 0, 2);
    // isValidScan(cboard);

    // cboard.movePiece(3, 1, 3, 2);
    // isValidScan(cboard);

    // cboard.movePiece(0, 2, 0, 3);
    // isValidScan(cboard);

    // cboard.movePiece(1, 3, 2, 3);
    // isValidScan(cboard);

    // underThreatScan(cboard);

    // cboard.movePiece(3, 2, 2, 2);
    // isValidScan(cboard);

    // cboard.movePiece(0, 3, 1, 3);
    // isValidScan(cboard);

    // cboard.movePiece(3, 0, 2, 0);
    // isValidScan(cboard);

    // cboard.movePiece(0, 1, 0, 2);
    // isValidScan(cboard);

    // cboard.movePiece(2, 3, 1, 0);
    // isValidScan(cboard);

    // underThreatScan(cboard);

    // cboard.movePiece(2, 0, 3, 1);
    // isValidScan(cboard);

    // cboard.movePiece(1, 3, 0, 3);
    // isValidScan(cboard);

    // cboard.movePiece(2, 2, 0, 2);
    // isValidScan(cboard);

    // cboard.movePiece(0, 3, 1, 3);
    // isValidScan(cboard);

    // cboard.movePiece(3, 1, 1, 2);
    // isValidScan(cboard);

    // underThreatScan(cboard);

    // cboard.movePiece(0, 2, 0, 1);
    // isValidScan(cboard);

    // cboard.movePiece(1, 3, 1, 2);
    // isValidScan(cboard);

    // cboard.movePiece(0, 1, 2, 1);
    // isValidScan(cboard);

    // cboard.movePiece(1, 2, 0, 2);
    // isValidScan(cboard);

    // cboard.movePiece(2, 0, 0, 0);
    // isValidScan(cboard);

    // underThreatScan(cboard);

    // cboard.movePiece(3, 1, 2, 0);
    // isValidScan(cboard);

    // cboard.movePiece(0, 2, 1, 2);
    // isValidScan(cboard);

    // cboard.movePiece(2, 0, 3, 0);
    // isValidScan(cboard);

    // cboard.movePiece(1, 2, 0, 2);
    // isValidScan(cboard);

    // cboard.movePiece(0, 1, 1, 1);
    // isValidScan(cboard);

    // underThreatScan(cboard);

    // cboard.movePiece(2, 1, 2, 3);
    // isValidScan(cboard);

    // cboard.movePiece(0, 2, 0, 1);
    // isValidScan(cboard);

    // cboard.movePiece(2, 3, 2, 0);
    // isValidScan(cboard);

    // cboard.movePiece(0, 1, 1, 2);
    // isValidScan(cboard);

    // cboard.movePiece(1, 2, 0, 0);
    // isValidScan(cboard);

    // underThreatScan(cboard);

    // cboard.movePiece(2, 0, 2, 2);
    // isValidScan(cboard);

    // cboard.movePiece(1, 2, 1, 3);
    // isValidScan(cboard);

    // cboard.movePiece(2, 2, 2, 0);
    // isValidScan(cboard);

    // cboard.movePiece(1, 3, 0, 2);
    // isValidScan(cboard);

    // cboard.movePiece(2, 2, 2, 2);
    // isValidScan(cboard);

    // underThreatScan(cboard);

    // cboard.movePiece(2, 0, 2, 1);
    // isValidScan(cboard);

    // cboard.movePiece(0, 2, 0, 3);
    // isValidScan(cboard);

    // cboard.movePiece(3, 0, 2, 0);
    // isValidScan(cboard);

    // cboard.movePiece(0, 3, 0, 2);
    // isValidScan(cboard);

    // cboard.movePiece(3, 0, 2, 2);
    // isValidScan(cboard);

    // underThreatScan(cboard);

    // cboard.movePiece(2, 1, 1, 1);
    // isValidScan(cboard);

    // cboard.movePiece(0, 2, 0, 3);
    // isValidScan(cboard);

    // cboard.movePiece(1, 1, 0, 1);
    // isValidScan(cboard);

    // cboard.movePiece(0, 3, 1, 3);
    // isValidScan(cboard);

    // cboard.movePiece(1, 0, 3, 3);
    // isValidScan(cboard);

    // underThreatScan(cboard);

    // cboard.movePiece(0, 1, 2, 1);
    // isValidScan(cboard);

    // cboard.movePiece(1, 3, 1, 2);
    // isValidScan(cboard);

    // cboard.movePiece(2, 1, 1, 1);
    // isValidScan(cboard);

    // cboard.movePiece(1, 2, 0, 2);
    // isValidScan(cboard);

    return EXIT_SUCCESS;
}

