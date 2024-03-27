#include <iostream>
#include <cstring>

const int Size = 20;

int main()
{
	using namespace std;

	char f_name[Size];
	char l_name[Size];

	cout << "Enter your first name: ";
	cin.getline(f_name, Size);
	cout << "Enter your last name: ";
	cin.getline(l_name, Size);

	char *name = new char[strlen(f_name) + strlen(l_name) + 3];
	strncpy(name, l_name, strlen(l_name));
	strncat(name, ", ", 2);
	strncat(name, f_name, strlen(f_name));

    cout << "Here's the information in a single string: ";
    cout << name << endl;
	
	delete [] name;

	return 0;

}