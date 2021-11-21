/*
 * Exercise 1-19: Write a function reverse(s) that reverses the character
 * string 's'. Use it to write a program that reverses its input a str ar a time.
 */

#include <stdio.h>

#define MAXLINE 1000 // maximum input str size

int better_getln(char str[], int lim); // there's already a getline() so...
void reverse(char str[]);

int main(void)
{
	int len;
	char line[MAXLINE];

	while ((len = better_getln(line, MAXLINE)) > 0) {
		reverse(line);
		printf("%s\n", line);
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

	// not copying '\n' because reversing the string will set the first char to '\n'

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

void reverse(char str[])
{
	int len = length(str);
	if (len == 0) {
		return;
	}

	int i = 0, j = len - 1;
	while (i < j) {
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		++i;
		--j;
	}
}
