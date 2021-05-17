#include <iostream>
#include "Stack.h"
#include <cctype>

void get_customer(customer& cu);

int main(void)
{
	using namespace std;
	Stack st;
	customer temp;
	double payments = 0;
	char c;

	cout << "Please enter A to add a customer,\n" 
		<< "P to process a customer, and Q to quit.\n";
	while (cin >> c && (c = toupper(c)) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (c != 'A' && c != 'P')
		{
			cout << "Please respond with A, P, or Q: ";
			continue;
		}
		switch (c)
		{
			case 'A':
				if (st.isfull())
					cout << "stack already full\n";
				else 
				{ 
					get_customer(temp);
					st.push(temp);
				}                             
			break; 
			case 'P':
				if (st.isempty())
					cout << "stack already empty\n";
				else 
				{ 
					st.pop(temp);
					payments += temp.payment;
					cout << temp.fullname << " processed. ";
					cout << "Payments now total $" << payments << "\n"; 
				}
			break;             
			default:
				cout << "Whoops! Programming error!\n";
		}
		cout << "Please enter A to add a customer,\n" 
			<< "P to process a customer, and Q to quit.\n";
	}
	cout << "Done!\n";

	return 0;
}

void get_customer(customer& cu) 
{ 
	using namespace std;
	cout << "Enter customer name: ";
	cin.getline(cu.fullname, 35);
	cout << "Enter customer payment: ";
	cin >> cu.payment;
	while (cin.get() != '\n')
		continue; 
}