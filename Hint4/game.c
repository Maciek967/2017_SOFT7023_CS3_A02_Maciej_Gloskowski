//------------------------------------
//	Include Libraries 
//------------------------------------
#include "game.h"

//------------------------------------
//	01. FUNCTION create_new_game
//------------------------------------
game* create_new_game(char* p1, char* p2, int connect, int rows, int columns) {
	//1. We create the variable for hosting the game
	game* g = (game*)malloc(1 * sizeof(game));

	//2. We use the names passed as arguments 
	(*g).p1 = (char*)malloc((strlen(p1) + 1) * sizeof(char));
	strcpy((*g).p1, p1);

	(*g).p2 = (char*)malloc((strlen(p2) + 1) * sizeof(char));
	strcpy((*g).p2, p2);

	//3. We set the mode to the one passed by parameter
	int mode = 0;
	if (strcmp(p1, "Computer") == 0)
		mode = mode + 2;
	if (strcmp(p2, "Computer") == 0)
		mode = mode + 1;
	(*g).mode = mode;

	//4. We set the status to be 1; i.e., player1 moves first
	(*g).status = 1;

	//5. We initialise the connect, rows and columns
	(*g).connect = connect;
	(*g).rows = rows;
	(*g).columns = columns;

	//6. We initialise the board to contain all positions empty
	(*g).board = (char**)malloc(rows * sizeof(char*));
	(*g).board[0] = (char*)malloc((rows * columns) * sizeof(char));
	for (int i = 0; i < rows; i++)
		(*g).board[i] = (*g).board[0] + (columns * i);

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			(*g).board[i][j] = ' ';

	//7. We return the game
	return g;
}

//------------------------------------
//	02. FUNCTION display_board 
//------------------------------------
void display_board(game* g) {
	int row;
	int col;
	int i = 0;
	printf("\n\n ****CONNECT 4 GAME****\n");

	for (i = 0; i < (*g).columns; i++)
	{
		printf("  %d ", i + 1);
	}
	printf("\n+");

	for (int j = 0; j < (*g).columns; j++)
	{
		printf("---+");
	}

	for (row = 0; row < (*g).rows; row++)
	{
		printf("\n", row);
		for (col = 0; col < (*g).columns; col++)
		{
			printf("| %c ", (*g).board[row][col]);
			if (col == ((*g).columns - 1))
			{
				printf("|\n");
				printf("+");
				for (i = 0; i < (*g).columns; i++)
				{
					printf("---+");
				}
			}
		}
	}
}

//------------------------------------
//	03. FUNCTION display_game_status 
//------------------------------------
void display_game_status(game* g)
{
	if ((*g).status == 1)
	{
		printf("\n%s, your turn next", (*g).p1);
	}

	else if ((*g).status == 2)
	{
		printf("\n%s, your turn next", (*g).p2);
	}

	else if ((*g).status == 3)
	{
		printf("\n%s, you have won!", (*g).p1);
	}

	else if ((*g).status == 4)
	{
		printf("\n%s, you have won!", (*g).p2);
	}

	else if ((*g).status == 5)
	{
		printf("\nThe game is finished with a draw");
	}
}

//--------------------------------------------------
// 04. FUNCTION my_getchar
//--------------------------------------------------
char my_get_char() {
	//1. We create the variable for hosting the char
	char my_char = ' ';

	//2. We create an extra variable to consume any other characters entered until a return is pressed
	bool line_consumed = False;
	char dummy_char = ' ';

	//3. We consume the first char entered, i.e., the one we are interested at
	my_char = getchar();

	//4. While still there are remaining characters
	while (line_consumed == False) {
		//4.1. We consume the next character
		dummy_char = getchar();

		//4.2. If the new character is the end of line one, we can ensure we have consumed the entire line.
		if (dummy_char == '\n')
			line_consumed = True;
	}

	//5. We return the first character entered by the user, i.e., the one we are interested at
	return my_char;
}

//------------------------------------
//	05. FUNCTION ask_for_column 
//------------------------------------
int ask_for_column(game* g) {
	char in = ' ';
	int x = 0;

	do {
		if ((*g).status == 1)
		{
			printf("\n%s, please enter a column: ", (*g).p1);
		}
		else if ((*g).status == 2)
		{
			printf("\n%s, please enter a column: ", (*g).p2);
		}
		in = my_get_char();
		x = in - '0';
	} 
	while ((x > (*g).columns) || (x < 1) || (in == "\n") || (in == ' '));
	return x;
}

//------------------------------------
//	06. FUNCTION user_movement 
//------------------------------------
void user_movement(game* g, int* r, int* c) {
	*r = -1;
	*c = -1;

	int input = 0;
	char p1 = 'X';
	char p2 = 'O';
	int i = ((*g).rows - 1);
	//int i = 5;

	input = ask_for_column(g);
	while (i >= 0)
	{
		if ((*g).status == 1)
		{
			if ((*g).board[i][input - 1] == ' ')

			{
				((*g).board[i][input - 1]) = p1;
				*r = i;
				*c = input - 1;

				i = -1;
			}
		}

		else if ((*g).status == 2)
		{
			if ((*g).board[i][input - 1] == ' ')
			{
				((*g).board[i][input - 1]) = p2;
				*r = i;
				*c = input - 1;

				i = -1;
			}
		}
		i--;
	}
}

