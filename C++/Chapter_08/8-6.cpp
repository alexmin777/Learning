#include <iostream>
#include <ctype.h>

using namespace std;

template <class T>
T maxn(T *pt, const int n);

//注意，显示具体化首先要定义一个模版函数，然后才能使用这个模版函数的显示具体化
template <>
const char * maxn(const char *pt[], int n);


int main()
{
	int test1[6] = {1, 2, 3, 4, 5, 6};
	double test2[4] = {1.1, 2.2, 3.3, 4.4};
	const char * test3[5] = {
		"alex",
		"alex_min",
		"alex.min",
		"minjl",
		"mjl"
	};

	cout << "Testing int array max:" << maxn(test1, 6) << endl;
	cout << "Testing double array max:" << maxn(test2, 4) << endl;
	cout << "Testing string array max length addr:" << maxn(test3, 5) << endl;
}

template <class T>
T maxn(T *pt, const int n)
{
	T max_value = pt[0];

	for (int i = 1; i < n; i++)
		max_value = max(max_value, pt[i]);
	
	return max_value;
}

template <>
const char * maxn(const char *pt[], int n)
{
	const char *max_str = pt[0];

	for (int i = 1; i < n; i++)
	{
		if (strlen(max_str) < strlen(pt[i]))
			max_str = pt[i];
	}

	return max_str;
}