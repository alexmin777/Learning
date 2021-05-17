#ifndef LIST_H_
#define LIST_H_

const int SIZE = 45;
struct film
{
	char title[SIZE];
	int rating;
};

typedef film Item;

class list
{
private:
	Item items[SIZE];
	int index;
public:
	list();
	bool additem(Item item);
	bool isempty(void);
	bool isfull(void);
	void visit(void (*pf)(Item& item));
};
#endif // !LIST_H_