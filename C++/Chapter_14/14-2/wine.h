#ifndef WINE_H_
#define WINE_H_

#include <iostream>
#include <valarray>

typedef std::valarray<int> ArrayInt;

template <typename T1, typename T2>
class Pair
{
private:
    T1 year;
    T2 number;
public:
    Pair() {}
    Pair(T1 y, T2 n) : year(y), number(n) {}
    ~Pair() {}
    //void set(T1 & y, T2 & n);
    void show(int y) const;
    auto total() const -> decltype(number.sum());
    Pair<T1, T2> & operator=(const Pair<T1, T2> & a);
};
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine : private std::string, private PairArray
{
private:
    int years;
public:
    Wine(std::string name = "NULL", int yrs = 0) : std::string(name), years(yrs) {}
    Wine(std::string name, int yrs, int * y, int * n) : std::string(name), years(yrs), PairArray(ArrayInt(y, yrs), ArrayInt(n, yrs)){}
    ~Wine() {}
    void GetBottles();
    void show() const;
    std::string & Label();
    int sum() const;
};

#endif /* WINE_H_ */