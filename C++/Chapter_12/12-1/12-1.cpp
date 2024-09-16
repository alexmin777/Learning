#include <iostream>
#include "cow.h"

int main()
{
    using std::cout;
    using std::endl;
    Cow black;
    Cow white("white", "eat", 200);

    white.ShowCow();
    cout << "now black is white" << endl;
    black = white;
    black.ShowCow();

    return 0;
}