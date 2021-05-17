#ifndef PLORG_H_
#define PLORG_H_

class Plorg
{
private:
	static const int SIZE = 20;
	char name[SIZE];
	int cl;
public:
	Plorg(const char * n = "Plorga");
	~Plorg();
	void alterCI(int c);
	void reprot(void) const;
};
#endif // !PLORG_H_
