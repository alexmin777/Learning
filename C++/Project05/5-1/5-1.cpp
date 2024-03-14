#include <iostream>

int main(void)
{
	using namespace std;

	cout << "Enter the start number: ";
	int start_num;
	cin >> start_num;
	cout << "Enter the end number: ";
	int end_num;
	cin >> end_num;

	int total = 0;
	for (; start_num <= end_num; start_num++)
		total += start_num;

	cout << "Now total is " << total << endl;

	return 0;
}