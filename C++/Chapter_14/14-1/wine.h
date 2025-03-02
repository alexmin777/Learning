#ifndef WINE_H
#define WINE_H

#include <iostream>
#include <valarray>

typedef std::valarray<int> ArrayInt;

template <typename T1, typename T2>
class Pair {
private:
    T1 year;
    T2 number;
public:
    Pair() {}
    Pair(const T1 &y, const T2 &n) : year(y), number(n) {}
    ~Pair() {}
    void set(const T1 &y, const T2 &n);
    void show(int y) const;
    int sum() const;
};
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine {
private:
    std::string name;
    PairArray yield;
    int vintage;
public:
    Wine(const char * l, int y, const int yr[], const int bot[]);
    Wine(const char * l = "NULL", int y = 0);
    void GetBottles();   //solicit input for year, bottle count
    void show(void) const;  //display object contents
    std::string Label();
    int sum() const;
};

#endif /* WINE_H */