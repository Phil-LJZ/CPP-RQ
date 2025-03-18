#include <iostream>
#include "stack.h"

Stack::Stack()
{
    top = 0;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == Max;
}

bool Stack::push(const Item & item)
{
    if (top < Max)
    {
        items[top++] = item;
        total_payment += item.payment;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item & item)
{
    if (top > 0)
    {
        item = items[--top];
        total_payment -= item.payment;
        return true;
    }
    else
        return false;
}

void Stack::show(void) const
{
    for (int i = 0; i < top; i++)
        std::cout << items[i].fullname << std::endl << items[i].payment << std::endl << std::endl;
}