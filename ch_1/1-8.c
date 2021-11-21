/*
 * Exercise 1-8: Write a program to count blanks, tabs, and newlines.
 */

#include <stdio.h>

int main(void)
{
	int blanks = 0, tabs = 0, newlines = 0;
	int c;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			++blanks;
		} else if (c == '\t') {
			++tabs;
		} else if (c == '\n') {
			++newlines;
		}
	}

	printf("Blanks = %d\n", blanks);
	printf("Tabs = %d\n", tabs);
	printf("Newlines = %d\n", newlines);

	return 0;
}