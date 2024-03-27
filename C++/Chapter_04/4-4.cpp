#include <iostream>
#include <string>

int main()
{
	using namespace std;

	string f_name, l_name;

	cout << "Enter your first name: ";
	getline(cin, f_name);
	cout << "Enter your last name: ";
	getline(cin, l_name);
	cout << "Here's the information in a single string: "
			<< l_name + ", " + f_name << endl;
	
	return 0;
}