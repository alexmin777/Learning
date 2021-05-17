#include <iostream>
#include "plorg.h"

int main(void)
{
	Plorg p;
	Plorg vp("Vargui Proplorg");

	p.reprot();
	vp.reprot();
	vp.alterCI(83);
	vp.reprot();

	return 0;
}