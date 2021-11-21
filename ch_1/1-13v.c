/*
 * Exercise 1-13: Write a program to print a histogram of the lengths of
 * words in its inputs. It is easy to draw the histogram with the bars
 * horiontal; a vertical orientation is more challenging.
 * 
 * This is the vertical version.
 */

#include <stdio.h>

#define MAX_WORD_LEN 10
#define FREQS_LEN (MAX_WORD_LEN + 1) // length of 'freqs' array

int main(void)
{
	/*
	 * We store the frequencies of lengths of words between 1 and 10
	 * characters in array 'freqs' (indices 0-9). Frequencies of lengths
	 * more than 10 will be stored at the end of the array (index 10).
	 */

	int freqs[FREQS_LEN] = {0};

	// calculating and storing frequencies
	int len = 0, c;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (len > MAX_WORD_LEN) {
				++freqs[MAX_WORD_LEN];
				len = 0;
			} else if (len > 0) {
				++freqs[len - 1];
				len = 0;
			}
		} else {
			++len;
		}
	}

	if (len > MAX_WORD_LEN) {
		++freqs[MAX_WORD_LEN];
	} else if (len > 0) {
		++freqs[len - 1];
	}

	putchar('\n');

	// finding maximum frequency
	int max_freq = 0;
	for (int i = 0; i < FREQS_LEN; ++i) {
		if (freqs[i] > max_freq) {
			max_freq = freqs[i];
		}
	}

	putchar('\n');

	// drawing histogram
	for (int y = max_freq; y > 0; --y) {
		printf("%3d|", y);

		for (int i = 0; i < MAX_WORD_LEN + 1; ++i) {
			if (freqs[i] >= y) {
				printf(" * ");
			} else {
				printf("   ");
			}
		}

		putchar('\n');
	}

	// drawing x-axis & labels
	printf("   +");
	for (int i = 0; i < FREQS_LEN; ++i) {
		printf("---");
	}

	printf("\n    ");
	for (int i = 0; i < MAX_WORD_LEN; ++i) {
		printf("%2d ", i + 1);
	}

	printf(">%2d\n",  MAX_WORD_LEN);

	return 0;
}