#include <iostream>
#include <fstream>
#include <ctime>
#include "vector.h"

int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result;
    unsigned long steps = 0;
    double target;
    double dstep;
    ofstream fout;

    fout.open("temp.txt");
    cout << "Enter target distance (q to quit): ";
    while (cin >> target) {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
        fout << "Target Distance: " << target;
        fout << " Step Size: " << dstep << endl;

        fout << "0: " << result << endl;
        while (result.mag_val() < target) {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
            fout << steps << ": " << result << endl;
        }
        fout << "After " << steps << " steps, the subkect "
            << "has the following location:\n";
        fout << result << endl;
        result.polar_mode();
        fout << "or \n" << result << endl;
        fout << "Average out ward distance per step = "
            << result.mag_val() / steps << endl;

        cout << "After " << steps << " steps, the subkect "
            << "has the following location:\n";
        cout << result << endl;
        result.polar_mode();
        cout << "or \n" << result << endl;
        cout << "Average out ward distance per step = "
            << result.mag_val() / steps << endl;
        steps = 0;
        result.reset(0, 0);
        cout << "Enter target distance (q to quit): ";
    }

    cin.clear();
    while (cin.get() != '\n');
    fout.close();
    cout << "Bye!\n";

    return 0;
}