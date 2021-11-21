/*
 * Exercise 1-16: Revise the main routine of the longest-line program so it
 * will correctly print the length of arbitrarily long input lines, and as
 * much as possible of the text.
 */

#include <stdio.h>
#include <string.h>

#define MAXLINE 10 // maximum input line size

int getln(char str[], int lim); // there is already a getline() so...
void copy(char to[], char from[]);

int main(void)
{
	char line[MAXLINE];    // store current line
	char linex[MAXLINE];   // overflow buffer
	char longest[MAXLINE];
	int len;               // length of current line
	int max = 0;

	while ((len = getln(line, MAXLINE)) > 0) {
		if (len == MAXLINE - 1 && line[MAXLINE - 2] != '\n') {
			printf("yes");
			int i, c;
			for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
				if (i < MAXLINE - 1) {
					linex[i] = (char)c;
				}

				++len;
			}

			if (c == '\n') {
				++len;
			}

			if (i >= MAXLINE - 1) {
				linex[MAXLINE - 1] = '\0';
			} else {
				if (c == '\n') {
					linex[i] = '\n';
					++i;
				}

				linex[i] = '\0';
			}
		}

		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}

	if (max > 0) {
		printf("\n%s", longest);

		if (max >= MAXLINE) {
			printf("%s", linex);
		}

		printf("\nLength: %d\n", max);
	}

	return 0;
}

int getln(char str[], int lim)
{
	--lim; // reducing the limit by 1 as last byte will be used for '\0'

	int i, c;
	for (i = 0; i < lim && ((c = getchar()) != EOF && c != '\n'); ++i) {
		str[i] = (char)c;
	}

	if (c == '\n') {
		str[i] = (char)c;
		++i;
	}

	str[i] = '\0';
	return i;
}

void copy(char to[], char from[])
{
	int i = 0;

	while ((to[i] = from[i]) != '\0') {
		++i;
	}
}