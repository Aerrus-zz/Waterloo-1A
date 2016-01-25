#include <stdio.h>
#include <string.h>

int rpsls(const char *player1, const char *player2)
{
	int list[5][5] = {
		{0, -1, 1, 1, -1},
		{1, 0, -1, -1, 1},
		{-1, 1, 0, 1, -1},
		{-1, 1, -1, 0, 1},
		{1, -1, 1, -1, 0}
	};
	
	if(player1 == NULL || player2 == NULL)
	{
		return 0;
	}
	
	int m1;
	int m2;
	
	if(strcmp(player1, "rock") == 0) {m1 = 0;}
	else if(strcmp(player1, "paper") == 0) {m1 = 1;}
	else if(strcmp(player1, "scissors") == 0) {m1 = 2;}
	else if(strcmp(player1, "lizard") == 0) {m1 = 3;}
	else if(strcmp(player1, "Spock") == 0) {m1 = 4;}
	else {return 0;}
	
	if(strcmp(player2, "rock") == 0) {m2 = 0;}
	else if(strcmp(player2, "paper") == 0) {m2 = 1;}
	else if(strcmp(player2, "scissors") == 0) {m2 = 2;}
	else if(strcmp(player2, "lizard") == 0) {m2 = 3;}
	else if(strcmp(player2, "Spock") == 0) {m2 = 4;}
	else {return 0;}
	
	return list[m1][m2];
}