#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <set>

int main()
{
    using namespace std;

    set<string> mat;
    set<string> pat;
    string name;

    cout << "Mat, Enter the name of the friend you want to invite(quit to quit): ";
    while (cin >> name && name != "quit")
    {
        mat.insert(name);
        cout << "Next name(quit to quit):";
    }

    cout << "Pat, Enter the name of the friend you want to invite(quit to quit): ";
    while (cin >> name && name != "quit")
    {
        pat.insert(name);
        cout << "Next name(quit to quit):";
    }

    cout << "Mat, The following is the list of people you want to invite: \n";
    copy(mat.begin(), mat.end(), ostream_iterator<string, char> (cout, " "));
    cout << endl;
    cout << "Pat, The following is the list of people you want to invite: \n";
    copy(pat.begin(), pat.end(), ostream_iterator<string, char> (cout, " "));
    cout << endl;

    cout << "Here are the Mat and Pat friends after merging and removing repetitive values:" << endl;
    set_union(mat.begin(), mat.end(), pat.begin(), pat.end(), ostream_iterator<string, char> (cout, " "));
    cout << "Done." << endl;

    return 0;
}