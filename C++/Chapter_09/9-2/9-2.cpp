#include <iostream>
#include <string>

void strcout(const std::string str);

int main()
{
    using namespace std;
    string input;

    cout << "Enter a line:\n";
    while (getline(cin, input) && input != "")
    {
        strcout(input);
        cout << "Enter next line (empyt line to quit):\n";
    }

    cout << "Bye\n";

    return 0;
}

void strcout(const std::string str)
{
    using namespace std;
    static int total = 0;

    cout << "\"" << str << "\" contains ";
    total += str.size();
    cout << str.size() << " characters\n";
    cout << total << " characters total\n";
}