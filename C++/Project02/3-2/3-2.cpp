#include <iostream>

const int inch_to_foot = 12;
const double foot_to_mile = 0.0254;
const double kg_to_pound = 2.2;

int main(void)
{
	using namespace std;

	cout << "Please enter your height:" << endl;
	cout << "First,enter your height of feet part:_\b";
	int ht_feet;
	cin >> ht_feet;
	cout << "Second,enter your height of inch part:_\b";
	int ht_inch;
	cin >> ht_inch;
	cout << "Now,please enter your weight in pound:___\b\b\b";
	double wt_pound;
	cin >> wt_pound;
	int total_foot = ht_inch * inch_to_foot + ht_feet;
	double ht_mile = foot_to_mile * total_foot;
	double wt_kg = wt_pound / kg_to_pound;

	cout << "Your pensonal body information as follows:" << endl;
	cout << "身高:" << total_foot << "(英寸foot)\n" << "身高:" << ht_mile << "(米meter)\n"\
		<< "体重:" << wt_kg << "(千克kilogram)\n";
	
	double BMI;
	BMI = wt_kg / (ht_mile * ht_mile);
	cout << "Your Body BMI is " << BMI << endl;

	return 0;
}