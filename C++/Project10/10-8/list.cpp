#include <iostream>
#include <cstring>
#include "list.h"

list::list()
{
	index = 0;
}

bool list::isempty(void)
{
	return (index == 0);
}

bool list::isfull(void)
{
	return (index == SIZE);
}

bool list::additem(Item item)
{
	if (isfull())
		return 0;
	else
		items[index++] = item;
	return 1;
}

void list::visit(void (*pf)(Item& item))
{
	for (int i = 0; i < index; i++)
		(*pf)(items[i]);
}