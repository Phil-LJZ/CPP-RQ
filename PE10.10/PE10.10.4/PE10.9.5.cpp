#include <iostream>
#include "sales.h"

int main(void)
{
    SALES::Sales my_sales {};
    my_sales.showSales();

    const double p[SALES::QUARTERS] = {1.0, 90.9, 329.0, 1.1};

    SALES::Sales your_sales {p, 4};
    your_sales.showSales();

    return 0;
}