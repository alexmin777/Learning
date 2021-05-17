#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 
#include "../input.h"
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 40
#define CONTINUE    0 
#define DONE        1

struct book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};
struct pack {
	struct book books;  
	bool delete_me;
};

int getlet(const char* s);
void update(struct pack* item);
int getbook(struct pack* pb);

int main(void)
{
	struct pack  library[MAXBKS];
	int count = 0;
	int deleted = 0;
	int index, filecount, open;
	FILE* pbooks;
	int size = sizeof(struct book);

	if ((pbooks = fopen("book.dat", "r+b")) == NULL)
	{
		fputs("Can't open book.dat file.\n", stderr);
		exit(EXIT_FAILURE);
	}

	rewind(pbooks);
	while (count < MAXBKS && fread(&library[count].books, size, 1, pbooks) == 1)
	{
		if (count == 0)
			puts("Current contents of book.dat:");
		printf("%s by %s: $%.2f\n", library[count].books.title, library[count].books.author, library[count].books.value);
		printf("Do you wish to change or delete this entry?<y/n> ");
		if (getlet("yn") == 'y')
		{
			printf("Enter c to change, d to delete entry: ");
			if (getlet("cd") == 'd')
			{
				library[count].delete_me == true;
				deleted++;
				puts("Entry marked for deletion.");
			}
			else
				update(&library[count]);
		}
		count++;
	}
	fclose(pbooks);

	filecount = count - deleted;
	if (count == MAXBKS) 
	{ 
		fputs("The book.dat file is full.", stderr);
		exit(EXIT_FAILURE);
	}
	puts("Please add new book titles.");
	puts("Press [enter] at the start of a line to stop.");
	open = 0;

	while (filecount < MAXBKS)
	{
		if (filecount < count)
		{
			while (library[open].delete_me == false)
				open++;
			if (getbook(&library[open]) == DONE)
				break;
		}
		else if (getbook(&library[filecount]) == DONE)
			break;
		filecount++;
		if (filecount < MAXBKS)
			puts("Enter the next book title.");
	}

	puts("Here is the list of your books:");
	for (index = 0; index < filecount; index++)
	{
		if (library[index].delete_me == false)
			printf("%s by %s: $%.2f\n", library[index].books.title, library[index].books.author, library[index].books.value);
	}

	if ((pbooks = fopen("book.dat", "w")) == NULL)
	{ 
		fputs("Can't open book.dat file for output\n", stderr);
		exit(EXIT_FAILURE);
	}
	for (index = 0; index < filecount; index++)
	{
		if (library[index].delete_me == false) 
			fwrite(&(library[index].books), size, 1, pbooks);
	}
	fclose(pbooks);
	puts("Done!");

	return 0;
}

int getlet(const char* s)
{
	int c;
	c = getchar();
	while (strchr(s, c) == NULL)
	{
		printf("Enter a character in the list %s\n", s);
		while (getchar() != '\n')
			continue;
		c = getchar();
	}
	while (getchar() != '\n')
		continue;
	
	return c;
}

void update(struct pack* item)
{
	struct book copy;
	char c;

	copy = item->books;
	puts("Enter the letter that indicates your choice:");
	puts("t) modify title     a) modify author");
	puts("v) modify value     s) quit, saving changes");
	puts("q) quit, ignore changes");
	while ((c = getlet("tavsq")) != 's' && c != 'q')
	{
		switch (c)
		{
			case 't':
				puts("Enter new title: ");
				s_gets(copy.title, MAXTITL);
				break;
			case 'a':
				puts("Enter new author: ");
				s_gets(copy.author, MAXTITL);
				break;
			case 'v':
				puts("Enter new value: ");
				while(scanf("%f", &copy.value) != 1)
				{
					puts("Enter a numeric value: ");
					scanf("%*s");
				}
				while (getchar() != '\n')
					continue;
				break;
		}
		puts("t) modify title     a) modify author");
		puts("v) modify value     s) quit, saving changes");
		puts("q) quit, ignore changes");
	}

	if (c == 's')
		item->books = copy;
}

int getbook(struct pack* pb)
{
	int status = CONTINUE;
	if (s_gets(pb->books.title, MAXTITL) == NULL || pb->books.title[0] == '\0')
	{
		status = DONE;
	}
	else
	{
		printf("Now enter the author: ");
		s_gets(pb->books.author, MAXAUTL);
		printf("Now enter the value: ");
		while (scanf("%f", &pb->books.value) != 1)
		{
			puts("Please use numeric input");
			scanf("%*s");
		}
		while (getchar() != '\n')
			continue;
		pb->delete_me = false;
	}

	return status;
}