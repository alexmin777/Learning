#include <iostream>


using namespace std;

typedef void (*pf)(double *data, int size);

void input(double *data, int size);
void show(double *data, int size);
void calc(double *data, int size);

const int func_size = 3;
const int max_size = 10;

int main()
{
	double score[max_size] = {0};
	pf process[func_size] = {input, show, calc};

	for (int i = 0; i < func_size; i++)
		process[i](score, max_size);

	return 0;
}

void input(double *data, int size)
{
	int i = 0;

	cout << "enter the score ten times(0 to stop)";
	while (cin >> data[i] && data[i] && i++ < size - 1);
}

void show(double *data, int size)
{
	cout << "data: ";
	for (int i = 0; i < size; i++)
		cout << data[i] << " ";
	
	cout << endl;
}

void calc(double *data, int size)
{
	double sum = 0;

	for (int i = 0; i < size; i++)
		sum += data[i];
	
	cout << "Average: " << sum / size << endl;
}