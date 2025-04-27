#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <iterator>

std::vector<unsigned int> lotto(unsigned int range, unsigned int choose);

int main()
{
    using std::vector;
    using std::cout;
    using std::cin;
    using std::endl;

    vector<unsigned int> winner;
    unsigned int range;
    unsigned int choose;

    cout << "Please enter two numbers" << endl;
    cout << "First for the number of dots on the lottery card and the number" << endl;
    cout << "Second for the number of dots randomly selected (q to quit): ";
    while (cin >> range >> choose && choose <= range)
    {
        winner = lotto(range, choose);
        cout << "There are " << choose << " spots on the lottery card." << endl;
        cout << "Here are the randomly selected " << range << " lottery dots numbers:" << endl;
        std::copy(winner.begin(), winner.end(), std::ostream_iterator<int, char>(cout, " "));
        cout << "\nYou can enter two numbers again (q to quit): ";
    }
    cout << "Done." << endl;

    return 0;
}

std::vector<unsigned int> lotto(unsigned int range, unsigned int choose)
{
#if 0
    std::vector<unsigned int> temp;

    for (int i = 0; i < choose; i++)
        temp.push_back(std::rand() % range);
    
    return temp;
#else
    std::vector<unsigned int> temp(range);
    std::vector<unsigned int> random(choose);

    for (int i = 0; i < range; i++)
        temp[i] = i + 1;
    
    std::random_shuffle(temp.begin(), temp.end());
    random.assign(temp.begin(), temp.begin() + choose);

    return random;
#endif
}