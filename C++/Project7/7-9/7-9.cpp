#include <iostream>
#define SLEN 30

using namespace std;
struct student {
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(student* ps);
void display3(const student pa[], int n);

int main(void)
{
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n')
		continue;

	student* ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete[] ptr_stu;
	cout << "Done.\n";

	return 0;
}

int getinfo(student pa[], int n)
{
	int i;
	
	for (i = 0; i < n; i++)
	{
		cout << "Enter student name: ";
		cin.getline(pa[i].fullname, SLEN);
		if (pa->fullname[0] == '\0')
			break;
		cout << "Enter student hobby: ";
		cin.getline(pa[i].hobby, SLEN);
		cout << "Enter student oop level: ";
		cin >> pa[i].ooplevel;
		while (cin.get() != '\n')
			continue;
	}

	return i;
}

void display1(student st)
{
	cout << st.fullname << ": " << st.hobby << ": "
		<< st.ooplevel << "\n";
}

void display2(student* ps)
{
	cout << ps->fullname << ": " << ps->hobby << ": "
		<< ps->ooplevel << "\n";
}

void display3(const student pa[], int n)
{
	for (int i = 0; i < n; i++)
		cout << pa[i].fullname << ": " << pa[i].hobby << ": "
		<< pa[i].ooplevel << "\n";
}