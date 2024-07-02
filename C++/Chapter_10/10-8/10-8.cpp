#include <iostream>
#include "list.h"

void traverse(Item &item);

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    List mylist;
    Item item;
    char ch;

    cout << "The list include following functions:" << endl;
    cout << "a to add an number." << endl;
    cout << "v to visit every number." << endl;
    cout << "q to exit the menu." << endl;
    cout << "Please enter your choice: ";

    while (cin >> ch && tolower(ch) != 'q') {
        while (cin.get() != '\n');
        if (tolower(ch) != 'a' && tolower(ch) != 'v')
        {
            cout << "Please enter a, v or q: ";
            continue;
        }

        switch (ch) {
            case 'a':
                cout << "Please enter an number: ";
                while (!(cin >> item)) {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "Please enter an number again: ";
                }
                while (cin.get() != '\n');

                if (!mylist.is_full()) {
                    mylist.add(item);
                    cout << "Add number " << item << " successfully." << endl;
                } else
                    cout << "The list is full. Can't add new number." << endl;
            break;

            case 'v':
                if (!mylist.is_empty()) {
                    cout << "Visit every number:" << endl;
                    mylist.visit(traverse);
                } else
                    cout << "No number.\n";
            break;

            default:
            break;
        }

        cout << "\n\n\n";
        cout << "The list include following functions:" << endl;
        cout << "a to add an number." << endl;
        cout << "v to visit every number." << endl;
        cout << "q to exit the menu." << endl;
        cout << "Please enter your choice: ";
    }

    cout << "Bye." << endl;

    return 0;
}

void traverse(Item &item)
{
    std::cout << item << ' ';
}