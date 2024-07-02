#ifndef __LIST_H__
#define __LIST_H__

typedef int Item;

class List
{
public:
    static const int MAX = 10;
    Item items[MAX];
    int index;

public:
    List();
    void add(Item item);
    bool is_empty();
    bool is_full();
    void visit(void (*pf)(Item & item));
};

#endif