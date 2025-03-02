#include "wine.h"

template <typename T1, typename T2>
void Pair<T1, T2>::set(const T1 &y, const T2 &n)
{
    year = y;
    number = n;
}

template <typename T1, typename T2>
void Pair<T1, T2>::show(int y) const
{
    using std::cout;
    using std::endl;

    for (int i = 0; i < y; i++)
        cout << "\t" << year[i] << "\t" << number[i] << endl;
}

template <typename T1, typename T2>
int Pair<T1, T2>::sum() const
{
    return number.sum();
}

//Wine::Wine(const char * l, int y, const int yr[], const int bot[]) : yield(ArrayInt(yr, y), ArrayInt(bot, y))
Wine::Wine(const char * l, int y, const int yr[], const int bot[])
{
    name = l;
    vintage = y;
    yield = PairArray(ArrayInt(yr, y), ArrayInt(bot, y));
    //yield.set(ArrayInt(yr, y), ArrayInt(bot, y));
}

Wine::Wine(const char * l, int y)
{
    name = l;
    vintage = y;
    yield = PairArray(ArrayInt(y), ArrayInt(y));
    //yield.set(ArrayInt(y), ArrayInt(y));
}

void Wine::GetBottles()
{
    using std::cin;
    using std::cout;
    using std::endl;

    int year[vintage];
    int num[vintage];

    cout << "Enter " << name << " data for " << vintage << " year(s):" << endl;
    for (int i = 0; i < vintage; i++)
    {
        cout << "Enter year: ";
        cin >> year[i];
        cout << "Enter bottles for that year: ";
        cin >> num[i];
    }
    yield.set(ArrayInt(year, vintage), ArrayInt(num, vintage));

    return;
}

void Wine::show(void) const
{
    using std::cout;
    using std::endl;

    cout << "Wine: " << name << endl;
    cout << "\tYear\tBottles" << endl;
    yield.show(vintage);
}

std::string Wine::Label()
{
    return name;
}

int Wine::sum() const
{
    return yield.sum();
}