#include "stack.h"
#include <iostream>
#include <cctype>

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    Item tmp;
    char ch;
    Stack stack;
    double total = 0.0;

    cout << "a to add a customer." << endl;
    cout << "d to delete a customer." << endl;
    cout << "q to exit the menu." << endl;
    cout << "Please enter your choice: ";
    while (cin >> ch && tolower(ch) != 'q') {
        while (cin.get() != '\n');
        if ('a' != tolower(ch) && 'd' != tolower(ch)) {
            cout << "Please enter a, d or q: ";
            continue;
        }

        switch (ch) {
            case 'a':
                cout << "Enter the customer's fullname: ";
                cin.getline(tmp.fullname, 35);
                cout << "Enter the customer's payment: ";
                while (!(cin >> tmp.payment)) {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "Please enter an number: ";
                }
                if (stack.isfull())
                    cout << "Can't add new customer." << endl;
                else
                    stack.push(tmp);
            break;

            case 'd':
                if (stack.isempty())
                    cout << "No any customer.\n";
                else {
                    stack.pop(tmp);
                    total += tmp.payment;
                    cout << "Customer " << tmp.fullname << " will quit." << endl;
                    cout << "Now the total payments are: " << total << endl;
                }
            break;

            default:
            break;
        }

        cout << "\n\n\n";
        cout << "a to add a customer." << endl;
        cout << "d to delete a customer." << endl;
        cout << "q to exit the menu." << endl;
        cout << "Please enter your choice: ";
    }

    cout << "Bye." << endl;

    return 0;
}