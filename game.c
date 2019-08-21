/******************************************************************************
** Student name: 	Scott Djuric
** Student number: 	s3600531
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "game.h"

void playGame()
{
	int i = 0;
	Cell board[BOARD_HEIGHT][BOARD_WIDTH];
		char *choice;
		char *pEnd;
		char *strTok;
		
		int posx;
		int posy;
		
		Direction *direction;
		Position *position;
		Player *player;
		Player player2;
		Position position2;
		Direction direction2;
		position = &position2;
		player = &player2;
		direction = &direction2;

		initialiseBoard(board);
		displayBoard(board, NULL);	

		instructMenu();
	while (i != 1)
	{
		
	
		choice = validateInput();
		
		if (strcmp(choice, COMMAND_LOAD" 1") ==0)
			{			
				loadBoard(board, BOARD_1);
				displayBoard(board, NULL);
				initMenu();				
			}
		else if (strcmp(choice, COMMAND_LOAD" 2") ==0)
			{
				loadBoard(board, BOARD_2);
				displayBoard(board, NULL);
				initMenu();
			}
		else if (strcmp(choice, COMMAND_QUIT) ==0)
			{
				return;
			}

		else if((strTok = strtok(choice," ")) && strcmp(strTok, COMMAND_INIT) == 0){
			strTok = NULL;
			
			if((strTok = strtok(strTok,",")) != NULL){
				posx = (int) strtol(strTok, &pEnd, 20);
				if(posx >= 0 && posx <= 9){
					strTok = NULL;
					position2.x = posx;
					
					if((strTok = strtok(strTok,",")) != NULL){
						posy = (int) strtol(strTok, &pEnd, 20);
						if(posy >= 0 && posy <= 9){
							strTok = NULL;
							
							position2.y = posy;
							if((strTok = strtok(strTok,",")) != NULL){
								if(strcmp(strTok, DIRECTION_NORTH) == 0 && placePlayer(board, position2) == TRUE){
									*direction = NORTH;
									placePlayer(board, position2);
									initialisePlayer(player, position, *direction);
									printf("\n");
									displayBoard(board, player);
									playMenu();
									playerGame(player, board);
								}
								else if(strcmp(strTok, DIRECTION_EAST) == 0 && placePlayer(board, position2) == TRUE){
									*direction = EAST;
									placePlayer(board, position2);
									initialisePlayer(player, position, *direction);
									printf("\n");
									displayBoard(board, player);
									playMenu();
									playerGame(player, board);
								}
								else if(strcmp(strTok, DIRECTION_SOUTH) == 0 && placePlayer(board, position2) == TRUE){
									*direction = SOUTH;
									placePlayer(board, position2);
									initialisePlayer(player, position, *direction);
									printf("\n");
									displayBoard(board, player);
									playMenu();
									playerGame(player, board);
								}
								else if(strcmp(strTok, DIRECTION_WEST) == 0 && placePlayer(board, position2) == TRUE){
									*direction = WEST;
									placePlayer(board, position2);
									initialisePlayer(player, position, *direction);
									printf("\n");
									displayBoard(board, player);
									playMenu();
									playerGame(player, board);
								}
								else if((strcmp(strTok, DIRECTION_NORTH) == 0 || strcmp(strTok, DIRECTION_EAST) == 0 || strcmp(strTok, DIRECTION_SOUTH) == 0 || strcmp(strTok, DIRECTION_WEST) == 0) && placePlayer(board, position2) == FALSE)
								{
									printf("\nUnable to place player at that position.\n\n");	
									displayBoard(board, NULL);
									initMenu();
								}	
								else if(strcmp(strTok, DIRECTION_NORTH) != 0 || strcmp(strTok, DIRECTION_EAST) != 0 || strcmp(strTok, DIRECTION_SOUTH) != 0 || strcmp(strTok, DIRECTION_WEST) != 0){
									invalidInput(board);
									initMenu();
								}
								else {
								invalidInput(board);
							}
							}
							else {
								invalidInput(board);
							}
						}
						else {
							invalidInput(board);
						}
					}
					else {
						invalidInput(board);
					}
				}
				else {
					invalidInput(board);
				}
			}
			else {
				invalidInput(board);
			}
		}		
		else
			{
				displayBoard(board, NULL);
				instructMenu();
			}
	}
}

void instructMenu()
{
	printf("\nAt this stage of the program, only three commands are acceptable:\n");
	printf("load <g>\n");
	printf("quit\n\n");
}

void initMenu()
{
	printf("\nAt this stage of the program, only three commands are acceptable:\n");
	printf("load <g>\n");
	printf("init <x>,<y>,<direction>\n");
	printf("quit\n\n");
}

void playMenu()
{
	printf("At this stage of the program, only three commands are acceptable:\n");
	printf("forward\n");
    printf("turn_left (or l)\n");
    printf("turn_right (or r)\n");
    printf("quit\n\n");
}

void playerGame(Player *player, Cell board[BOARD_HEIGHT][BOARD_WIDTH])
{
	int i = 0;
	while(i != 1)
	{
		char *choice;
		   
		choice = validateInput();
			if (strcmp(choice, COMMAND_TURN_LEFT_SHORTCUT) == 0 || strcmp(choice, COMMAND_TURN_LEFT) == 0) {
				turnDirection(player, TURN_LEFT);
				printf("\n");
				displayBoard(board, player);
				playMenu();
				player->moves ++;
			}
			else if (strcmp(choice, COMMAND_TURN_RIGHT_SHORTCUT) == 0 || strcmp(choice, COMMAND_TURN_RIGHT) == 0) {
				turnDirection(player, TURN_RIGHT);
				printf("\n");
				displayBoard(board, player);
				playMenu();
				player->moves ++;
			}
			else if (strcmp(choice, COMMAND_FORWARD) == 0 || strcmp(choice, COMMAND_FORWARD_SHORTCUT) == 0){
				movePlayerForward(board, player);
				printf("\n");
				displayBoard(board, player);
				playMenu();
				player->moves ++;
			}
			else if (strcmp(choice, COMMAND_QUIT) == 0) {
				printf("\n");
				printf("Total player moves: ");
				printf("%i\n\n", player->moves);
				return;
			}
			else {
				printf("\n");
				printf("Invalid input\n\n");
				displayBoard(board,player);
				playMenu();
			}
    }
}

void invalidInput(Cell board[BOARD_HEIGHT][BOARD_WIDTH])
{
	printf("\n");
    printf("Invalid input.\n\n");
	displayBoard(board, NULL);
	initMenu();
}
