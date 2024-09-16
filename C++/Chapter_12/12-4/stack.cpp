#include "stack.h"
#include <iostream>

Stack::Stack(int n)
{
    if (n > MAX)
    {
        std::cout << "The length of stack can't exceed 10.\n";
        std::cout << "So initialize the length to 10.\n";
        size = MAX;
    }
    else if (n < 0)
    {
        std::cout << "The length of stack can't less than 0.\n";
        std::cout << "So initialize the length to 10.\n";
        size = MAX;
    }
    else
    {
        size = n;
    }
    pitems = new Item[size];
    top = 0;
}

Stack::Stack(const Stack & st)
{
    size = st.size;
    pitems = new Item[size];
    for (int i = 0; i < size; i++)
        pitems[i] = st.pitems[i];
    top = st.top;
}

Stack::~Stack()
{
    delete [] pitems;
}

bool Stack::isempty() const
{
    return (top == 0);
}

bool Stack::isfull() const
{
    return (top == size);
}

bool Stack::push(const Item & item)
{
    if (isfull()) {
        return false;
    } else {
        pitems[top++] = item;
        return true;
    }
}

bool Stack::pop(Item & item)
{
    if (isempty()) {
        return false;
    } else {
        item = pitems[top--];
        return true;
    }
}

Stack & Stack::operator=(const Stack & st)
{
    if (this == &st)
        return *this;

    delete [] pitems;

    size = st.size;
    top = st.top;
    pitems = new Item[size]; 
    for (int i = 0; i < top; i++)
    {
        pitems[i] = st.pitems[i];
    }

    return *this;
}

std::ostream &operator<<(std::ostream &os, const Stack &st)
{
    for (int i = st.top - 1; i >= 0; i--)
    {
        os << st.pitems[i] << std::endl;
    }
    return os;
}