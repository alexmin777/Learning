#include <iostream>
#include "move.h"

int main(void)
{
	Move a(10.0, 20.0);
	Move b(2.5, 3.5);
	Move c;
	a.showmove();
	b.showmove();
	c.showmove();
	a.add(b).showmove();
	a.reset();
	a.showmove();

	return 0;
}