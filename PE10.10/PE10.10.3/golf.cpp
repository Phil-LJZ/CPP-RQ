#include <iostream>
#include <string.h>
#include "golf.h"

static void string_clear(char * name)
{
    for (int i = 0; name[i]; i++)
        name[i] = '\0';
}

static int string_input(char * target, int size)
{
    char temp;
    int index = 0;

    string_clear(target);
    temp = std::cin.get();
    if (temp == '\n' || temp == EOF)
        return 0;
    while (temp != '\n' && index < size)
    {
        target[index] = temp;
        index++;
        temp = std::cin.get();
    }
    while (temp != '\n')
        temp = std::cin.get();

    return 1;
}

static void handicap_input(int & handicap)
{
    int temp = 0;
    std::cin >> temp;
    handicap = temp;
    while (std::cin.get() != '\n');
}

Golf::Golf()
{
    Golf g {"None", 0};

    std::cout << "Please input your fullname: ";
    string_input(g.fullname, Len);
    std::cout << "Please input your handicap: ";
    handicap_input(g.handicap);

    *this = g;
}

Golf::Golf(const char * name, int hc)
{
    handicap = hc;
    strncpy(fullname, name, Len);
}

void Golf::showGolf()
{
    std::cout << "Your name is: " << fullname << std::endl;
    std::cout << "Your handicap is: " << handicap << std::endl;
}
