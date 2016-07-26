#include <iostream>
#include <time.h>
#include <conio.h>

enum class moveset { up, left, down, right, standbye }player;
struct cods {
	int x;
	int y;
}playercods, trap[5];

char board[10][20];

void printboard() {
	//Clears console (allows refresh)

	//Initialize the board with correct values (this will deny ghosting)
	for (int y = 0; y < 10; y++)
		for (int x = 0; x < 20; x++)
			board[y][x] = '.';

	//Inserts entities
	board[playercods.y][playercods.x] = 'G';
	for (int i = 0; i < 5; i++)
		board[trap[i].y][trap[i].x] = 'T';

	//Prints board
	for (int y = 0; y < 10; y++){
		for (int x = 0; x < 20; x++)
			std::cout << board[y][x];
		std::cout << "\n";
	}
	std::cout << std::endl;
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
			playercods.y -= 1;
			break;
		case 'a':
			player = moveset::left;
			playercods.x -= 1;
			break;
		case 's':
			player = moveset::down;
			playercods.y += 1;
			break;
		case 'd':
			player = moveset::right;
			playercods.x += 1;
			break;
		default:
			player = moveset::standbye;
		}
	} while (player == moveset::standbye);
}

bool detectwin() {

	return false;
}

int main(){
	//Initialize placement of entities
	playercods.y = 2;
	playercods.x = 2;
		srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		trap[i].y = rand() % 6 + 3;
		trap[i].x = rand() % 16 + 3;
	}

	//Game loop
	while (detectwin != false){
	printboard();	
	user_input();
	if (traps() == true)
		break;
	}
	printboard();
	if (traps() == true)
		std::cout << "\n\n You died!\n";
	else
		std::cout << "\n\n You won!\n";
	return 0;
}

