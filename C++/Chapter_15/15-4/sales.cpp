#include "sales.h"
using std::string;

Sales::bad_index::bad_index(int ix, const string &s) : bi(ix), std::logic_error(s)
{

}

Sales::Sales(int yy)
{
    year = yy;
    for (int i = 0; i < MONTHS; i++)
        gross[i] = 0;
}

Sales::Sales(int yy, const double * gr, int n)
{
    year = yy;
    int lim = (n < MONTHS) ? n : MONTHS;
    int i;
    for (i = 0; i < lim; ++i)
        gross[i] = gr[i];

    for (; i < MONTHS; ++i)
        gross[i] = 0;
}

double Sales::operator[](int i) const
{
    if (i < 0 || i >= MONTHS)
        throw bad_index(i);
    return gross[i];
}

double &Sales::operator[](int i)
{
    if (i < 0 || i >= MONTHS)
        throw bad_index(i);
    return gross[i];
}

LabeledSales::nbad_index::nbad_index(const std::string &lb, int ix, const std::string &s)
    : lbl(lb), Sales::bad_index(ix, s)
{

}

LabeledSales::LabeledSales(const std::string &lb, int yy) : label(lb), Sales(yy)
{

}

LabeledSales::LabeledSales(const std::string &lb, int yy, const double *gr, int n)
    : label(lb), Sales(yy, gr, n)
{

}

double LabeledSales::operator[](int i) const
{
    if (i < 0 || i >= MONTHS)
        throw nbad_index(Label(), i);
    return Sales::operator[](i);
}


double& LabeledSales::operator[](int i)
{
    if (i < 0 || i >= MONTHS)
        throw nbad_index(Label(), i);
    return Sales::operator[](i);  
}