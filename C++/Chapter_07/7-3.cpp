#include <iostream>

typedef struct {
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
} box;

void show_box(const box data);
void calc_volume(box * data);

int main()
{
	using namespace std;

	box product = {"alex_min", 10.1, 20.2, 30.3};

	calc_volume(&product);
	show_box(product);

	return 0;
}

void show_box(const box data)
{
	using namespace std;

	cout << "Maker:" << data.maker;
	cout << " height:" << data.height;
	cout << " width:" << data.width;
	cout << " length:" << data.length;
	cout << " volume:" << data.volume << endl;
}

void calc_volume(box * data)
{
	data->volume = data->height * data->width * data->length;
}