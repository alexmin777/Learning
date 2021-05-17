#include <stdio.h>
#include <stdlib.h>
#define LINE 20
#define ROW 30

void transform(const int source[][ROW], char target[][ROW], int line);

const char map_table[] = {
	'0', ' ',
	'1', '.',
	'2', '\'',
	'3', ':',
	'4', '~',
	'5', '*',
	'6', '=',
	'7', '&',
	'8', '%',
	'9', '#'
};
int main(void)
{
	int array[LINE][ROW];
	char output[LINE][ROW];
	FILE* source;
	int line, row;

	if ((source = fopen("test", "r")) == NULL)
	{
		fprintf(stderr, "Can't open test file.\n");
		exit(EXIT_FAILURE);
	}

	for (line = 0; line < LINE; line++)
		for (row = 0; row < ROW; row++)
			fscanf(source, "%d", &array[line][row]);

	transform(array, output, LINE);

	for (line = 0; line < LINE; line++)
	{
		for (row = 0; row < ROW; row++)
			fprintf(stdout, "%c", output[line][row]);
		printf("\n");
	}
}

void transform(const int source[][ROW], char target[][ROW], int line)
{
	int lines, rows;

	for (lines = 0; lines < line; lines++)
	{
		for (rows = 0; rows < ROW; rows++)
		{
			target[lines][rows] = map_table[(2 * source[lines][rows]) + 1];
		}
	}
}