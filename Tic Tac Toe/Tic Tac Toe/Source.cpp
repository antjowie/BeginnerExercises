#include <iostream>
#include <string>
#include <time.h>

char counter, winner, input, mark = 'X', board[9]{ '1','2','3','4','5','6','7','8','9' };
int player = 0, tempplayer, adress, turns = 0, pointer, vertical, horizontal, random;

void printBoard() {
	int printer = 6;
	for (int vertical = 0; vertical < 3; vertical++) {
		for (int horizontal = 0; horizontal < 3; horizontal++) {
			std::cout << board[printer] << ' ';
			printer++;
		}
		std::cout << std::endl;
		printer -= 6;
	}
}

void turn() {

	//Turn decider
	mark = (tempplayer = player % 2 == 0) ? 'X' : 'O';

	switch (mark) {
	case 'X':
		std::cout << "\nPlayer X: ";
		break;
	case 'O':
		std::cout << "\nPlayer O: ";
	}
}

void logic() {
	while (1) {
		std::cin >> input;
		adress = input - '0' - 1;

		//Control section
		if (input == board[adress])
			break;
		else
			std::cout << "Value already modified" << std::endl;
	}
	player++;
	board[adress] = mark;
}

char aiLogic() {

	//AI rules
	//block victory
	//take middle
	//take corners
	//take sides

	//block victory
	for (vertical = 0, pointer = 0; vertical < 3; vertical++, pointer += 3) {
		if (board[pointer + 1] == 'X' && board[pointer + 2] == 'X' && board[pointer] != 'O')
			return (board[pointer] = 'O');
		if (board[pointer] == 'X' && board[pointer + 2] == 'X' && board[pointer + 1] != 'O')
			return (board[pointer + 1] = 'O');
		if (board[pointer] == 'X' && board[pointer + 1] == 'X' && board[pointer + 2] != 'O')
			return (board[pointer + 2] = 'O');
	}
	for (horizontal = 0, pointer = 0; horizontal < 3; horizontal++, pointer++) {
		if (board[pointer + 3] == 'X' && board[pointer + 6] == 'X' && board[pointer] != 'O')
			return (board[pointer] = 'O');
		if (board[pointer] == 'X' && board[pointer + 6] == 'X' && board[pointer + 3] != 'O')
			return (board[pointer + 3] = 'O');
		if (board[pointer] == 'X' && board[pointer + 3] == 'X' && board[pointer + 6] != 'O')
			return (board[pointer + 6] = 'O');
	}
	if (board[4] == 'X' && board[8] == 'X' && board[0] != 'O')
		return (board[0] = 'O');
	if (board[0] == 'X' && board[8] == 'X' && board[4] != 'O')
		return (board[4] = 'O');
	if (board[0] == 'X' && board[4] == 'X' && board[8] != 'O')
		return (board[8] = 'O');
	if (board[4] == 'X' && board[2] == 'X' && board[6] != 'O')
		return (board[6] = 'O');
	if (board[6] == 'X' && board[2] == 'X' && board[4] != 'O')
		return (board[4] = 'O');
	if (board[4] == 'X' && board[6] == 'X' && board[2] != 'O')
		return (board[2] = 'O');

	//take middle
	if (board[4] == '5')
		return (board[4] = 'O');

	//take corners(at random)
	while (board[0] == '1' || board[2] == '3' || board[6] == '7' || board[8] == '9') {
		srand(time(0));
		random = rand() % 4;
		if (random == 0 && board[0] == '1')
			return (board[0] = 'O');
		if (random == 1 && board[2] == '3')
			return (board[2] = 'O');
		if (random == 2 && board[6] == '7')
			return (board[6] = 'O');
		if (random == 3 && board[8] == '9')
			return (board[8] = 'O');
	}

	//take sidess(at random)
	while (board[1] == '2' || board[3] == '4' || board[5] == '6' || board[7] == '8') {
		srand(time(0));
		random = rand() % 4;
		if (random == 0 && board[1] == '2')
			return (board[1] = 'O');
		if (random == 1 && board[3] == '4')
			return (board[2] = 'O');
		if (random == 2 && board[5] == '6')
			return (board[5] = 'O');
		if (random == 3 && board[7] == '8')
			return (board[7] = 'O');
	}
}

char checkwin() {

	//left-right control section
	for (vertical = 0, pointer = 0; vertical < 3; vertical++, pointer += 3)
		if (board[pointer] == board[pointer + 1] && board[pointer] == board[pointer + 2])
			return board[pointer];

	//down-up control section
	for (horizontal = 0, pointer = 0; horizontal < 3; horizontal++, pointer++)
		if (board[pointer] == board[pointer + 3] && board[pointer] == board[pointer + 6])
			return board[pointer];

	//ll_ur control section
	pointer = 0;
	if (board[pointer] == board[pointer + 4] && board[pointer] == board[pointer + 8])
		return board[pointer];

	//lr_ul control section	
	if (board[pointer + 2] == board[pointer + 4] && board[pointer + 2] == board[pointer + 6])
		return board[pointer + 2];

	return ' ';
}

int main() {
	while (1) {
		printBoard();
		//turn();
		logic();
		turns++;
		if (checkwin() == 'X' || checkwin() == 'O' || turns == 9)
			break;
		aiLogic();
		turns++;
		if (checkwin() == 'X' || checkwin() == 'O' || turns == 9)
			break;
	}

	//Finish section
	printBoard();
	if (checkwin() == 'X' || checkwin() == 'O')
		std::cout << "Player " << checkwin() << " won!" << std::endl;
	else
		std::cout << "Draw!" << std::endl;
	return 0;
}