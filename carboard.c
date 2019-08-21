/******************************************************************************
** Student name: 	Scott Djuric
** Student number: 	s3600531
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "carboard.h"

int main()
{
	char choice;
	
	while ( choice != '1' || '2' || '3')
		{
			printf("\nWelcome to Car Board\n");
			printf("--------------------\n");
			printf("1. Play game\n");
			printf("2. Show student's information\n");
			printf("3. Quit\n\n");
			printf("Please enter your choice: ");
			
			fgets(&choice,1+EXTRA_SPACES,stdin);			
			
			switch(choice)
			{
				case '1':
					showPlayInstruct();
					playGame();
					break;
					
				case '2':
					printf("\n");
					showStudentInformation();
					break;
					
				case '3':
					printf("\nGood bye! \n\n");
					return EXIT_SUCCESS;
					
				default:
					printf("\nInvalid Input. \n");
					break;
			}
		}
		return EXIT_SUCCESS;
}

void showStudentInformation()
{
	printf("-------------------------------------------\n");
	printf("Name:"STUDENT_NAME"\n");
	printf("No: "STUDENT_ID"\n");
	printf("Email:"STUDENT_EMAIL"\n");
	printf("-------------------------------------------\n");
	printf("\n\n");
	
}

void showPlayInstruct()
{
	printf("\nYou can use the following commands to play the game: \nload <g>\n\tg: number of the game board to load\ninit <x>,<y>,<direction>\n");
	printf("\tx: horizontal position of the car on the board (between 0 & 9)\n\ty: vertical position of the car on the board (between 0 & 9\n\tdirection: direction of the car's movement (north, east, south, west)\n");
	printf("forward (or f)\nturn_left (or l)\nturn_right (or r)\nquit\n\n");
	
	printf("Press enter to continue...");
	getchar();
	printf("\n\n");
}
