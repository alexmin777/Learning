#include <iostream>
#include "list.h"
#include <cstdlib>

void showmovies(Item &item);

int main(void)
{
	using namespace std;
	list movies;
	Item temp;

	if (movies.isfull())
	{
		cout << "No more room in list! Bye!\n"; 
		exit(1);
	}
	cout << "Enter first movie title:\n";
	while (cin.getline(temp.title, SIZE) && temp.title[0] != '\0')
	{
		cout << "Enter your rating <0-10>: ";
		cin >> temp.rating;
		while (cin.get() != '\n')
			continue;
		if (movies.additem(temp) == false) 
		{ 
			cout << "List already is full!\n";
			break; 
		}
		if (movies.isfull()) 
		{ 
			cout << "You have filled the list.\n";
			break; 
		}
		cout << "Enter next movie title (empty line to stop):\n";
	}
	if (movies.isempty())
		cout << "No data entered. ";
	else
	{
		cout << "Here is the movie list:\n";
		movies.visit(showmovies);
	}
}

void showmovies(Item & item) 
{ 
	std::cout << "Movie: " << item.title 
		<< "  Rating: " << item.rating 
		<< std::endl; 
}