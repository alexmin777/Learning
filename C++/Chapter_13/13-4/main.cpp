#include "port.h"
#include "vintageport.h"

int main()
{
    Port wine1("Gallo", "tawny", 20);
    VintagePort wine2("Lafei", 10, "strong wine", 1876);
    VintagePort wine3("Merlot", 50, "middle wine", 1976);

    cout << "Here is the Port object:\n";
    wine1.Show();
    cout << wine1 << endl;

    cout << "\nHere are the VintagePort objects:\n";
    wine2.Show();
    cout << wine2 << endl;
    wine3.Show();
    cout << wine3 << endl;

    cout << "\nGallo add 20 bottles:\n";
    wine1 += 20;
    wine1.Show();

    cout << "\nLafei add 10 bottles:\n";
    wine2 += 10;
    wine2.Show();

    cout << "\nMerlot minus 10 bottles:\n";
    wine3 -= 10;
    wine3.Show();

    VintagePort wine4(wine2);
    cout << "\nResult of VintagePort copy:\n";
    wine4.Show();

    VintagePort wine5;
    wine5 = wine3;
    cout << "\nResult of VintagePort assignment:\n";
    wine5.Show();

    return 0;
}
