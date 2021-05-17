#include <iostream>
#include "move.h"

Move::Move(double a, double b)
{
	x = a;
	y = b;
}

void Move::showmove() const
{
	std::cout << "(x,y) = (" << x << ',' << y << ")\n";
}


Move Move::add(const Move& m) const
{
	double i = x + m.x;
	double j = y + m.y;
	Move xy(i, j);
	
	return xy;
}

void Move::reset(double a, double b)
{
	x = a;
	y = b;
}