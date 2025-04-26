#include <iostream>
#include <string>

bool is_palindrome(std::string & st);

int main()
{
    using namespace std;

    string temp;
    bool palindrome = false;

    cout << "Enter words, quit to quit:\n";
    while (cin >> temp && temp != "quit")
    {
        palindrome = is_palindrome(temp);
        if (palindrome)
            cout << "You enter word is palindrome!\n";
        
        cout << "Next words, quit to quit:\n";
    }

    cout << "Bye!" << endl;

    return 0;
}

bool is_palindrome(std::string & st)
{
    std::string::iterator pbegin = st.begin();
    std::string::iterator pend = st.end() - 1;

    while (pbegin < pend)
    {
        if (*pbegin < *pend)
            return false;

        pbegin++;
        pend--;
    }

    return true;
}