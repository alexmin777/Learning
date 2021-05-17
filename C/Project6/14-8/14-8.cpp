#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../input.h"
#define LEN 128
#define MAX 12
#define CHOICES 6
#define EMPTY      0 
#define TAKEN      1
#define CONTINUE   1 
#define DONE       0

extern char* s_gets(char* st, int n);

struct name
{
	char first[LEN];
	char last[LEN];
};
struct seat
{
	unsigned int seat_id;
	bool status;
	struct name person;
};

int getmenu(void);
char getlet(const char * st);
int openings(const struct seat[], int);
void makelist(const struct seat[], char*, int);
void show_empty_seats(const struct seat[], int);
void list_assign(const struct seat* [], int);
void sort(struct seat* [], int);
void assign_seat(struct seat[], int);
void delete_seat(struct seat[], int);

int main(void)
{
	struct seat seats[MAX], *ps[MAX];
	char choose;
	FILE* fp;
	int size = sizeof(struct seat);
	int i;

	for (i = 0; i < MAX; i++)
		ps[i] = &seats[i];

	if ((fp = fopen("air.dat", "rb")) == NULL)
	{
		for (i = 0; i < MAX; i++)
		{
			seats[i].status = EMPTY;
			seats[i].seat_id = i + 1;
		}
	}
	else
	{
		fread(seats, size, MAX, fp);
		fclose(fp);
	}

	while ((choose = getmenu()) != 'f')
	{
		switch (choose)
		{
			case 'a':
				printf("There are %d empty seats.\n", openings(seats, MAX));
				break;
			case 'b':
				show_empty_seats(seats, MAX);
				break;
			case 'c':
				list_assign(ps, MAX);
				break;
			case 'd':
				assign_seat(seats, MAX);
				break;
			case 'e':
				delete_seat(seats, MAX);
				break;
			default:
				puts("Switch trouble");
				break;
		}
	}
	
	if ((fp = fopen("air.dat", "wb")) == NULL)
		puts("Can't save data to file.");
	else 
	{ 
		fwrite(seats, size, MAX, fp);
		fclose(fp);
	}     
	puts("Bye from Colossus Airlines!");
	return 0;
}

int getmenu(void) 
{ 
	const char* descript[CHOICES] = { 
		"Show number of empty seats",
		"Show list of empty seats",
		"Show alphabetical list of seat assignments",
		"Assign a customer to a seat",
		"Delete a seat assignment",
		"Quit" 
	};     
	const char labels[CHOICES + 1] = "abcdef";
	int i;
	puts("To choose a function, enter its letter label");
	for (i = 0; i < CHOICES; i++)         
		printf("%c) %s\n", labels[i], descript[i]);
	
	return getlet(labels); 
}

void show_empty_seats(const struct seat pl[], int n)
{
	char seating[3 * MAX];
	if (openings(pl, n) == 0)
		puts("All seats are assigned");
	else
	{
		puts("The following seats are available:");
		makelist(pl, seating, EMPTY);
		puts(seating);
	}
}

void makelist(const struct seat pl[], char* str, int kind)
{ 
	int seat;
	char temp[LEN];          
	str[0] = '\0';     
	for (seat = 0; seat < MAX; seat++)
		if (pl[seat].status == kind) 
		{ 
			sprintf(temp, " %d", pl[seat].seat_id);
			strcat(str, temp);
		}
}

void list_assign(struct seat* ps[], int n)
{
	int i;

	if (openings(*ps, n))
		puts("All seats are assigned");
	else
	{
		sort(ps, n);
		for (i = 0; i < MAX; i++)
			if ( ps[i]->status == TAKEN )
				printf("Seat %d:%s, %s\n", ps[i]->seat_id, ps[i]->person.last, ps[i]->person.first);
	}
}

void sort(struct seat* array[], int limit)
{
	int top, search;
	struct seat* temp;

	for (top = 0; top < limit - 1; top++)
		for (search = top + 1; search < limit; search++)
			if (strcmp(array[search]->person.last, array[top]->person.last) < 0) 
			{ 
				temp = array[search];
				array[search] = array[top];
				array[top] = temp;
			}
}

void assign_seat(struct seat pl[], int n)
{
	char list[3 * MAX];
	int seat, loop;

	if (openings(pl, n) == 0)
		puts("All seats are assigned.");
	else
	{
		makelist(pl, list, EMPTY);
		puts("Which seat do you want? Choose from this list:");
		puts(list);
		do
		{
			while(scanf("%d", &seat) != 1)
			{
				scanf("%*s");
				puts("Enter a number from this list:");
				puts(list);
			}
			if (seat < 1 || seat > MAX || pl[seat - 1].status == TAKEN)
			{
				puts("Enter a number from this list:");
				puts(list);
				loop = CONTINUE;
			}
			else
				loop = DONE;
		} while (loop == CONTINUE);
		while (getchar() != '\n')
			continue;

		puts("Enter first name:");
		s_gets(pl[seat - 1].person.first, LEN);
		puts("Enter last name:");
		s_gets(pl[seat - 1].person.last, LEN);
		printf("%s %s assigned to seat %d.\n", pl[seat - 1].person.first, pl[seat - 1].person.last, seat);
		puts("Enter a to accept assignment, c to cancel it.");
		if (getlet("ac") == 'a')
		{
			pl[seat - 1].status = TAKEN;
			puts("Passenger assigned to seat.");
		}
		else
			puts("Passenger not assigned.");
	}
}

void delete_seat(struct seat pl[], int n)
{
	int seat, loop;
	char list[3 * MAX];

	if (openings(pl, n) == 0)
		puts("All seats already are empty.");
	else
	{
		makelist(pl, list, TAKEN);
		puts(list);
		puts("Enter the number of the seat to be cancelled:");
		do
		{
			while (scanf("%d", &seat) != 1)
			{
				scanf("%*s");
				puts("Enter a number from this list:");
				puts(list);
			}
			if (seat < 1 || seat > MAX || pl[seat - 1].status == EMPTY)
			{
				puts("Enter a number from this list:");
				puts(list);
				loop = CONTINUE;
			}
			else
				loop = DONE;
		} while (loop == CONTINUE);
		while (getchar() != '\n')
			continue;

		printf("%s %s to be canceled for seat %d.\n", pl[seat - 1].person.first, pl[seat - 1].person.last, seat);
		puts("Enter d to delete assignment, a to abort.");
		if (getlet("da") == 'd') 
		{ 
			pl[seat - 1].status = EMPTY;
			puts("Passenger dropped.");
		}
		else
			puts("Passenger retained.");
	}
}

int openings(const struct seat pl[], int n)
{
	int count = 0;
	int i;

	for (i = 0; i < n; i++)
	{
		if (pl[i].status == EMPTY)
			count++;
	}

	return count;
}

void makelist(const struct seat pl[], char* str, int kind)
{
	int seat;
	char temp[LEN];
	str[0] = '\0';
	for (seat = 0; seat < MAX; seat++)
		if (pl[seat].status == kind)
		{
			sprintf(temp, " %d", pl[seat].seat_id);
			strcat(str, temp);
		}
}

char getlet(const char* st)
{
	char c;

	c = getchar();
	while (strchr(st, c) == NULL)
	{
		printf("Enter a character in the list %s\n", st);
		while (getchar() != '\n')
			continue;
		c = getchar();
	}
	while (getchar() != '\n')
		continue;

	return c;
}