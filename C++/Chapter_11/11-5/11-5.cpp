#include <iostream>
#include "stonewt.h"

int main()
{
    using std::cout;
    using std::endl;
    Stonewt incognito(275, Stonewt::FORMATE_POUND_FRACTIONAL);
    Stonewt wolfe(285.7, Stonewt::FORMATE_STONE);
    Stonewt taft(21, 8, Stonewt::FORMATE_POUND_INTEGER);

    cout << "Here are the tsets:" << endl;
    cout << "The celebrity weighed ";
    cout << incognito;
    cout << "The detective weighed ";
    cout << wolfe;
    cout << "The President weighed ";
    cout << taft;
    cout << "incognito + wolfe = " << incognito + wolfe;
    cout << "wolfe - incognito = " << wolfe - incognito;
    cout << "taft * 10.0 = " << taft * 10.0;
    cout << "10.0 * taft = " << 10.0 * taft;

    return 0;
}
