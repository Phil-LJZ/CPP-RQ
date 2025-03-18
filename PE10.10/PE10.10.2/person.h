#ifndef __PERSON_H__
#define __PERSON_H__

#include <iostream>

class Person
{
private:
    static const int LIMIT = 25;
    std::string lname;
    char fname[LIMIT];
public:
    Person();
    Person(const std::string &, const char * fn = "Heyyou");
    void show() const;
    void FormalShow() const;
    ~Person();
};

#endif