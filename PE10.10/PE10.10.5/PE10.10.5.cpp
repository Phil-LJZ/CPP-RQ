#include <iostream>
#include "stack.h"

void show_customer(customer &);

int main(void)
{
    Stack s {};

    customer c1 {"Phil", 90};   s.push(c1);
    customer c2 {"Jack", 18};   s.push(c2);
    customer c3 {"join", 89};   s.push(c3);
    customer c {};
    s.show();

    s.pop(c);
    std::cout << "已弹出:" << std::endl;
    show_customer(c);
    std::cout << "剩余" << std::endl;
    s.show();

    s.pop(c);
    std::cout << "已弹出:" << std::endl;
    show_customer(c);
    std::cout << "剩余" << std::endl;
    s.show();

    s.pop(c);
    std::cout << "已弹出:" << std::endl;
    show_customer(c);
    std::cout << "剩余" << std::endl;
    s.show();

    return 0;
}

void show_customer(customer & c)
{
    std::cout << c.fullname << std::endl << c.payment << std::endl;
}