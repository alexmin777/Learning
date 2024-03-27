#include <string>
#include <iostream>

using namespace std;

struct student_info {
	string f_name;
	string l_name;
	char record;
	int age;
};

int main()
{
	student_info student;
	
	cout << "What is your first name?";
	getline(cin, student.f_name);
	cout << "What is your last name?";
	getline(cin, student.l_name);
	cout << "What letter grade do you deserve?";
	cin >> student.record;
	cout << "What is your age?";
	cin >> student.age;

	cout << "Name: " << student.l_name + ", "+ student.f_name << endl;
	cout << "Grade: " << (char)(student.record + 1) << endl;
	cout << "Age: " << student.age << endl;

	return 0;
}
