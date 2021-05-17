#include <iostream>
#include <cstring>

template <class T>
T maxn(T ar[], int n)
{
	T temp = ar[0];

	for (int i = 1; i < n; i++)
	{
		if (temp < ar[i])
			temp = ar[i];
	}

	return temp;
}

template<> const char* maxn(const char* ar[], int n);

int main(void)
{
	using namespace std;
	double ard[4] = { -3.4, 58.1, -76.4, 34.4 };
	int ari[6] = { 2, 3, 81, 1, 9, 22 };
	const char* strs[5] = { "Here", "is", "a", "test", "sequence" };
	double md;
	int mi;
	const char* longest;

	md = maxn(ard, 4);
	mi = maxn(ari, 6);
	longest = maxn(strs, 5);
	cout << "md = " << md << endl;
	cout << "mi = " << mi << endl;
	cout << "The longest string: " << longest << endl;

	return 0;
}

template<> const char* maxn(const char* ar[], int n)
{
	int temp = strlen(ar[0]);
	const char* str = ar[0];

	for (int i = 1; i < n; i++)
	{
		if (temp < strlen(ar[i]))
		{
			temp = strlen(ar[i]);
			str = ar[i];
		}
	}

	return str;
}