#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main(void)
{
	FILE* fp;
	char words[MAX];
	int words_count = 0;
	int i;

	if ((fp = fopen("wordy", "a+")) == NULL)
	{
		fprintf(stderr, "Can't open \"wordy\" file.\n");
		exit(EXIT_FAILURE);
	}

	rewind(fp);
	while (fgets(words, MAX, fp) != NULL)
		words_count++;
	rewind(fp);

	puts("Enter words to add to the file; press the #");
	puts("key at the beginning of a line to terminate.");
	while ((fscanf(stdin, "%s", words) == 1 && words[0] != '#'))
	{
		fprintf(fp, "%d:%s\n", ++words_count, words);
	}

	puts("File content:");
	rewind(fp);
	
	while (fgets(words, MAX, fp) != NULL) 
		fputs(words, stdout); 
	puts("Done!");

	if (fclose(fp) != 0)
		fprintf(stderr, "Error closing file\n");

	return 0;
}