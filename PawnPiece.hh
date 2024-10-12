#ifndef __PAWNPIECE_H__
#define __PAWNPIECE_H__

#include "ChessPiece.hh"

/**
 * Student implementation of a Pawn chess piece.
 * The class is defined within the Student namespace.
 */
namespace Student
{
    class PawnPiece : public ChessPiece
    {
    private:
        Type type = Pawn;
    public:
        PawnPiece(ChessBoard &board, Color color, int row, int column);
        ~PawnPiece();
        virtual bool canMoveToLocation(int toRow, int toColumn);
        virtual const char *toString();
    };
}

#endif
