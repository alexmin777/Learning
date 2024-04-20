#include <iostream>
#include <vector>
#include <cctype>

const int Size = 10;

int main()
{
	using namespace std;

	int i = 0;
	int count = 0;
	int over_average = 0;
	double average = 0;
	vector<double> donation(Size);

	cout << "You may enter up to " << Size;
	cout << " donation (q to terminate)." << endl;

	while ((i < Size) && (cin >> donation[i]))
	{
		average += donation[i];
		count++;
		i++;
	}

	average /= (double)count;

	for (i = 0; i < count; i++)
	{
		if (donation[i] > average)
			over_average++;
	}

	cout << "Average: " << average << " and " << over_average << " data over average" << endl;

	return 0;
}
