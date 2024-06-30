#include <iostream>
#include <cstring>

const int Size = 20;

struct chaff
{
    char dross[Size];
    int slag;
};

const int BUF = 512;
int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    char *buffer2 = new char[BUF];
    chaff *pchaff;
    char tmp[Size];

    pchaff = new (buffer2) chaff[2];

    cout << "Memory pool address: " << (void *)buffer2 << endl;
    cout << "pchaff address: " << pchaff << endl;

    for (int i = 0; i < 2; i++)
    {
        cout << "Enter #" << i + 1 << " chaff's dross: ";
        cin.getline(tmp, Size);
        strcpy(pchaff[i].dross, tmp);

        cout << "Enter #" << i + 1 << " chaff's slag: ";
        while (!(cin >> pchaff[i].slag))
        {
            cin.clear();
            while(cin.get() != '\n');
            cout << "Please enter number:\n";
        }
        while(cin.get() != '\n');
    }

    for (int i = 0; i < 2; i++)
    {
        cout << "#" << i + 1 << " chaff's dross: " << pchaff[i].dross << endl;
        cout << "#" << i + 1 << " chaff's slag: " << pchaff[i].slag << endl;
    }

    return 0;
}