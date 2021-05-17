#include <iostream>

using namespace std;

void showmenu(void);

int main(void)
{
	using namespace std;

	char ch;
	showmenu();
	cout << "Please enter a c, p, t, or g: ";
	cin >> ch;
	while (ch != 'c' && ch != 'p' && ch != 't' && ch != 'g')
	{
		cout << "Please enter a c, p, t, or g: ";
		cin >> ch;
	}

	switch (ch)
	{
		case 'c' : cout << "A cat is a carnivore.\n";
				   break;
		case 'p':  cout << "Radu Lupu is a pianist.\n";
				   break;
		case 't':  cout << "A maple is a tree.\n";
				   break;
		case 'g':  cout << "Golf is a game.\n";
				   break;
		default :  cout << "The program shouldn't get here!\n";
	}

	return 0;
}

void showmenu(void)
{
	cout << "Please enter one of the following choice:\n";
	cout << "c) carnivore		p) pianist\n";
	cout << "t) tree			g) game\n";
}