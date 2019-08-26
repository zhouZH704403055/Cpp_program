#include <stdio.h>
int main() {
	char c;
	while ((c = getchar()) != EOF)
	{
		if ('A' <= c && 'Z' >= c) 
		{
			c = (c > 'E') ? (c - 5) : (c + 21);
		} 
		putchar(c);
	} 
	return 0;
}