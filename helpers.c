/******************************************************************************
** Student name: 	Scott Djuric
** Student number: 	s3600531
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "helpers.h"

void readRestOfLine()
{
    int ch;
    while(ch = getc(stdin), ch != EOF && ch != '\n')
    { } /* Gobble each character. */

    /* Reset the error status of the stream. */
    clearerr(stdin);
}

char * validateInput()
{
    char input[20 + EXTRA_SPACES];
	char *end = malloc(strlen(input) + EXTRA_SPACES);

	
	fgets(input,20+EXTRA_SPACES,stdin);
	
	if(input[strlen(input)-1] != '\n')
	{
		readRestOfLine();
	}
	
	input[strlen(input) - 1] = 0;
	input[strcspn(input, "\n")] = '\0';
	strcpy(end, input);
	
	return end;
}



