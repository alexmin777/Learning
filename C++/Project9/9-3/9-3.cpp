#include <iostream>
#include <new>

struct charff
{
	char dross[20];
	int slag;
};

const int ArSize = 2;

int main(void)
{
	using namespace std;
	char* buff = new char[500];
	charff* sz = new (buff) charff[ArSize];

	strcpy(sz[0].dross, "Horse Feathers");
	sz[0].slag = 13;
	strcpy(sz[1].dross, "Piffle");
	sz[1].slag = -39;

	for (int i = 0; i < ArSize; i++)
		cout << sz[i].dross << ": " << sz[i].slag << endl;
	
	delete[] buff;

	return 0;
}