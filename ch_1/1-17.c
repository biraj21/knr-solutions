/*
 * Exercise 1-17: Write a program to print all input lines that are longer than
 * 80 characters.
 */

#include <stdio.h>

#define LONGER_THAN 80  // print a line if it's more then this
#define MAXLINE 1000    // maximum input line size

int better_getln(char str[], int lim); // there is already a getline() so...

int main(void)
{
	int len;
	char line[MAXLINE];

	while ((len = better_getln(line, MAXLINE)) > 0) {
		if (len > LONGER_THAN) {
			printf("%s\n", line);
		}
	}

	return 0;
}

int better_getln(char str[], int lim)
{
	--lim; // reducing the limit by 1 as last byte will be used for '\0'

	int i, c, len = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (len < lim) {
			++len;
			str[i] = c;
		}
	}

	if (c == '\n') {
		++i;
		if (len < lim) {
			str[len] = '\n';
			++len;
		}
	}

	str[len] = '\0';
	return i;
}