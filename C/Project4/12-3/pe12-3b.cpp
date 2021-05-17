#include <stdio.h>
#include "pe12-3a.h"
int main(void)
{
	int mode;
	int mode_flag;
	double distance, fuel;

	printf("Enter 0 for metric mode, 1 for US mode: ");
	scanf_s("%d", &mode);
	while (mode >= 0)
	{
		set_mode(&mode);
		if (mode == MODE_OTHER)
			mode = mode_flag;
		mode_flag = mode;
		get_info(mode, &distance, &fuel);
		show_info(mode, &distance, &fuel);
		printf("Enter 0 for metric mode, 1 for US mode: ");
		printf(" (-1 to quit): ");
		scanf_s("%d", &mode);
	}
	printf("Done.\n");
	return 0;
}