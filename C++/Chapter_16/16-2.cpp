#include <iostream>
#include <string>
#include <cctype>

std::string ToLower(std::string &st);
bool is_palindrome(std::string & st);

int main()
{
    using namespace std;

    string temp;
    bool palindrome = false;

    cout << "Enter words, quit to quit:\n";
    while (getline(cin, temp) && temp != "quit")
    {
        temp = ToLower(temp);
        palindrome = is_palindrome(temp);
        if (palindrome)
            cout << "You enter word is palindrome!\n";
        
        cout << "Next words, quit to quit:\n";
    }

    cout << "Bye!" << endl;

    return 0;
}

std::string ToLower(std::string &st)
{
    std::string s;
    for (auto &x : st)
    {
        if (!isspace(x) && !ispunct(x))
        {
            s += tolower(x);
        }
    }
    return s;
}

bool is_palindrome(std::string & st)
{
    return st == std::string(st.rbegin(), st.rend());
}