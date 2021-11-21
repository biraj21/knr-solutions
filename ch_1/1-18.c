/*
 * Exercise 1-18: Write a program to remove trailing blanks and tabs from
 * each line of input, and to delete entirely blank lines.
 */

#include <stdio.h>

#define MAXLINE 1000 // maximum input line size

int better_getln(char str[], int lim); // there's already a getline() so...
void rtrim(char str[]);         // removes trailing blanks, tabs and newline chars

int main(void)
{
	int len;
	char line[MAXLINE];

	while ((len = better_getln(line, MAXLINE)) > 0) {
		rtrim(line);
		printf("|%s|\n", line);
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

int length(char str[])
{
	int len = 0;
	while (str[len] != '\0') {
		++len;
	}

	return len;
}

void rtrim(char str[])
{
	int len = length(str);
	if (len == 0) {
		return;
	}

	while (len > 1 && (str[len - 1] == '\n' || str[len - 1] == ' ' || str[len - 1] == '\t')) {
		--len;
	}

	str[len] = '\0';
}
