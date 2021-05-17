#include <iostream>
#include <cstring>

#define SIZE 20
struct name {
	char first_name[SIZE];
	char last_name[SIZE];
	char complete_name[2 * SIZE + 2];
};

int main(void)
{
	using namespace std;
	name example;

	cout << "Enter your first name: ";
	cin.getline(example.first_name, SIZE);
	cout << "Enter your last name: ";
	cin.getline(example.last_name, SIZE);

	strncpy(example.complete_name, example.last_name, SIZE);
	strcat(example.complete_name, ", ");
	strncat(example.complete_name, example.first_name, SIZE);

	strncat(example.complete_name, example.first_name, SIZE);
	cout << "Here's the information in a single string: " << example.complete_name << endl;
	
	return 0;
}