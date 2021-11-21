/*
 * Exercise 1-15: Rewrite the temperature conversion program of Section 1.2
 * to use a function for conversion.
 */

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float fahr_to_celsius(float fahr);

int main(void)
{
	printf(" F  |    C  \n");
	printf("------------\n");

	for (int fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
		printf("%3d | %6.1f\n", fahr, fahr_to_celsius((float)fahr));
	}

	return 0;
}

float fahr_to_celsius(float fahr) {
	return (float)((5.0 / 9.0) * (fahr - 32.0));
}