#ifndef __SALES_H__
#define __SALES_H__

namespace SALES
{
    const int QUARTERS = 4;
    class Sales
    {
        private:
            double sales[SALES::QUARTERS];
            double average;
            double max;
            double min;
        public:
            Sales(const double *, int);
            Sales();
            void showSales();
    };
};

#endif