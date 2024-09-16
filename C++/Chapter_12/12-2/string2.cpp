#include <iostream>
#include <cctype>
#include "string2.h"

int String::num_strings = 0;

int String::HowMany()
{
    return num_strings;
}

String::String(const char * s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
}

String::String()
{
    len = 0;
    str = new char[len + 1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String & s)
{
    len = s.len;
    str = new char[len + 1];
    std::strcpy(str, s.str);
    num_strings++;
}

String::~String()
{
    num_strings--;
    delete[] str;
}

void String::stringlow()
{
    for (int i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }
}

void String::stringup()
{
    for (int i = 0; i < len; i++) {
        str[i] = toupper(str[i]);
    }
}

int String::has(const char c) const
{
    int count = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] == c)
            count++;
    }

    return count;
}

String & String::operator=(const String & s)
{
    if (this == &s)
        return *this;

    delete [] str;

    len = s.len;
    str = new char[len + 1];
    std::strcpy(str, s.str);
    num_strings++;

    return *this;
}

String & String::operator=(const char * s)
{
    delete [] str;

    len = strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;

    return *this;
}

char & String::operator[](int i)
{
    return str[i];
}

const char & String::operator[](int i) const
{
    return str[i];
}

String String::operator+(const char * s)
{
    int length = len + strlen(s);
    char *ptemp = new char[length + 1];
    std::strcpy(ptemp, str);
    std::strcat(ptemp, s);
    String new_str(ptemp);

    delete [] ptemp;

    return new_str;
}

bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
    return st2 < st1;
}

bool operator==(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

ostream & operator<<(ostream & os, const String & st)
{
    os << st.str;

    return os;
}

istream & operator>>(istream & is, String & st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    
    while (is && is.get() != '\n')
        continue;
    
    return is;
}

String operator+(const char *st1, const String &st2)
{
    int length = st2.len + strlen(st1);
    char *ptemp = new char[length + 1];
    std::strcpy(ptemp, st1);
    std::strcat(ptemp, st2.str);
    String new_str(ptemp);

    delete[] ptemp;

    return new_str;
}

String operator+(const String & st1, const String & st2)
{
    int length = st1.len + st2.len;
    char *ptemp = new char[length + 1];
    std::strcpy(ptemp, st1.str);
    std::strcat(ptemp, st2.str);
    String new_str(ptemp);

    delete[] ptemp;

    return new_str;
}