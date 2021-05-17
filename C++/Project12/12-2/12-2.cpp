#include <iostream>
//#include "string2.h"
#include "String2.h" // alternative name
int main()
{
	using std::cout;
	using std::cin;
	String s1(" and I am a C++ student.");
	printf("调用复制构造函数\n");
	String s2 = "Please enter your name: ";
	String s3;
	cout << s2; // overloaded << operator
	cin >> s3; // overloaded >> operator
	s2 = "My name is " + s3; // overloaded =, + operators
	cout << s2 << ".\n";
	s2 = s2 + s1;
	s2.stringup(); // converts string to uppercase
	cout << "The string\n" << s2 << "\ncontains " << s2.has('A')
		<< " 'A' characters in it.\n";
	s1 = "red"; // String(const char *),
	// then String & operator=(const String&)
	String rgb[3] = { String(s1), String("green"), String("blue") };
	cout << "Enter the name of a primary color for mixing light: ";
	String ans;
	bool success = false;
	while (cin >> ans)
	{
		ans.stringlow(); // converts string to lowercase
		for (int i = 0; i < 3; i++)
		{
			if (ans == rgb[i]) // overloaded == operator
			{
				cout << "That's right!\n";
				success = true;
				break;
			}
		}
		if (success)
			break;
		else
			cout << "Try again!\n";
	}
	cout << "Bye\n";
	//cin.get();
	return 0;
}
