// indent.c
#include <stdio.h>

void main (void)
{
	int ch;		
	while (ch = getchar() != EOF)		// Do while is not end of file
	{
		if (ch == ';')
		{
			putchar(ch);
			putchar('\n');
			
		}	
		if (ch == '{')
		{
			putchar('\n');
			putchar(ch);
			putchar('\n');
			putchar('\t');	
		}
		if (ch == '}')
		{
			putchar('\n');
			putchar(ch);
			putchar('\n');
		}
	}	
}
