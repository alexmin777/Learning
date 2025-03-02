#ifndef PERSON_MI_H_
#define PERSON_MI_H_

#include <string>

class Person
{
private:
    std::string f_name;
    std::string l_name;

protected:
    void Data() const;
    void Get();

public:
    Person() : f_name("none"), l_name("none") {}
    Person(const std::string &first, const std::string &last) : f_name(first), l_name(last) {}
    Person(const Person & person);
    virtual ~Person() = 0;
    virtual void Set() = 0;
    virtual void show() const = 0;
};

class Gunslinger : virtual public Person
{
private:
    int nicks;

protected:
    void Data() const;
    void Get();

public:
    Gunslinger() : nicks(0), Person() {}
    Gunslinger(const std::string &f, const std::string &l, const int n) : nicks(n), Person(f, l) {}
    Gunslinger(const Person &p, const int n) : nicks(n), Person(p) {}
    void Set();
    double Draw() const;
    virtual void show() const;
};

class PokerPlayer : virtual public Person
{
protected:
    void Data() const;

public:
    PokerPlayer() : Person("no", "one") {}
    PokerPlayer(const std::string &f, const std::string &l) : Person(f, l) {}
    PokerPlayer(const Person &p) : Person(p) {}
    void Set();
    unsigned int Draw() const;
    virtual void show() const;
};

class BadDude : public Gunslinger, public PokerPlayer
{
protected:
    void Data() const;
    void Get();

public:
    BadDude() {}
    BadDude(const std::string &f, const std::string &l, int n) : Person(f, l), Gunslinger(f, l, n), PokerPlayer(f, l) {}
    BadDude(const Person &p, int n) : Person(p), Gunslinger(p, n), PokerPlayer(p) {}
    BadDude(const Gunslinger &g) : Person(g), Gunslinger(g), PokerPlayer(g) {}
    BadDude(const PokerPlayer &p, int n) : Person(p), Gunslinger(p, n), PokerPlayer(p) {}
    void Set();
    double Gdraw() const;
    int Cdraw() const;
    virtual void show() const;
};
#endif  /* PERSON_MI_H_ */