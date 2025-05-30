#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

template <typename T>
int reduce(T ar[], int n)
{
    sort(ar, ar + n);
    return static_cast<int>(unique(ar, ar + n) - ar);
}

template <typename T>
void print_array(T ar[], int n)
{
    for (int i = 0; i < n; i ++)
        cout << ar[i] << ' ';
    cout << endl;
}

int main()
{
    long ar[] = {1L, 2L, 4L, 8L, 6L, 6L, 4L, 2L, 4L, 6L, 5L};
    string s[] = {"vector", "set", "map", "multiset", "multimap", "set", "map", "vector"};

    cout << "Print array before sorting and removing repetitive values(long):" << endl;
    print_array(ar, sizeof(ar) / sizeof(ar[0]));
    cout << "Print array before sorting and removing repetitive values(string):" << endl;
    print_array(s, sizeof(s) / sizeof(s[0]));
    cout << "Print array after sorting and removing repetitive values(long):" << endl;
    print_array(ar, reduce(ar, sizeof(ar) / sizeof(ar[0])));
    cout << "Print array after sorting and removing repetitive values(string):" << endl;
    print_array(s, reduce(s, sizeof(s) / sizeof(s[0])));

    return 0;
}