/*
 * Exercise 1-21: Write a program entab that replaces strings of blanks by
 * the minimum number of tabs and blanks to achieve the same spacing. Use
 * the same tab stops as for detab. When either a tab or single blank would
 * suffice to reach a tab stop, which should be given preference?
 *
 * When either a tab or single blank would suffice to reach a tab stop,
 * this program will use a space, not tab.
 *
 * Examples:
 * . is used to show a space
 * | is used to show tab stops in output
 * - is used to show show distance (if any) between last char & next tab stop
 *
 * Tab Stop = 3          Tab Stop = 4    Tab Stop = 8
 * In:  a...
 * Out: |a\t|.--|     |a\t|           |a...----|
 *
 * In:  ...a
 * Out: |\t|a--|      |...a|          |...a----|
 *
 * In:  .....
 * Out: |\t|..-|      |\t|.---|       |.....---|
 *
 * In:  ab\tcde
 * Out: |ab\t|cde|    |ab\t|cde-|     |ab\t|cde-----|
 *
 * In:  ab.d.\t...
 * Out: |ab.|d\t|\t|  |ab.d|\t|...-|  |ab.d\t|...-----|
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
			int spaces = 1; // number of spaces within current tab stop
			while  ((i + spaces) < TABSTOP && (c = getchar()) == ' ')  {
				++spaces;
			}

			if (c == '\t') {
				putchar('\t');
			} else if (i + spaces == TABSTOP) {
				if (spaces > 1) {
					putchar('\t');
				} else {
					putchar(' ');
				}
			} else {
				while (spaces > 0) {
					putchar(' ');
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
