#ifndef __STACK_H_
#define __STACK_H_

typedef struct customer
{
    char fullname[35];
    double payment;
} Item;

class Stack
{
private:
    enum {MAX = 10};
    Item item[MAX];
    int top;

public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item & item);
    bool pop(Item & item);
};

#endif // __STACK_H_