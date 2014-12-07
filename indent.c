// indent.c
#include <stdio.h>

void main (void)
{
	int after_precompiler = 0, ch;
	int previous_char1 = 0;
	int previous_char2 = 0;
	int previous_char3 = 0;
	int previous_char4 = 0;
	int previous_char5 = 0;
	int chartoprint = 0;
	int open_braces = 0;
	int open_parenthesis = 0;
	
	ch = getchar();
	
	while (ch != EOF)
	{
		if (after_precompiler == 0) // if the commands are for the precompiler
		{	//if we encounter the word "main" 
			if (previous_char4 == '\n' && previous_char3 == 'm' && previous_char2== 'a' && previous_char1 == 'i' && ch == 'n')
			{
				after_precompiler = 1; // flag that the commands are after main()
				putchar(previous_char4);
				putchar(previous_char3);
				putchar(previous_char2);
				putchar(previous_char1);
				putchar(ch); // all the above makes it print the word "main"
				previous_char1 = ch;
				ch = getchar();
			}
			else
			{
				if (chartoprint != 0)			
					putchar(chartoprint);
				
				//read 5 characters ahead (to catch the word "main")
				chartoprint = previous_char4;
				previous_char4 = previous_char3;
				previous_char3 = previous_char2;
				previous_char2 = previous_char1;
				previous_char1 = ch;
			}
		}
	
		if (after_precompiler == 1) // commands after main
		{
			if (ch == '(')
			{
				open_parenthesis += 1; // counts how many parenthesis are open (increase)
			}
			
			if (ch == ')')
			{
				open_parenthesis -= 1; // counts how many parenthesis are open (decrease)
			}
			
			//avoid multiple whitespaces, multiple changes of line and multiple tabs or combination of them
			if ((ch == ' ' || ch == '\t') && previous_char1 != ' ' && previous_char1 != '\t' && previous_char1 != '\n'  && previous_char1 != ';')
			{
				putchar(ch);
			}
			//as above but also, if the character is \n, do not change line if inside parentheses.
			if (ch == '\n' && previous_char1 != ' ' && previous_char1 != '\t' && previous_char1 != '\n'  && previous_char1 != ';' && open_parenthesis == 0)
			{
				putchar(ch);
			}
			
			if (ch == ';' && open_parenthesis == 0)
			{
				putchar(ch);
				putchar('\n');	
				
				if (open_braces > 0)
				{
					int i;
					for (i=1; i<= open_braces; i++) // print as many tabs as the amount of open braces
					{
						putchar('\t');
					}
				}
			}
			
			else if (ch == ';' && open_parenthesis > 0) // treat ';' as any other character if inside parentheses, i.e. do not change line
			{
				putchar(ch);
			}
			if (ch == '{')
			{
				putchar('\n');
				putchar(ch);
				putchar('\n');
				putchar('\t');
				open_braces += 1; // counts the number of open braces
			}
			if (ch == '}')
			{
				putchar('\n');
				putchar(ch);
				putchar('\n');
				open_braces -= 1; // counts the number of open braces (decrease)
			}
			// if the character is not any of "special" characters mentioned above, then just print it normally
			if (ch != ';' && ch != '{' && ch != '}' && ch != '\n' && ch != ' ' && ch != '\t')
			{
				putchar(ch);
			}
		}
		previous_char1 = ch; // remember the previous character, to be able to reject multiple spaces, multiple tabs etc.
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

