#include <iostream>
#include "worker.h"

using std::cout;
using std::cin;
using std::endl;

void Worker::Set()
{
    cout << "Enter worker's name: ";
    getline(cin, fullname);
    cout << "Enter worker's ID: ";
    cin >> id;
    while (cin.get() != '\n')
        continue;
}

void Worker::Show() const
{
    cout << "Worker name: " << fullname << endl;
    cout << "Worker ID: " << id << endl;
}