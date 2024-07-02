#include "stack.h"
#include <iostream>
#include <cstring>

Stack::Stack()
{
    memset(item, 0, sizeof(Item));
    top = 0;
}

bool Stack::isempty() const
{
    std::cout << "Now ptr = " << top << std::endl;
    return (top == 0) ? true : false;
}

bool Stack::isfull() const
{
    std::cout << "Now ptr = " << top << std::endl;
    return (top == MAX) ? true : false;
}

bool Stack::push(const Item & item)
{
    if (isfull()) {
        return false;
    } else {
        this->item[top++] = item;
        return true;
    }
}

bool Stack::pop(Item & item)
{
    if (isempty()) {
        return false;
    } else {
        item = this->item[--top];
        return true;
    }
}