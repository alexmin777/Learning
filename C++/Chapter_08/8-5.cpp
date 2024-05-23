#include <iostream>

const int Size = 5;

template <class T>
T max5(const T *ptr);

int main()
{
	using namespace std;

	int int_array[Size] = {1, 2, 3, 4, 5};
	double double_array[Size] = {1.0, 2.0, 3.0, 4.0, 5.0};

	cout << "max of int array value is " << max5(int_array) << endl;
	cout << "max of int double value is " << max5(double_array) << endl;

	return 0;
}

template <class T>
T max5(const T *ptr)
{
	T max_value = ptr[0];

	for (int i = 1; i < Size; i++)
		max_value = max_value > ptr[i] ? max_value : ptr[i];

	return max_value;
}