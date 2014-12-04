// indent.c
#include <stdio.h>

void main (void)
{
	int after_precompiler = 0, ch;	// after_precompiler is inactive, means there are the commands for the precompiler
	int previous_char1 = 0;
	int previous_char2 = 0;
	int previous_char3 = 0;
	int previous_char4 = 0;
	int previous_char5 = 0;
	int chartoprint = 0;
	int opened_braces = 0;
	int closed_braces = 0;
	
	while (ch != EOF)
	{
		ch = getchar();
		if (after_precompiler == 0) // if the commands are for the precompiler
		{
			chartoprint = previous_char5;
			previous_char5 = previous_char4;
			previous_char4 = previous_char3;
			previous_char3 = previous_char2;
			previous_char2 = previous_char1;
			previous_char1 = ch;
		
			if (previous_char5 == '\n' && previous_char4 == 'm' && previous_char3 == 'a' && previous_char2 == 'i' && previous_char1 == 'n') 
			{
				after_precompiler = 1;
				putchar(previous_char5);
				putchar(previous_char4);
				putchar(previous_char3);
				putchar(previous_char2);
				putchar(previous_char1);			
			}
			else
				putchar(chartoprint);
		}
		
		if (after_precompiler == 1) // commands after main
		{
			previous_char2 = previous_char1;
			previous_char1 = ch;
			
			if((ch == ' ' || ch == '\t' || ch == '\n') && previous_char1 != ' ' && previous_char1 != '\t' && previous_char1 != '\n'  && previous_char1 != ';')
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
				opened_braces += 1;
			}
			if (ch == '}')
			{
				putchar('\n');
				putchar(ch);
				putchar('\n');
				opened_braces -= 1;
			}
		}
		if (opened_braces > 0)
		{
			int i;
			for (i=1; i<= opened_braces; i++)
			{
				putchar('\t');
			}
			putchar(ch);
		}
		ch = getchar();
			
	}
}

	
	
	
	
	
	
	
	
	
	
	
	
	/*int ch, isquote = 0, ischar = 0, open_parenthesis = 0, close_parenthesis = 0, previousch = 0,   
	ch = getchar();	
	if ()
	while (ch!= EOF)		// Do while is not end of file
	{
		if (ch == '\n' && previousch == '\n')
		{
			putchar(' ');
		}
		if ( ch =='(')
		{
			open_parenthesis += 1; // counts how many parenthesis have open
		}
		if (ch == ')')
		{
			close_parenthesis += 1; // counts how many parenthesis have close
		}
		if ( ch == '\n' && close_parenthesis == open_parenthesis && previousch != '\n')
		{
			putchar(ch);
		}
		if (ch == '\'') 
		{
			if (isquote == 0)
			{
				isquote = 1;
			}
			else
			{
				isquote = 0;
			}
		}
		if (ch == '\\')
		{
			ischar = 1;
		}
		if (ch != ';' && ch != '{' && ch != '}' && ch != '\n')
		{
			putchar(ch);
		}
		if (ch == ';' && isquote == 0 && ischar == 0)
		{
			putchar(ch);
			putchar('\n');
			
		}	
		if (ch == '{')
		{
			if (isquote == 0 && ischar == 0)
			{
				putchar('\n');
			}
			putchar(ch);
			putchar('\n');
			putchar('\t');			
		}
		if (ch == '}'  && isquote == 0 && ischar == 0)
		{
			putchar('\n');
			putchar(ch);
			putchar('\n');
		}
		if (ischar = 1)
		{
			ischar = 0;
		}
		previousch = ch;
		ch = getchar(); 
	}*/	

