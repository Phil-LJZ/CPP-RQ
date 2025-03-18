#include <iostream>
#include "golf.h"

int main(void)
{
    Golf g {};
    g.showGolf();

    Golf g2 {"Phil", 90};
    g2.showGolf();

    return 0;
}