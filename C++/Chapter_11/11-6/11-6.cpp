#include <iostream>
#include "stonewt.h"

int main()
{
    using std::cout;

    int i;
    int count = 0;
    Stonewt stones_min, stones_max, stones_cmp;
    Stonewt stones[6] = {Stonewt(10), Stonewt(11), Stonewt(12)};

    for (i = 3; i < 6; i++) {
        stones[i] = Stonewt(i + 10);
    }

    stones_min = stones[0];
    stones_max = stones[0];
    stones_cmp = Stonewt(11);
    for (i = 1; i < 6; i++) {
        stones_min = stones[i] < stones_min ? stones[i] : stones_min;
        stones_max = stones[i] > stones_min ? stones[i] : stones_max;
        if (stones[i] >= stones_cmp)
            count++;
    }

    cout << "The minimum pounds are: " << stones_min;
    cout << "The maximum pounds are: " << stones_max;
    cout << "There are " << count << " elements more than 11 stones.\n";

    return 0;
}