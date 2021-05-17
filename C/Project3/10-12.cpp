#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char ch;
	int num_of_word = 0;
	int num_of_up = 0;
	int num_of_low = 0;
	int num_of_func = 0;
	int num_of_dig = 0;
	int flag = 0;

	printf("Enter text to be analyzed (EOF to terminate):\n");
	while ((ch = getchar()) != EOF)
	{
		if (!isblank(ch) && !flag)
		{
			num_of_word++;
			flag = 1;
		}
		if (isblank(ch) && flag)
		{
			flag = 0;
		}
		if (isupper(ch))
			num_of_up++;
		else if (islower(ch))
			num_of_low++;
		else if (ispunct(ch))
			num_of_func++;
		else if (isdigit(ch))
			num_of_dig++;
	}
	printf("\nwords = %d, lowercase = %d, uppercase = %d, "
		"digits = %d, punctuation = %d\n", num_of_word, num_of_low, num_of_up, num_of_dig, num_of_func);

	return 0;
}