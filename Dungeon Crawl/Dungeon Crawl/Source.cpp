#include <iostream>
#include <time.h>
#include <conio.h>

enum class moveset { up, left, down, right, standbye }player;
struct cods {
	int x;
	int y;
}playercods, finish, trap[5], enemy[5];

char board[10][20];

void printboard() {

	//Initialize the board with correct values (this will deny ghosting)
	for (int y = 0; y < 10; y++)
		for (int x = 0; x < 20; x++)
			board[y][x] = '.';

	//Inserts entities
	board[playercods.y][playercods.x] = 'G';
	for (int i = 0; i < 5; i++){
		board[trap[i].y][trap[i].x] = 'T';
		board[enemy[i].y][enemy[i].x] = 'E';
	}
	board[finish.y][finish.x] = 'X';
	//Prints board
	for (int y = 0; y < 10; y++){
		for (int x = 0; x < 20; x++)
			std::cout << board[y][x];
		std::cout << "\n";
	}
	
	//Fake refresh
	std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << std::endl;
}

bool traps() {
	for (int i = 0; i < 5; i++)
		if (trap[i].y == playercods.y &&trap[i].x == playercods.x)
			return true;
	return false;
}

void user_input() {

	//Gets player input
	do{
		char key = _getch();
		switch (key) {
		case 'w':
			player = moveset::up;
			playercods.y--;
			break;
		case 'a':
			player = moveset::left;
			playercods.x--;
			break;
		case 's':
			player = moveset::down;
			playercods.y++;
			break;
		case 'd':
			player = moveset::right;
			playercods.x++;
			break;
		default:
			player = moveset::standbye;
		}
	} while (player == moveset::standbye);
}

bool detectwin() {
	if (finish.y == playercods.y && finish.x == playercods.x)
		return true;
	else
		return false;
}

bool enemies() {

	//Control loop
	for (int i = 0; i < 5; i++)
		if (enemy[i].y == playercods.y && enemy[i].x == playercods.x)
			return true;
	
	//Makes enemies move
	for (int i = 0; i < 5; i++) {
	int dir = rand() % 4;
		if (dir == 0)
			enemy[i].x--;
		else if (dir == 1)
			enemy[i].x++;
		else if (dir == 2)
			enemy[i].y--;
		else if (dir == 3)
			enemy[i].y++;
	}

	//Control loop
	for (int i = 0; i < 5; i++) 
		if (enemy[i].y == playercods.y && enemy[i].x == playercods.x)
			return true;
		
			return false;
}

int main(){
	//Initialize placement of entities
		//Player
	playercods.y = 2;
	playercods.x = 2;
	
		//Traps
	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		trap[i].y = rand() % 6 + 3;
		trap[i].x = rand() % 16 + 3;
	}

		//Enemies
	for (int i = 0; i < 5; i++) {
		enemy[i].y = rand() % 6 + 3;
		enemy[i].x = rand() % 16 + 3;
	}
		
		//Finish
	finish.y = 8;
	finish.x = 17;

	//Game loop
	while (detectwin != false){
	printboard();	
	if (traps() == true || enemies() == true || detectwin() == true)
		break;
	user_input();
	}
	
	printboard();
	if (traps() == true ||enemies() == true)
		std::cout << "\n\n You died!\n";
	else
		std::cout << "\n\n You won!\n";
	return 0;
}

