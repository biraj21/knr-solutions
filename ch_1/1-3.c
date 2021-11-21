/*
 * Exercise 1-3: Modify the temperature conversion program to print a
 * heading above the table.
 */

#include <stdio.h>

/*
 * print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300; floating-point version
 */

int main(void)
{
	printf(" F  |    C  \n");
	printf("------------\n");

	int lower = 0;   // lower limit of temperature table
	int upper = 300; // upper limit
	int step = 20;   // step size

	float fahr = (float) lower, celsius;
	while (fahr <= upper) {
		celsius = (float) ((5.0 / 9.0) * (fahr - 32.0));
		printf("%3.0f | %6.1f\n", fahr, celsius);
		fahr = fahr + (float) step;
	}

	return 0;
}