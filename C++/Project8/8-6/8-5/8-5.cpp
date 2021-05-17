#include <iostream>
#define LIMIT 5

template <class T>
T max5(T ar[]);

int main(void)
{
	using namespace std;
	double ard[LIMIT] = { -3.4, 8.1, -76.4, 34.4, 2.4 };
	int ari[LIMIT] = { 2, 3, 8, 1, 9 };
	double md;
	int mi;

	md = max5(ard);
	mi = max5(ari);
	cout << "md = " << md << endl;
	cout << "mi = " << mi << endl;

	return 0;
}

template <typename T>
T max5(T ar[]) 
{
	T temp = ar[0];

	for (int i = 1; i < LIMIT; i++)
	{
		if (temp < ar[i])
			temp = ar[i];
	}

	return temp;
}