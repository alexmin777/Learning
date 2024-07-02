#ifndef __SALES_H__
#define __SALES_H__

namespace SALES
{
    class Sales
    {
    private:
        static const int QUARTERS = 4;
        double sales[QUARTERS];
        double average;
        double max;
        double min;

    public:
        Sales(const double ar[], int n);
        Sales();
        void showSales(void) const;
    };
}

#endif  //__SALES_H__