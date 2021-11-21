/*
 * Exercise 1-4: Write a program to print the corresponding Celsius
 * to Fahrenheit table.
 */

#include <stdio.h>

/*
 * print Celsius-Fahrenheit table
 * for celsius = 0, 20, ..., 300; floating-point version
 */

int main(void)
{
	printf(" C  |    F  \n");
	printf("------------\n");

	int lower = 0;   /* lower limit of temperature table */
	int upper = 300; /* upper limit */
	int step = 20;   /* step size */

	float fahr, celsius = (float)lower;
	while (celsius <= upper) {
		fahr = (float)(celsius * (9.0 / 5.0) + 32.0);
		printf("%3.0f | %6.1f\n", celsius, fahr);
		celsius = celsius + (float)step;
	}

	return 0;
}