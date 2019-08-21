/******************************************************************************
** Student name: 	Scott Djuric
** Student number: 	s3600531
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "player.h"

void initialisePlayer(Player * player, Position * position, Direction direction)
{
	player->position.x = position->x;
	player->position.y = position->y;
	player->direction = direction;
	player->moves = 0;
}

void turnDirection(Player * player, TurnDirection turnDirection)
{
	if(turnDirection == TURN_LEFT)
	{
		if(player->direction == NORTH){
			player->direction = WEST;
		}
		else if(player->direction == WEST){
			player->direction = SOUTH;
		}
		else if(player->direction == SOUTH){
			player->direction = EAST;
		}
		else if(player->direction == EAST){
			player->direction = NORTH;
		}
	}
	if(turnDirection == TURN_RIGHT)
	{
		if(player->direction == NORTH){
			player->direction = EAST;
		}
		else if(player->direction == EAST){
			player->direction = SOUTH;
		}
		else if(player->direction == SOUTH){
			player->direction = WEST;
		}
		else if(player->direction == WEST){
			player->direction = NORTH;
		}
	}
}

Position getNextForwardPosition(const Player * player)
{
    Position position;
	
	if(player->direction == NORTH){
		position = player->position;
		position.x --;
	}
	
	else if(player->direction == EAST){
		position = player->position;
		position.y ++;
	}
	
	else if(player->direction == SOUTH){
		position = player->position;
		position.x ++;
	}
	
	else if(player->direction == WEST){
		position = player->position;
		position.y --;
	}
	
    return position;
}

void updatePosition(Player * player, Position position)
{
	player->position = position;
}

void displayDirection(Direction direction)
{
	if (direction == NORTH)
	{
		printf("%s", DIRECTION_ARROW_OUTPUT_NORTH);
	}

	if (direction == EAST)
	{
		printf("%s", DIRECTION_ARROW_OUTPUT_EAST);
	}
	
	if (direction == SOUTH)
	{
		printf("%s", DIRECTION_ARROW_OUTPUT_SOUTH);
	}
	
	if (direction == WEST)
	{
		printf("%s", DIRECTION_ARROW_OUTPUT_WEST);
	}
}