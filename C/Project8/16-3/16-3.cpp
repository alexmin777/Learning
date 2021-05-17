#include <stdio.h>
#include <math.h>

#define RAD_TO_DEG (180/(4 * atan(1)))
int main(void)
{
	double length, degree;
	
	printf("Please enetr the length and degree(q to quit):\n");
	while ((scanf("%lf %lf", &length, &degree)) == 2 && length > 0)
	{
		printf("length %lf and degree %lf, result:x = %lf, y = %lf\r\n", length, degree, length * sin(degree / RAD_TO_DEG), length * cos(degree / RAD_TO_DEG));
		printf("Please enetr the length and degree(q to quit):\n");
	}
	puts("Bye!");

	return 0;

}