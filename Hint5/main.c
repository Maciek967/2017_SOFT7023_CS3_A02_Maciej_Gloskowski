
//------------------------------------
//	Define 
//------------------------------------
#define _CRT_SECURE_NO_WARNINGS

//------------------------------------
//	Include Libraries 
//------------------------------------
#include <time.h>
#include "game.h"
#include <string.h>

//------------------------------------
//	FUNCTION main 
//------------------------------------
int main(int argc, char* argv[]) {
	//1. We set the seed for generating random numbers (in case the "Computer" acts as one of the players)
	//srand((unsigned int) time(NULL));

	//2. We parse the input arguments to the program
	//2.1. The first argument represents the amount of figures to be placed consecutively so as to win the game
	//int connect = atoi(argv[1]);

	//2.2. The second argument is the rows of the board
	//int rows = atoi(argv[2]);

	//2.3. The third argument is the columns of the board
	//int columns = atoi(argv[3]);

	//2.4. The fourth argument is the name of the first player
	//char* p1 = (char*)malloc(strlen(argv[4]) + 1 * sizeof(char));
	//strcpy(p1, argv[4]);

	//2.5. The fifth argument is the name of the second player
	//char* p2 = (char*)malloc(strlen(argv[5]) + 1 * sizeof(char));
	//strcpy(p2, argv[5]);

	//3. We call to the main function of the game
	play_game(3, 2, 3, "P1", "Computer");

	//4. We finish the application returning 0
	return 0;
}



