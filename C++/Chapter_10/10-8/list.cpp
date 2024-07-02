#include <cstring>
#include "list.h"

List::List()
{
    memset(items, 0, MAX * sizeof(Item));
    index = 0;
}

void List::add(Item item)
{
    items[index++] = item;
}

bool List::is_empty()
{
    return (index == 0) ? true : false; 
}

bool List::is_full()
{
    return (index == MAX) ? true : false; 
}

void List::visit(void (*pf)(Item & item))
{
    for (int i = 0; i < index; i++)
        (*pf)(this->items[i]);
}