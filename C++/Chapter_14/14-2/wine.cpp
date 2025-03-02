#include "wine.h"

// template <typename T1, typename T2>
// void Pair<T1, T2>::set(T1 & y, T2 & n)
// {
//     year = y;
//     number = n;
// }

template <typename T1, typename T2>
void Pair<T1, T2>::show(int y) const
{
    using std::cout;
    using std::endl;

    cout << '\t' << year[y] << '\t' << number[y] << endl;
}

template <typename T1, typename T2>
auto Pair<T1, T2>::total() const -> decltype(number.sum())
{
    return number.sum();
}

template <typename T1, typename T2>
Pair<T1, T2> & Pair<T1, T2>::operator=(const Pair<T1, T2> & a)
{
    if (this == &a)
        return *this;
    
    year = a.year;
    number = a.number;

    return *this;
}

void Wine::GetBottles()
{
    using std::cout;
    using std::endl;
    using std::cin;

    ArrayInt year(years);
    ArrayInt num(years);
 
    cout << "Enter " << (const std::string &)(*this)
         << "for " << years << " year(s):" << endl;
    for (int i = 0; i < years; i++)
    {
        cout << "Enter year: ";
        cin >> year[i];
        cout << "Enter bottles for that year: ";
        cin >> num[i];
    }
    //PairArray::set(year, num);
    PairArray::operator=(PairArray(year, num));
}

void Wine::show() const
{
    using std::cout;
    using std::endl;

    cout << "Wine: " << (const std::string)(*this) << endl;
    cout << "\tYear\tBottles" << endl;
    for (int i = 0; i < years; i++)
        PairArray::show(i);
}

std::string & Wine::Label()
{
    return (std::string &)*this;
}

int Wine::sum() const
{
    return PairArray::total();
}