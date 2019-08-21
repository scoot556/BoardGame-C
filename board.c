/******************************************************************************
** Student name: 	Scott Djuric
** Student number: 	s3600531
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "board.h"

Cell BOARD_1[BOARD_HEIGHT][BOARD_WIDTH] =
{
    { BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED }
};

Cell BOARD_2[BOARD_HEIGHT][BOARD_WIDTH] =
{
    { BLOCKED, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};

void initialiseBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH])
{
	int h,w;
	/* Creating a loop to initialise the height and width */
	for (h = 0; h < BOARD_HEIGHT; h++)
	{
		for (w = 0; w < BOARD_WIDTH; w++)
		{
			/* Sets the board empty */
			board[h][w] = EMPTY;
		}
	}
}

void loadBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH],
               Cell boardToLoad[BOARD_HEIGHT][BOARD_WIDTH])
{
	int h,w;
	
	for (h = 0; h < BOARD_HEIGHT; h++)
	{
		for (w = 0; w < BOARD_WIDTH; w++)
		{
			board[h][w] = boardToLoad[h][w];
		}
	}
}

Boolean placePlayer(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Position position)
{
	if (board[position.x][position.y] == EMPTY)
	{
		board[position.x][position.y] = PLAYER;
		return TRUE;
	}
	return FALSE;
}

PlayerMove movePlayerForward(Cell board[BOARD_HEIGHT][BOARD_WIDTH],
                             Player * player)
{
	Position position = getNextForwardPosition(player);
	
	if(board[position.x][position.y] == BLOCKED)
	{
		printf("\n Unable to move - cell is blocked.\n");
		
		return CELL_BLOCKED;
	}
	
	else if(position.x < 0 || position.y < 0 || position.x > 9 || position.y > 9)
	{
		printf("\n Unable to move - outside bounds.\n");
		
		return OUTSIDE_BOUNDS;
	}
	
	else
	{
		board[player->position.x][player->position.y] = EMPTY;
		updatePosition(player, position);
		board[player->position.x][player->position.y] = PLAYER;
		printf("\n Player moved.\n");
		return PLAYER_MOVED;
	}		
}

void displayBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Player * player)
{
	int h,w;
	
	for (h=0; h <= BOARD_HEIGHT; h++)
	{
		if (h == 0)
		{
			printf("| ");
		}
		else if (h == BOARD_HEIGHT)
		{
			printf("|%d", h-1);
		}
		else
		{
			printf("|%d", h-1);
		}
		
		for (w=0; w < BOARD_WIDTH; w++)
		{
			if (h == 0)
			{
				printf("|%d", w);
			}
			else 
				{
					printf("|");
					
					if (board[h-1][w] == EMPTY)
					{
						printf("%s", EMPTY_OUTPUT);
					}
					else if (board[h-1][w] == BLOCKED)
					{
						printf("%s", BLOCKED_OUTPUT);
					}
					else if(board[h-1][w] == PLAYER)
					{
						displayDirection(player->direction);
					}
				}
		}
		printf("|\n");
	}
}
