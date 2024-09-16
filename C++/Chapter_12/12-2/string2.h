#ifndef __STRING2_H__
#define __STRING2_H__

#include <iostream>
using std::ostream;
using std::istream;

class String {
private:
    char * str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;
public:
    String(const char * s);
    String();
    String(const String & s);
    ~String();
    int length() const { return len;}
    void stringlow();
    void stringup();
    int has(const char c) const;
// overloaded operator methods
    String & operator=(const String & s);
    String & operator=(const char * s);
    char & operator[](int i);
    const char & operator[](int i) const;
    String operator+(const char * s);
// overloaded operator friends
    friend bool operator<(const String &st1, const String &st2);
    friend bool operator>(const String &st1, const String &st2);
    friend bool operator==(const String &st1, const String &st2);
    friend ostream & operator<<(ostream & os, const String & st);
    friend istream & operator>>(istream & is, String & st);
    friend String operator+(const char *st1, const String &st2);
    friend String operator+(const String & st1, const String & st2);
// static functions
    static int HowMany();
};

#endif  /* __STRING_H__ */