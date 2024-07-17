#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vector.h"

int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    int count, i;
    unsigned long max_steps, min_steps;
    double average_dstep, total_dstep;
    bool first_time;

    cout << "Enter test times (q to quit): ";
    while (cin >> count) {
        cout << "Enter target distance: ";
        if (!(cin >> target))
            continue;

        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
        
        first_time = true;
        max_steps = min_steps = 0;
        total_dstep = average_dstep = 0.0;

        for (i = 0; i < count; i++) {
            while (result.magval() < target){
                direction = rand() % 360;
                step.reset(dstep, direction, Vector::POL);
                result = result + step;
                steps++;
            }

            if (first_time) {
                max_steps = min_steps = steps;
                first_time = false;
            } else {
                max_steps = steps > max_steps ? steps : max_steps;
                min_steps = steps < min_steps ? steps : min_steps;
            }

            total_dstep += (result.magval() / steps);

            cout << "After " << steps << " steps, the subject ";
            cout << "has the following location:\n";
            cout << result << endl;
            result.polar_mode();
            cout << " or\n";
            cout << result << endl;
            cout << "Average outward distance per step = ";
            cout << result.magval() / steps << endl;
            steps = 0;
            result.reset(0.0, 0.0);
            cout << endl << endl;

        }
        average_dstep = total_dstep / count;
        cout << "Max steps = " << max_steps;
        cout << " Min steps = " << min_steps;
        cout << " average steps = " << average_dstep << endl;

        cout << "Enter test times (q to quit): ";
    }

    cout << "Bye!\n";

    return 0;
}
