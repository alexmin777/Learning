#include <iostream>
#include <cstring>
#include "golf.h"

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    golf ann;

    setgolf(ann, "Ann Birdfree", 24);
    cout << "This is version 1 out:\n";
    showgolf(ann);

    cout << "Enter empty or full name to stop loop:\n";
    while (0 == setgolf(ann))
    {   
        size_t len = strlen(ann.fullname);
        if(0 == len || Len - 1 == len)
        {
            cout <<  "Enter name is empty or full, exit!" << endl;
            break;
        }

        cout << "This is version 2 out:\n";
        showgolf(ann);
        cout << "Enter next name(empty or full to stop loop):\n";
    }

    cout << "Bye." << endl;

    return 0;
}