#include <iostream>

typedef std::valarray<int> ArrayInt;

template <typename T, typename T>
class Pair {
private:
    T year;
    T number;
public:
    Pair(T y = 0, T n = 0) : year(y), number(n) {}
    ~Pair() {}
};
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine {
private:
    std::string name;
    PairArray yield;
public:
    Wine(const char * l, int y, const int yr[], const int bot[]);
    Wine(const char * l = "NULL", int y = 0);
};

Wine::Wine(const char * l, int y, const int yr[], const int bot[])
{
    name = l;
    yield<>()
}