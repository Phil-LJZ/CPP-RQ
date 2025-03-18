#include <iostream>
#include "accoumt.h"

int main(void)
{
    const char * uname = "Phil Jackson";
    const char * aname = "Meal";
    double dep = 500.0;

    Accoumt my_accoumt {uname, aname, dep};
    my_accoumt.showAccoumt();
    my_accoumt.remove(15);
    my_accoumt.showAccoumt();
    my_accoumt.deposit(500);
    my_accoumt.showAccoumt();
    my_accoumt = my_accoumt + 10.9;
    my_accoumt.showAccoumt();

    return 0;
}