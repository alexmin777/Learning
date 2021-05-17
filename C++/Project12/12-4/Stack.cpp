#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Stack.h"

Stack::Stack(int n)
{
	printf("默认构造函数\n");
	size = n;
	pitems = new Item[MAX + 1];
	top = 0;
}

Stack::Stack(const Stack& st)
{
	printf("复制构造函数\n");
	size = st.size;
	pitems = new Item[size + 1];
	memcpy((void*)pitems, (void*)st.pitems, sizeof(Item) * size + 1);
	top = st.top;
}

Stack::~Stack()
{
	delete[] pitems;
}

bool Stack::isempty() const
{
	return top == 0 ? true : false;
}

bool Stack::isfull() const
{
	return top == MAX ? true : false;
}

bool Stack::push(const Item& item)
{
	if (top < MAX)
	{
		pitems[top++] = item;
		return true;
	}
	else
		return false;
}

bool Stack::pop(Item& item)
{
	if (top > 0)
	{
		item = pitems[--top];
		return true;
	}
	else
		return false;
}

Stack& Stack::operator=(const Stack& st)
{
	printf("赋值运算符\n");
	if (this == &st)
		return *this;
	delete[] pitems;
	size = st.size;
	pitems = new Item[size + 1];
	memcpy((void*)pitems, (void*)st.pitems, sizeof(Item) * size + 1);
	top = st.top;
}