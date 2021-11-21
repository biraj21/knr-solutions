/*
 * Exercise 1-12: Write a progam that prints its input one word per line.
 */

#include <stdbool.h>
#include <stdio.h>

int main(void)
{
	int in_new_line = true; // to print a '\n' only if we found a word
	int c;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (!in_new_line) {
				putchar('\n');
				in_new_line = true;
			}
		} else {
			putchar(c);
			in_new_line = false;
		}
	}

	if (!in_new_line) {
		putchar('\n');
	}

	return 0;
}