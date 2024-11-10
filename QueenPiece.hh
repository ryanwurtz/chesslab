#include "ChessPiece.hh"

namespace Student
{
    class QueenPiece : public ChessPiece
    {
    private:
        Type type = Queen;
    public:
        QueenPiece(ChessBoard &board, Color color, int row, int column);
        virtual ~QueenPiece() {}
        virtual Type getType() {return type;}
        virtual bool canMoveToLocation(int toRow, int toColumn);
        virtual const char *toString();
    };
}