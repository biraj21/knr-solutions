/*
 * Exercise 1-20: Write a program detab that replaces tabs in the input with
 * proper number of blanks to space to the next tab stop. Assume a fixed set
 * of tab stops, say every every n columns. Should n be a variable or a
 * symbolic parameter?
 */

#include <stdio.h>

#define TABSTOP 4

int main(void)
{
	printf("Tab Stop: %d\n", TABSTOP);

	int c;
	int i = 0; // index of char within tabstop

	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			putchar('\n');
			i = 0;
		} else if (c == '\t') {
			while (i < TABSTOP) {
				putchar(' ');
				++i;
			}

			i = 0;
		} else {
			putchar(c);
			i = (i + 1) % TABSTOP;
		}
	}

	return 0;
}
