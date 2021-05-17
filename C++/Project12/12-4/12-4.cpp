#include <iostream>
#include <cctype>
#include "Stack.h"

int main(void)
{
	using namespace std;
	Stack st(0);
	char ch;
	unsigned long temp;

	cout << "Please enter A to add a PO,\n"
		<< "P to process a PO, and Q to quit.\n";
	while ((cin >> ch) && ((ch = toupper(ch)) != 'Q'))
	{
		while (cin.get() != '\n')
			continue;
		if ((ch != 'A') && (ch != 'P'))
		{
			cout << "Please respond with A, P, or Q: ";
			continue;
		}
		switch (ch)
		{
			case 'A':
				if (st.isfull())
					cout << "stack already full\n";
				else
				{
					cout << "Enter PO number: ";
					cin >> temp;
					cout << "Temp = " << temp << endl;
					st.push(temp);
				}
				break;
			case 'P':
				if (st.isempty())
					cout << "stack already empty\n";
				else
				{
					st.pop(temp);
					cout << "Processing PO " << temp << '\n';
				}
				break;
			default: cout << "Whoops! Programming error!\n";
		}
		cout << "Please enter A to add a customer,\n"
			<< "P to process a customer, and Q to quit.\n";

	}
	cout << "Done!\n";

	return 0;
}