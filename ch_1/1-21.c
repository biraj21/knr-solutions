/*
 * Exercise 1-21: Write a program entab that replaces strings of blanks by
 * the minimum number of tabs and blanks to achieve the same spacing. Use
 * the same tab stops as for detab. When either a tab or single blank would
 * suffice to reach a tab stop, which should be given preference?
 */

#include <stdio.h>

#define TABSTOP 4

int main(void)
{
	printf("Tab stop: %d\n", TABSTOP);

	int c;
	int i = 0; // index of char within tabstop

	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			putchar('\n');
			i = 0;
		} else if (c == ' ') {
			int spaces = 1; // number of spaces after within current tab stop
			while  ((i + spaces) < TABSTOP && (c = getchar()) == ' ')  {
				++spaces;
			}

			if ((spaces > 1 && i + spaces == TABSTOP) || c == '\t') {
				putchar('#');
			} else {
				while (spaces > 0) {
					putchar('.');
					--spaces;
				}

				if (c != EOF) {
					putchar(c);
				}
			}

			i = 0;
		} else {
			putchar(c);
			i = (i + 1) % TABSTOP;
		}
	}

	return 0;
}
