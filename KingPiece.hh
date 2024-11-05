#ifndef __KINGPIECE_H__
#define __KINGPIECE_H__

#include "ChessPiece.hh"

/**
 * Student implementation of a King chess piece.
 * The class is defined within the Student namespace.
 */
namespace Student
{
    class KingPiece : public ChessPiece
    {
    private:
        Type type = King;
        int row;
        int column;
    public:
        KingPiece(ChessBoard& board, Color color, int row, int column);
        virtual Type getType() {return type;}
        virtual bool canMoveToLocation(int toRow, int toColumn);
        const char* toString();
    };
}

#endif
