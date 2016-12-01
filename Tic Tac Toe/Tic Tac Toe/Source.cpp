#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Global constants
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_WINNER = 'N';

// Function prototypes
void instructions(const bool numpad);
void displayBoard(const std::vector<char>& board);
char askYesNo(const std::string& question);
char playerPiece();
char computerPiece(const char& player);
int askNumber(const std::string& question, const int high, const bool numpad, const int low = 0);
int toNumpad(int& value);
inline bool isLegal(const std::vector<char>& board, const int move);
int playerMove(const std::vector<char>& board, const char player, const bool numpad);
int computerMove(std::vector<char> board, const char player, const char computer);
char determineWinner(const std::vector<char>& board);
inline void congratulateWinner(const char winner, const char player, const char computer);

int main() {
	bool numpad = ((askYesNo("Do you have a numpad?\n") == 'y') ? true : false);

	char winner;
	int move;
	const int MAX_SQUARES = 9;
	std::vector<char> board(MAX_SQUARES, EMPTY);

	instructions(numpad);
	char player = playerPiece();
	char computer = computerPiece(player);
	char turn = X;

	displayBoard(board);
	while (winner = determineWinner(board) == NO_WINNER) {

		if (turn == player) {
			move = playerMove(board, player, numpad);
			board[move] = player;
			std::cout << "Player has taken number " << move << ".\n";
			}
		else
		{
			move = computerMove(board, player, computer);
			board[move] = computer;
			std::cout << "I shall take number " << move << "!\n";
		}
		turn = (turn == X) ? O : X;
		displayBoard(board);
		}
	congratulateWinner(winner, player, computer);
	std::cout << "\n(side note) Thanks for playing!" << std::endl;
	return 0;
}

void instructions(const bool numpad) {
	std::cout << "Welcome to the most important game of tic tac toe you will ever wintness.\n"
		<< "You will play against me! Human vs machine. I'll warn you, I have no mercy.\n"
		<< "You play by entering a value which is on the board. This is the layout:\n";
	if (numpad == true) {
		std::cout << "\t 7 | 8 | 9 \n"
			<< "\t-----------\n"
			<< "\t 4 | 5 | 6 \n"
			<< "\t-----------\n"
			<< "\t 1 | 2 | 3 \n";
	}
	else {
		std::cout << "\t 0 | 1 | 2 \n"
			<< "\t-----------\n"
			<< "\t 3 | 4 | 5 \n"
			<< "\t-----------\n"
			<< "\t 6 | 7 | 8 \n";
	}
	std::cout << "Pretty easy, for me atleast. Prepare yourself.\n\n";
}

void displayBoard(const std::vector<char>& board)
{
	std::cout << "\n\t " << board[0] << " | " << board[1] << " | " << board[2]
		<< "\n\t" << "-----------"
		<< "\n\t " << board[3] << " | " << board[4] << " | " << board[5]
		<< "\n\t" << "-----------"
		<< "\n\t " << board[6] << " | " << board[7] << " | " << board[8]  << '\n';
}

char askYesNo(const std::string & question)
{
	std::cout << question;
	char input;
	do {
		std::cout << "y/n: ";
		std::cin >> input;
	} while ((input != 'y') && (input != 'n'));
	if (input == 'y')
		return 'y';
	else
		return 'n';
}

char playerPiece()
{
	char go_first = askYesNo("Because I'm being modest, I'll let you decide if you want to start. Better think this through.\n");
	if (go_first == 'y') {
		std::cout << "You'll need it.\n";
		return X;
	}
	else {
		std::cout << "Careful what you wish for...\n";
		return O;
	}
}

char computerPiece(const char & player)
{
	if (player == X)
		return O;
	else
		return X;

}

int askNumber(const std::string & question, const int high, const bool numpad, const int low)
{
	std::cout << question << "Must be inbetween " << low << " and " << high << '\n';
	int move;
	std::cin >> move;
	if (numpad == true)
		toNumpad(move);
	while ((move > high) || (move < low)) {
		std::cout << "Fool! Your value is invalid.\n";
		std::cin >> move;
		if (numpad == true)
			toNumpad(move);
	}
	return move;
}

int toNumpad(int & value)
{
	if (value < 4)
		return (value += 5);
	else if (value < 7)
		return (value -= 1);
	else
		return (value -= 7);
}

inline bool isLegal(const std::vector<char>& board, const int move)
{
	if (board[move] == EMPTY)
		return true;
	else
		return false;
}

int playerMove(const std::vector<char>& board, const char player, const bool numpad)
{
	int move = askNumber("Player turn...\n", (board.size() - 1), numpad);
	while (!isLegal(board, move)) {
		std::cout << "Idiot! that space is already occupied.\n";
		move = askNumber("Still player turn.....\n", (board.size() - 1), numpad);
	}
	return move;
}

int computerMove(std::vector<char> board, const char player, const char computer)
{
	/*
	 AI Protocol in specific order
	1- Secure own victory
	2- Block out opponents victory
	3- Take corners
	4- Take space inbetween corners
	*/
	std::cout << "Computer's turn...\n";

	unsigned int move = 0;
	bool victory = false;

	while ((!victory) && (move < board.size())) {
		if (isLegal(board, move)) {
			board[move] = computer;
			victory = determineWinner(board) == computer;
			board[move] = EMPTY;
		}
		if(!victory)
			++move;
	}

	if (!victory) {
		move = 0;
		while ((!victory) && (move < board.size())) {
			if (isLegal(board, move)) {
				board[move] = player;
				victory = determineWinner(board) == player;
				board[move] = EMPTY;
			}
			if (!victory)
				++move;
		}
	}
	if (!victory) {
		const char BEST_MOVES[]{ 4,0,2,6,8,1,3,5,7 };
		for (int i = 0; !victory; ++i) {
			move = BEST_MOVES[i];
			if (isLegal(board, move))
				victory = true;
		}
	}
	return move;
}

char determineWinner(const std::vector<char>& board)
{
	const int TOTAL_ROWS = 8;
	const char WINNING_ROWS[TOTAL_ROWS][3]{
		{0,1,2},
		{3,4,5},
		{6,7,8},
		{0,3,6},
		{1,4,7},
		{2,5,8},
		{0,4,8},
		{2,4,6}
	};

	// Return winner
	for (int row = 0; row < TOTAL_ROWS; ++row) {
		if ((board[WINNING_ROWS[row][0]] != EMPTY) &&
			(board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
			(board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]))
			return board[WINNING_ROWS[row][0]];
	}
	
	// Return tie
	if (std::count(board.begin(), board.end(), EMPTY) == 0)
		return TIE;

	// Nobody won
	return NO_WINNER;
}

inline void congratulateWinner(const char winner, const char player, const char computer)
{
	if (winner == computer) {
		std::cout << "Just as I predicted, I am a computer after all.\n";
	}
	else if (winner == player) {
		std::cout << "Unbelievable, your just a dirty hacker, aren't ya.\n";
	}
	else
		std::cout << "It appears you are quite the formidable opponent.\n";
}