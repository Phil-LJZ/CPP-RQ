#include <iostream>
#include "person.h"

int main(void)
{
    Person one;
    Person two("Smthecraft");
    Person three("Dimwiddy", "Sam");
    
    one.show();
    std::cout << std::endl;
    one.FormalShow();
    two.show();
    std::cout << std::endl;
    two.FormalShow();
    three.show();
    std::cout << std::endl;
    three.FormalShow();

    return 0;
}