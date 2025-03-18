#include <iostream>
#include "sales.h"

static double minimum(const double * ar, int n)
{
    double temp {*ar};
    
    if (!n)
        return 0;
    else if (!(n - 1))
        return *ar;
    for (int i = 1; i < n; i++)
        temp = temp < ar[i] ? temp : ar[i];
    
    return temp;
}
static double maximum(const double * ar, int n)
{
    double temp {*ar};
    
    if (!n)
        return 0;
    else if (!(n - 1))
        return *ar;
    for (int i = 1; i < n; i++)
        temp = temp > ar[i] ? temp : ar[i];
    
    return temp;
}
static double average_compute(const double * ar, int n)
{
    double total {};

    if (!n)
        return 0;
    else if (!(n - 1))
        return *ar;
    for (int i = 0; i < SALES::QUARTERS; i++)
        total += ar[i];

    return total / SALES::QUARTERS;
}

static double get_sales()
{
    double temp {};

    std::cin >> temp;
    // while (std::cin.get() != '\n')
        // ;
    
    return temp;
}

SALES::Sales::Sales()
{
    std::cout << "请输入4个季度的销售额，以空格分开(输入完请回车)：";
    for (int i = 0; i < SALES::QUARTERS; i++)
        sales[i] = get_sales();
    average = average_compute(sales, SALES::QUARTERS);
    max = maximum(sales, SALES::QUARTERS);
    min = minimum(sales, SALES::QUARTERS);
}

SALES::Sales::Sales(const double * ar, int n)
{
    for (int i = 0; i < SALES::QUARTERS; i++)
        sales[i] = ar[i];

    min = minimum(ar, n);
    sales[0] = min;
    average = average_compute(ar, SALES::QUARTERS);
    max = maximum(ar, SALES::QUARTERS);
}

void SALES::Sales::showSales()
{
    std::cout << "四个季度的销售额：" << std::endl;
    for (int i = 0; i < SALES::QUARTERS; i++)
        std::cout << i+1 << ": " << sales[i] << std::endl;
    std::cout << "最大销售额：" << max << std::endl << "最小销售额：" << min << std::endl;
}