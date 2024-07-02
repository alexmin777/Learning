#include <iostream>
#include "plorg.h"

int main()
{
    Plorg all_default;
    Plorg ci_default("alex");
    Plorg manual("mjl", 24);

    all_default.show_plorg();
    ci_default.show_plorg();
    manual.show_plorg();

    all_default.set_ci(1);
    ci_default.set_ci(2);
    manual.set_ci(3);
    all_default.show_plorg();
    ci_default.show_plorg();
    manual.show_plorg();

    return 0;
}