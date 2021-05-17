#include <iostream>

void display(const char* str, int n = 0);

int main(void)
{
	using namespace std;
	const char* p = "Why me?\n";
	
	display(p);
	for (int i = 0; i < 3; i++)
	{
		cout << i << " = i\n";
		display(p, i);
	}
	cout << "Done.\n";
	
	return 0;
}


void display(const char* str, int n)
{
	using namespace std;
	static int count = 0;
	
	count++;
	if (n == 0)
		cout << str;
	else
	{
		for (int i = 0; i < count; i++)
			cout << str;
	}
}
