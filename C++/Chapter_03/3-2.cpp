#include <iostream>

//conversion constant
const int inch2feet = 12;
const double feet2meter = 0.0254;
const double kilogram2pound = 2.2;

int main()
{
	using namespace std;

	double height_inch, height_feet = 0;
	double weight_pound = 0;

	cout << "Enter your height in inch and foot." << endl;
	cout << "Now enter your height in inch:__\b\b";
	cin >> height_inch;
	cout << "Now enter your height in foot:__\b\b";
	cin >> height_feet;

	cout << "Next enter your weight in pound:____\b\b\b\b";
	cin >> weight_pound;

	double height_meter = (height_inch * inch2feet + height_feet) * feet2meter;
	double weight_kilogram = weight_pound / kilogram2pound;

	cout << "Hey your BMI is:" << weight_kilogram / (height_meter * height_meter)
		<< endl;
	
	return 0;
}