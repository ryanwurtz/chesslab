#include "ChessPiece.hh"

namespace Student
{
    class KnightPiece : public ChessPiece
    {
    private:
        Type type = Knight;
    public:
        KnightPiece(ChessBoard &board, Color color, int row, int column);
        virtual ~KnightPiece() {}
        virtual Type getType() {return type;}
        virtual bool canMoveToLocation(int toRow, int toColumn);
        virtual const char *toString();
    };
}