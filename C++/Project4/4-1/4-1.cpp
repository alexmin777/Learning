#include <iostream>

#define SIZE	20
using namespace std;

struct personal_information {
	char first_name[SIZE];
	char last_name[SIZE];
	char grade;
	unsigned int age;
};

void display(personal_information example);

int main(void)
{
	personal_information example;

	cout << "What is your first name? ";
	cin.getline(example.first_name, SIZE);
	cout << "What is your last name? ";
	cin.getline(example.last_name, SIZE);
	cout << "What letter grade do you deserve? ";
	cin >> example.grade;
	cout << "What is your age? ";
	cin >> example.age;
	
	display(example);
	
	return 0;
}

void display(personal_information example)
{
	cout << "Name: " << example.last_name << ", " << example.first_name << endl;
	cout << "Grade: " << (char)(example.grade + 1) << endl;
	cout << "Age: " << example.age << endl;

	return;
}