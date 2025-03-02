#ifndef QUEUE_TP_
#define QUEUE_TP_
#include <iostream>

template <typename T>
class QueueTp
{
private:
    enum { Q_MAX = 10 };
    struct node{
        T item;
        node * next;
    };
    node * head;
    node * end;
    int count;
    const int qsize;
    //To prevent implicit use, it is defined as private.
    QueueTp(const QueueTp & q) : qsize(0) {}
    QueueTp & operator=(const QueueTp & q) { return *this; }
public:
    QueueTp(int qs = Q_MAX);
    ~QueueTp();
    bool is_empty(void) const { return (count == 0);}
    bool is_full(void) const { return (count == qsize);}
    bool enqueue(const T & data);
    bool dequeue(T & data);
    int queue_size(void) { return count; }
};

template <typename T>
QueueTp<T>::QueueTp(int qs) : qsize(qs)
{
    head = end = nullptr;
    count = 0;
}

template <typename T>
QueueTp<T>::~QueueTp()
{
    node * temp;

    while (head != nullptr)
    {
        temp = head;
        head = temp->next;
        delete temp;
    }
}

template <typename T>
bool QueueTp<T>::enqueue(const T & data)
{
    if (is_full())
        return false;
    
    node * add = new node;
    add->item = data;
    add->next = nullptr;

    if (nullptr == head)
        head = add;
    else
        end->next = add;
    end = add;
    count++;

    return true;
}

template <typename T>
bool QueueTp<T>::dequeue(T & data)
{
    if (is_empty())
        return false;
    
    data = head->item;

    node * del = head;
    head = head->next;
    delete del;
    count--;
    if (0 == count)
        end = nullptr;

    return true;
}

#endif  /* QUEUE_TP_ */