/*
 * Exercise 1-13: Write a program to print a histogram of the lengths of
 * words in its inputs. It is easy to draw the histogram with the bars
 * horiontal; a vertical orientation is more challenging.
 * 
 * This is the horizontal version.
 */

#include <stdio.h>

#define MAX_WORD_LEN 10

int main(void)
{
	/*
	 * We store the frequencies of lengths of words between 1 and 10
	 * characters in array 'freqs' (indices 0-9). Frequencies of lengths
	 * more than 10 will be stored in variable 'freq_overflow'.
	 */

	int freqs[MAX_WORD_LEN] = {0};
	int freq_overflow = 0;

	// calculating and storing frequencies
	int len = 0, c;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (len > MAX_WORD_LEN) {
				++freq_overflow;
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
		++freq_overflow;
	} else if (len > 0) {
		++freqs[len - 1];
	}

	putchar('\n');

	// drawing histogram
	printf(">%2d| ", MAX_WORD_LEN);
	for (int i = 0; i < freq_overflow; ++i) {
		putchar('*');
	}

	putchar('\n');

	for (int i = MAX_WORD_LEN - 1; i >= 0; --i) {
		printf(" %2d| ", i + 1);
		for (int j = 0; j < freqs[i]; ++j) {
			putchar('*');
		}

		putchar('\n');
	}

	return 0;
}