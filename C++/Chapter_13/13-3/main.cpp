#include <iostream>
#include "dma.h"
const int LEN = 3;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    DMA *temp[LEN];
    char label[50];
    int rating;
    char color[40];
    char style[50];
    char kind;

    cout << "Here are the process for creating 3 objects" << endl;
    for (int i = 0; i < LEN; i++)
    {
        cout << "Enter 1 for baseDMA, 2 for lacksDMA or 3 for hasDMA: ";
        while (cin >> kind && (kind != '1' && kind != '2' && kind != '3'))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Please enter 1, 2 or 3: ";
        }
        if (kind == '1')
        {
            cout << "Please enter the label: ";
            cin >> label; 
            cout << "Please enter the rating: ";
            cin >> rating;
            temp[i] = new baseDMA(label, rating, "baseDMA");
        }
        else if (kind == '2')
        {
            cout << "Please enter the color: ";
            cin >> color;
            temp[i] = new lacksDMA(color, "lacksDMA");
        }
        else
        {
            cout << "Please enter the style: ";
            cin >> style;
            temp[i] = new hasDMA(style, "hasDMA");
        }
    }
    cout << "\nThe results after creating 3 objects" << endl;
    for (int i = 0; i < LEN; i++)
    {
        temp[i]->View();
    }
    for (int i = 0; i < LEN; i++)
    {
        delete temp[i];
    }
    cout << "Done.\n";

    return 0;
}
