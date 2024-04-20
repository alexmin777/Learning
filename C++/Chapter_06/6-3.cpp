#include <iostream>

int main()
{
	using namespace std;

	char ch;

	cout << "Please enter one of the following choices:" << endl;
	cout << "c) carnivore p) pianist\nt) tree g) game" << endl;

	while (cin >> ch)
	{
		switch (ch) 
		{
			case 'c':
				cout << "carnivore" << endl;
				break;
			case 'p':
				cout << "pianist" << endl;
				break;
			case 't':
				cout << "Amaple is a tree" << endl;
				break;
			case 'g':
				cout << "game" << endl;
				break;
			default:
				cout << "Please enter a c, p, t or g:" << endl;
		}
		if (ch == 'c' || ch == 'p' || ch == 't' || ch == 'g')
			break;
	}

	return 0;
}