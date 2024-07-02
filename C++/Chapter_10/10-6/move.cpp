#include "move.h"
#include <iostream>

Move::Move(double a, double b)
{
    x = a;
    y = b;
}

void Move::showmove() const
{
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
}

Move Move::add(const Move & m) const
{
    Move tmp(x + m.x, y + m.y);

    return tmp;
}

void Move::reset(double a, double b)
{
    x = a;
    y = b;
}