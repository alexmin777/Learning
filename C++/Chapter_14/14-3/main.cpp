#include <iostream>
#include <cstring>
#include "QueueTp.h"
#include "worker.h"

const int SIZE = 5;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    Worker *tmp;
    QueueTp<Worker *> lolas(SIZE);

    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the menu order:" << endl;
        cout << "a: add a worker to queue." << endl;
        cout << "d: delete a worker from queue." << endl;
        cout << "q: quit." << endl;
        cin >> choice;
        while (NULL == strchr("adq", choice))
        {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }
        if ('q' == choice)
            break;

        switch (choice)
        {
            case 'a':
                tmp = new Worker;
                cin.get();
                if (lolas.is_full())
                {
                    cout << "Queue is full!" << endl;
                    delete tmp;
                }
                else
                {
                    tmp->Set();
                    lolas.enqueue(tmp);
                }
                break;
            case 'd':
                if (lolas.is_empty())
                {
                    cout << "Queue is empty!" << endl;
                }
                else
                {
                    lolas.dequeue(tmp);
                }
                break; 
        }
    }

    ct = lolas.queue_size();
    cout << "\nHere is " << ct << " worker(s) in queue:" << endl;
    for (int i = 0; i < ct; i++)
    {
        lolas.dequeue(tmp);
        tmp->Show();
    }
    cout << "Done.\n";

    return 0;
}