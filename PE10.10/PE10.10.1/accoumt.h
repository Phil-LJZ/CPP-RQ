#include <iostream>

class Accoumt
{
    private:
        enum {ArSize = 20};
        char accoumt_uname[ArSize] {};
        char accoumt_name[ArSize] {};
        double accoumt_deposit {};
    public:
        Accoumt();
        Accoumt(const char *, const char *, double);
        ~Accoumt();
        void showAccoumt();
        double deposit(double);
        double remove(double);
        Accoumt operator+(double);
        friend Accoumt operator+(double, const Accoumt &);
};