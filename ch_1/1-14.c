/*
 * Exercise 1-14: Write a program to print a histogram of the frequencies
 * of different characters in its input.
 *
 * The histogram is vertical.
 */

#include <stdio.h>

#define TOTAL_CHARS (10 + 26 + 26 + 1)
#define OFFSET_UPPER 10
#define OFFSET_LOWER (10 + 26)

int main(void)
{
	int freqs[TOTAL_CHARS] = {0};

	/*
	 * indices 0-9 will be for digits
	 * indices 10-35 will be for uppercase alphabets
	 * indices 36-61 will be for lowercase alphabets
	 * index 62 will be for other characters
	 */

	// calculating frequencies
	int c;
	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9') {
			++freqs[c - '0'];
		} else if (c >= 'A' && c <= 'Z') {
			++freqs[OFFSET_UPPER + c - 'A'];
		} else if (c >= 'a' && c <= 'z') {
			++freqs[OFFSET_LOWER + c - 'a'];
		} else {
			++freqs[TOTAL_CHARS - 1];
		}
	}

	// finding maximum frequency
	int max_freq = 0;
	for (int i = 0; i < TOTAL_CHARS; ++i) {
		if (freqs[i] > max_freq) {
			max_freq = freqs[i];
		}
	}

	// drawing histogram
	for (int y = max_freq; y > 0; --y) {
		printf("%3d|", y);
		for (int i = 0; i < TOTAL_CHARS; ++i) {
			if (freqs[i] >= y) {
				printf(" *");
			} else {
				printf("  ");
			}
		}

		putchar('\n');
	}

	// drawing x-axis and labels
	printf("   +");
	for (int x = 0; x < TOTAL_CHARS; ++x) {
		printf("--");
	}

	printf("\n    ");
	for (int x = 0; x < 10; ++x) {
		printf(" %d", x);
	}

	for (int x = 'A'; x <= 'Z'; ++x) {
		printf(" %c", x);
	}

	for (int x = 'a'; x <= 'z'; ++x) {
		printf(" %c", x);
	}

	printf(" ~\n");

	return 0;
}
