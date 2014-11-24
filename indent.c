// indent.c
#include <stdio.h>

void main (void)
{
	int ch;
	ch = getchar();	
	while (ch!= EOF)		// Do while is not end of file
	{
		if (ch!=';' && ch!='{' && ch!='}')
		{
			putchar(ch);
		}
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
		ch = getchar(); 
	}	
}
