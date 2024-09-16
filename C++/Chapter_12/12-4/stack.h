#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>

typedef unsigned long Item;

class Stack {
private:
    enum {MAX = 10};
    Item * pitems;
    int size;
    int top;
public:
    Stack(int n = MAX);
    Stack(const Stack & st);
    ~Stack();
    bool isempty() const;
    bool isfull() const;
    //push() returns false if stack already is full, ture otherwise
    bool push(const Item & item);   //add item to stack
    //pop() returns false if stack already is empty, ture otherwise
    bool pop(Item & item); //pop top into item
    Stack & operator=(const Stack & st);
//friend
    friend std::ostream &operator<<(std::ostream &os, const Stack &st);
};

#endif  /* __STACK_H__ */