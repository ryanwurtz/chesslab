#ifndef __BISHOPPIECE_H__
#define __BISHOPPIECE_H__

#include "ChessPiece.hh"

/**
 * Student implementation of a Bishop chess piece.
 * The class is defined within the Student namespace.
 */
namespace Student
{
    class BishopPiece : public ChessPiece
    {
    private:
        Type type = Bishop;
    public:
        BishopPiece(ChessBoard &board, Color color, int row, int column);
        ~BishopPiece();
        virtual void setPosition(int row, int column);
        virtual bool canMoveToLocation(int toRow, int toColumn);
        virtual const char *toString();
    };
}

#endif
