#include <iostream>
#include <cstring>
#include "plorg.h"

Plorg::Plorg(char * name, int value)
{
    strncpy(p_name, name, MAX);
    ci = value;
}

void Plorg::set_ci(int value)
{
    ci = value;
}

void Plorg::show_plorg(void) const
{
    using std::cout;
    using std::endl;

    cout << "The plorg name is: " << this->p_name << endl;
    cout << "The plorg ci is: " << this->ci << endl;
}