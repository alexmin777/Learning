#include <iostream>

struct box {
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void display(const box ar);
void calc_volume(box *par);

int main(void)
{
	using namespace std;
	box carton = { "Bingo Boxer", 2, 3, 5 };
	
	calc_volume(&carton);
	display(carton);

	return 0;
}

void calc_volume(box* par)
{
	par->volume = par->height * par->length * par->width;
}

void display(const box b)
{ 
	using namespace std;
	cout << "Box maker: " << b.maker 
		<< "\nheight: " << b.height 
		<< "\nlwidth: " << b.width 
		<< "\nlength: " << b.length 
		<< "\nvolume: " << b.volume << "\n"; 
}