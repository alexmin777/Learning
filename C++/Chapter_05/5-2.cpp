#include <iostream>
#include <array>

const int Size = 101;

int main()
{
	using namespace std;

	array<long double, Size> num;
	num[0] = num[1] = 1;

	for (int i = 2; i < Size; i++)
		num[i] = i * num[i - 1];
	
	cout << "100! = " << num[Size - 1] << endl;

	return 0;
}