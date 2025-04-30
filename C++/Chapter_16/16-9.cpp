#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <algorithm>
#include <iterator>

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::vector;
    using std::list;

    srand(time(0));

    long size = 0;
    clock_t start, end;
    cout << "Enter size of test array: ";
    while (cin >> size && size > 0)
    {
        vector<int> vi0(size);
        vector<int> vi(vi0);
        list<int> li(vi0.begin(), vi0.end());
        for (int i = 0; i < size; i++)
            vi0[i] = rand() % 100 + 1;
        
        cout << "sort vector cust: ";
        start = clock();
        sort(vi.begin(), vi.end());
        end = clock();
        cout << (double)(end - start) / CLOCKS_PER_SEC << endl;

        cout << "sort list cust: ";
        start = clock();
        li.sort();
        end = clock();
        cout << (double)(end - start) / CLOCKS_PER_SEC << endl;

        cout << "use constructor, copy to vector and sort, recpoy to list cust: ";
        sort(vi0.begin(), vi0.end());
        li = list<int> (vi0.begin(), vi0.end());
        start = clock();
        vi = vector<int> (li.begin(), li.end());
        sort(vi.begin(), vi.end());
        li = list<int> (vi.begin(), vi.end());
        end = clock();
        cout << (double)(end - start) / CLOCKS_PER_SEC << endl;

        cout << "not use constructor, copy to vector and sort, recpoy to list cust: ";
        sort(vi0.begin(), vi0.end());
        copy(vi0.begin(), vi0.end(), li.begin());
        start = clock();
        copy(li.begin(), li.end(), vi.begin());
        sort(vi.begin(), vi.end());
        copy(vi.begin(), vi.end(), li.begin());
        end = clock();
        cout << (double)(end - start) / CLOCKS_PER_SEC << endl;

        cout << "Enter size of test array: ";
    }

    return 0;
}