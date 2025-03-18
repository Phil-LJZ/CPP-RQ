#include <iostream>
#include <string.h>
#include "person.h"

Person::Person()
{
    lname = "Lname";
    strncpy(fname, "Fname", LIMIT);
}

Person::Person(const std::string & ln, const char * fn)
{
    lname = ln;
    strncpy(fname, fn, LIMIT);
}

Person::~Person()
{
    ;
}

void Person::show() const
{
    std::cout << "姓：" << lname << std::endl;
    std::cout << "名：" << fname << std::endl;
}

void Person::FormalShow() const
{
    std::cout << "姓：" << lname << std::endl;
    std::cout << "名：" << fname << std::endl;
}