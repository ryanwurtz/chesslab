#ifndef __CHESS_H__
#define __CHESS_H__

enum Color
{
    Black,
    White,
};
enum Type
{
    Pawn,
    Rook,
    Bishop,
    King,
};

class iterator {
public:
    bool operator!=(const iterator& other);
    int& operator*();
    iterator& operator++();
};

#endif
