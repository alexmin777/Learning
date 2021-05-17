#include <iostream>
#include "complex0.h"
int main()
{
	using std::cout;
	using std::endl;
	using std::cin;
	complex a(3.0, 4.0); // initialize to (3,4i)
	complex c;
	cout << "Enter a complex number (q to quit):\n";
	while (cin >> c)
	{
		cout << "c is " << c << endl;
		cout << "complex conjugate is " << ~c << endl;
		cout << "a is " << a << endl;
		cout << "a + c is " << a + c << endl;
		cout << "a - c is " << a - c << endl;
		cout << "a * c is " << a * c << endl;
		cout << "2 * c is " << 2 * c << endl;
		cout << "Enter a complex number (q to quit):\n";
	}
	cout << "Done!\n";
	/* to keep window open
	 cin.clear();
	 while (cin.get() != '\n')
	 continue;
	 cin.get();
	*/
	return 0;
}