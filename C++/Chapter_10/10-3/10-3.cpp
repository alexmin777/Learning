#include "golf.h"
#include <iostream>

int main()
{
    Golf ann_default;
    Golf ann("Ann Birdfree", 24);

    ann_default.showgolf();
    ann.showgolf();

    ann_default.set_handicap(23);
    ann.set_handicap(25);

    ann_default.showgolf();
    ann.showgolf();

    return 0;
}