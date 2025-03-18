#include <iostream>
#include <string>
#include "accoumt.h"

static int strncopy(char * target, const char * source, int size)
{
    for (int i = 0; i < size; i++)
    {
        target[i] = source[i];
        if (!source[i])
        {
            target[i] = '\0';
            return 0;
        }
    }
    return 0;
}

Accoumt::Accoumt()
{
    std::cout << "默认构造函数已调用. . . " << std::endl;
}

Accoumt::Accoumt(const char * user_name = "no name", const char * acc_name = "no_name", double dep = 0.0)
{
    strncopy(accoumt_uname, user_name, ArSize);
    strncopy(accoumt_name, acc_name, ArSize);
    accoumt_deposit = dep;
    std::cout << "非默认构造函数已调用. . ." << std::endl;
}

Accoumt::~Accoumt()
{
    std::cout << "账户已消除. . .";
}

double Accoumt::deposit(double money)
{
    accoumt_deposit += money;
    return money;
}

double Accoumt::remove(double money)
{
    accoumt_deposit -= money;
    return money;
}

void Accoumt::showAccoumt()
{   
    std::cout << "用户名字：";
    std::cout << accoumt_uname;
    std::cout << std::endl;

    std::cout << "账户名字：";
    std::cout << accoumt_name;
    std::cout << std::endl;

    std::cout << "账户余额：";
    std::cout << accoumt_deposit;
    std::cout << std::endl;
}

Accoumt Accoumt::operator+(double n)
{
    this->accoumt_deposit += n;
    return *this;
}

Accoumt operator+(double n, Accoumt a)
{
    return a + n;
}