//------------------------------------
//	07. FUNCTION computer_movement 
//------------------------------------
void computer_movement(game* g, int* r, int* c) {
	*r = -1;
	*c = -1;

	int input;
	char p1 = 'X';
	char p2 = 'O';
	int i = ((*g).rows - 1);

	input = rand() % ((*g).columns);

	while (i >= 0)
	{
		if ((*g).status == 1)
		{
			if ((*g).board[i][input] == ' ')
			{
				((*g).board[i][input]) = p1;
				*r = i;
				*c = input;

				i = -1;
			}
		}

		else if ((*g).status == 2)
		{
			if ((*g).board[i][input] == ' ')
			{
				((*g).board[i][input]) = p2;
				*r = i;
				*c = input;

				i = -1;
			}
		}
		i--;
	}
}


//------------------------------------
//	08. FUNCTION new_movement 
//------------------------------------
void new_movement(game* g, int* r, int* c) {
	bool validMovement = False;
	if ((*g).status == 1)
	{
		if ((strcmp((*g).p1, "Computer") == 0))
		{
			while (validMovement == False) {
				computer_movement(g, r, c);
				if ((*r != -1) && (*c != -1))
					validMovement = True;
			}
		}
		else if ((strcmp((*g).p1, "Computer") != 0))
		{
			while (validMovement == False) {
				user_movement(g, r, c);
				if ((*r != -1) && (*c != -1))
					validMovement = True;
			}
		}
	}

	else if ((*g).status == 2)
	{
		if ((strcmp((*g).p2, "Computer") == 0))
		{
			while (validMovement == False) {
				computer_movement(g, r, c);
				if ((*r != -1) && (*c != -1))
					validMovement = True;
			}
		}
		else if ((strcmp((*g).p2, "Computer") != 0))
		{
			while (validMovement == False) {
				user_movement(g, r, c);
				if ((*r != -1) && (*c != -1))
					validMovement = True;
			}
		}
	}
}

//------------------------------------
//	09. FUNCTION winning_row 
//------------------------------------
bool winning_row(game* g, int row, int ply) //horizontal
{
	return False;
}

//------------------------------------
//	10. FUNCTION winning_column 
//------------------------------------
bool winning_column(game* g, int column, int ply) //vertical
{
	int i = 5;
	char p = ' ';
	bool checkColumn = False;

	if ((*g).status == 1)
	{
		p = 'X';
	}

	else if ((*g).status == 2)
	{
		p = 'Y';
	}

	while (i > 1)
	{
		if ((*g).board[i][column - 1] == p)
		{
			if ((*g).board[i - 1][column - 1] == p)
			{
				if ((*g).board[i - 2][column - 1] == p)
				{
					if ((*g).board[i - 3][column - 1] == p)
					{
						checkColumn = True;
					}
				}
			}
		}
		i--;
	}
	return checkColumn;
}

//------------------------------------
//	11. FUNCTION winning_diagonal 
//------------------------------------
bool winning_diagonal(game* g, int diagonal, int ply, bool left)
{
	return False;
}

//------------------------------------
//	12. FUNCTION winning_player 
//------------------------------------
bool winning_player(game* g, int ply)
{
	/*bool finish = False;
	checkCol = winning_column(g, column, ply);
	if (checkCol == True)
	{
	finish = True;
	}
	return finish;*/
	return False;
}

//------------------------------------
//	13. FUNCTION update_status 
//------------------------------------
void update_status(game* g, bool finish, int movs)
{
	//int movs = 0;
	if ((*g).status == 1)
	{
		if (finish == False)
		{
			(*g).status = 2;

			if (movs == (*g).columns * (*g).rows)
			{
				(*g).status = 5;
			}
		}

		else
		{
			(*g).status = 3;
		}
	}

	else if ((*g).status == 2)
	{
		if (finish == False)
		{

			(*g).status = 1;

			if (movs == (*g).columns * (*g).rows)
			{
				(*g).status = 5;
			}
		}

		else
		{
			(*g).status = 4;
		}
	}
}

//------------------------------------
//	14. FUNCTION play_game 
//------------------------------------
//void play_game(char* p1, char* p2)
void play_game(int connect, int rows, int columns, char* p1, char* p2)
{
	//game* mygame = create_new_game(p1, p2);
	game* mygame = create_new_game(p1, p2, connect, rows, columns);

	bool finish = False;
	int pos_x = 0;
	int pos_y = 0;
	int movements = 0;


	//Main loop of the game
	while (finish == False) {
		//1. Display the game status
		display_board(mygame);
		display_game_status(mygame);

		//while ((pos_x != -1) && (pos_y != -1))

		//2. Modifies the status
		//2.1. Ask for a new valid movement 
		new_movement(mygame, &pos_x, &pos_y);
		movements++;

		//2.2. Check if the new movement ends the game
		finish = winning_player(mygame, (*mygame).status, pos_x, pos_y);

		//2.3. Update the status of the game
		update_status(mygame, finish, movements);

		//if (movements == 42)
		if (movements == (*mygame).columns * (*mygame).rows)
		{
			finish = True;
		}
	}

	display_board(mygame);
	display_game_status(mygame);
}
