#include <iostream>
#include <cctype>
#include "String2.h"
using std::cin;
using std::cout;

int String::num_strings = 0;

String::String(const char* s)
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	num_strings++;
}

String::String()
{
	printf("默认构造函数\n");
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}

String::String(const String& st)
{
	printf("复制构造函数\n");
	len = st.len;
	str = new char[st.len + 1];
	strcpy(str, st.str);
	num_strings++;
}

String::~String()
{
	--num_strings;
	delete[] str;
}

String& String::operator=(const String& st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[st.len + 1];
	strcpy(str, st.str);
	
	return *this;
}

String& String::operator=(const char*  s)
{
	delete[] str;
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	
	return *this;
}

char& String::operator[](int i) const
{
	return str[i];
}

void String::stringlow()
{
	for (int i = 0; i < len; i++)
		str[i] = tolower(str[i]);
}

void String::stringup()
{
	for (int i = 0; i < len; i++)
		str[i] = toupper(str[i]);
}

int String::has(char ch)
{
	int ct = 0;
	char* ps = str;
	while (*ps)
	{
		if (*ps++ == ch)
			ct++;
	}

	return ct;
}

String operator+(const String& st1, const String& st2)
{
	int len = st1.len + st2.len;
	char* temp_str = new char[len + 1];
	strcpy(temp_str, st1.str);
	strcat(temp_str, st2.str);
	String temp(temp_str);

	return temp;
}

bool operator<(const String& st1, const String& st2)
{
	return (strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String& st1, const String& st2)
{
	return st2 < st1;
}

bool operator==(const String& st1, const String& st2)
{
	return (strcmp(st1.str, st2.str) == 0);
}

ostream& operator<<(ostream& os, const String& st)
{
	os << st.str;
	return os;
}

istream& operator>>(istream& is, String& st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;

	return is;
}

int String::HowMany()
{
	return num_strings;
}