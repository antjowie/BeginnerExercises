#include <iostream>
#include <string>	
#include <time.h>
#include <chrono>
#include <thread> 
#include <fstream>
#include <conio.h>

//Defines a sleep timer
#define sleep std::this_thread::sleep_for (std::chrono::seconds(0))

//Names and color are in enumerated value for better readability in function generatebunny
enum name { George, Leeroy, Frogsron, Bob, Zakje, Patat, Kebab, Auto, Nope, Lamp, Mac, KFC, Bal, Rondje, Kip, Comb, Schipje, RNG, Weeb, Dota, EUW, Poku };
enum color { White, Black, Brown, Sprouts };
char grid[80][80];


struct bunny {
	std::string name;
	std::string color;
	std::string sex;
	int age = 0;
	int x;
	int y;
	char icon;
	bool radioactiveMutantVampireBunny;
	bool isModified = false;
	bunny *next = nullptr;
}*root, *list;

//Function declarations
void gatherValues(int &fertileFemales, int &fertileMales);																		//Complete
void contaminateSearch(int x = 0, int y = 0);																					//Complete
void contaminateExecute(const int &infectedx, const int &infectedy);																	
void generate(int &total, int &fertileFemales);																					//Complete
void spawn(int &total, const std::string &femaleColor = "NULL", const int &femalex = 0, const int &femaley = 0);				//Complete
void overPopulation(int &total, const bool &viaMassMurder = false);																//Complete
void kill(int &total, const bool &viaOverPopulation = false);																	//Complete
void print(const int &turn);																									//Complete
void insertGrid(void);																											//Complete
void insertFile(const std::string &info, const int &phase, const int &extra = 0, const char &xy = '0');							//Complete

int main() {
	int total = 0;
	int turn = 0;
	int fertileMale = 0;
	int fertileFemale = 0;
	root = new bunny;
	srand(time(0));
	remove ("output.txt");
	
	insertFile("Welcome to the bunny daily life simulator! (pressing \'k\' will initiate a mass murder!)\n", 5);
	sleep;

	//Fills grid with dots
	for (int x = 0; x < 80; x++)
		for (int y = 0; y < 80; y++)
			grid[x][y] = '.';

	//Generate 5 bunnies
	while (total != 5)
		spawn(total);

	/*
	Phases
	 Gather and update values
	 Contaminate bunnies
	 Spawn new bunnies
	 Check for overpopulation
	 Kill bunnies
	 Insert grid
	 Print the bunnies
	*/

	while (total > 0) {
		turn++;

		//Checks if k is pressed
		if(_kbhit())
			if (_getch() == 'k')
				overPopulation(total, true);

		//Phase 1
		//Gathers the values for generate and adds age to the bunnies
		gatherValues(fertileFemale, fertileMale);

		//Phase 2
		//Looks to contaminate bunnies
		contaminateSearch();

		//Phase 3
		//Checks the values to see if new bunnies will be spawned
		if (fertileFemale > 0 && fertileMale > 0)
			generate(total, fertileFemale);

		//Phase 4
		//Check for overpopulation
		if (total >= 1000)
			overPopulation(total);

		//Phase 5
		//Kills the bunny by age
		kill(total);

		//Phase 6
		//Inserts bunny xy into grid
		insertGrid();
		//Phase 7
		//Prints the bunny data
		print(turn); 
	}
	insertFile("\n...\n It appears that all of the bunnies have died .-.\n The end\n", 5);
	sleep;
	return 0;
}

void gatherValues(int &fertileFemales, int &fertileMales) {

	//Reset value
	fertileMales = 0;
	fertileFemales = 0;

	if (root != nullptr) {
		list = root;
		while (list != nullptr) {
			
			//Checks the values for function generate
			if (list->age >= 2 && list->sex == "Female" && list->radioactiveMutantVampireBunny == false)
				fertileFemales++;
			else if (list->age >= 2 && list->sex == "Male" && list->radioactiveMutantVampireBunny == false)
				fertileMales++;
	
			list->age++;
			list = list->next;
		}
	}
}

void contaminateSearch(int x, int y) {
	for (int x; x<80; x++)
		for (int y; y < 80; y++) {
			if (grid[x][y] == 'X') {
				if (x != 79 && grid[x + 1][y])
					contaminateExecute(x + 1, y);
				else if (x != 0 && grid[x - 1][y])
					contaminateExecute(x - 1, y);
				else if (y != 79 && grid[x][y + 1])
					contaminateExecute(x, y + 1);
				else if (y != 0 && grid[x][y - 1])
					contaminateExecute(x, y - 1);
			}
		}
}

void contaminateExecute(const int &infectedx, const int &infectedy) {
	list = root;
	while (list != nullptr) {

	}
}

void generate(int &total, int &fertileFemales) {
	bunny *female = root;
	//While fertilefemale >= 0 (gathered at function gathervalue) this loop runs
	while (fertileFemales >= 0 && female != nullptr) {
		if (female->age >= 3 && female->sex == "Female" && female->radioactiveMutantVampireBunny == false) {
			spawn(total, female->color, female->x, female->y);
			fertileFemales--;
		}
		female = female->next;
	}
}

void spawn(int &total, const std::string &femaleColor, const int &femalex, const int &femaley) {
	list = root;
	//Travers the nodes
	while (list->next != nullptr)
		list = list->next;
	//Uses first node of the list
	if (list->isModified == true) {
		list->next = new bunny;
		list = list->next;
	}
	//Names bunny
	switch (rand() % 22) {
	case George:
		list->name = "George";
		break;
	case Leeroy:
		list->name = "Leeroy";
		break;
	case Frogsron:
		list->name = "Frogsron";
		break;
	case Bob:
		list->name = "Bob";
		break;
	case Zakje:
		list->name = "Zakje";
		break;
	case Patat:
		list->name = "Patat";
		break;
	case Kebab:
		list->name = "Kebab";
		break;
	case Auto:
		list->name = "Auto";
		break;
	case Nope:
		list->name = "Nope";
		break;
	case Lamp:
		list->name = "Lamp";
		break;
	case Mac:
		list->name = "Mac";
		break;
	case KFC:
		list->name = "KFC";
		break;
	case Bal:
		list->name = "Bal";
		break;
	case Rondje:
		list->name = "Rondje";
		break;
	case Kip:
		list->name = "Kip";
		break;
	case Comb:
		list->name = "Comb";
		break;
	case Schipje:
		list->name = "Schipje";
		break;
	case RNG:
		list->name = "RNG";
		break;
	case Weeb:
		list->name = "Weeb";
		break;
	case Dota:
		list->name = "Dota";
		break;
	case EUW:
		list->name = "EUW";
		break;
	case Poku:
		list->name = "Poku";
		break;
	default:
		insertFile("Error in function generate (name)!\a\n", 5);
	}

	//Decides sex of the bunny 
	switch (rand() % 2) {
	case 0:
		list->sex = "Male";
		break;
	case 1:
		list->sex = "Female";
		break;
	default:
		insertFile("Error in funcion generate (sex)\a\n", 5);
	}

	//Decides color of the bunny
	if (femaleColor == "NULL")
		switch (rand() % 4) {
		case Black:
			list->color = "Black";
			break;
		case Brown:
			list->color = "Brown";
			break;
		case Sprouts:
			list->color = "Sprouts";
			break;
		case White:
			list->color = "White";
			break;
		default:
			insertFile("Error in funcion generate (color)\a\n", 5);
		}
	else
		list->color = femaleColor;

	//Decides xy of bunny
	bool finished = false;
	if (femaleColor == "NULL") {
		
		//Checks so bunny won't overwrite
		while (finished == false) {
			int tempx = rand() % 80;
			int tempy = rand() % 80;
			if (grid[tempx][tempy] == '.') {
				list->x = tempx;
				list->y = tempy;
				finished = true;
			}
		}
	}
	else
		//Checks so bunny won't overwrite
	bool finished = false;
	for (int counter = 0; counter < 10, finished == false; counter++) {
			switch (rand() % 3) {
			case 0:
				if (grid[femalex - 1][femaley] == '.') {
					list->x = femalex - 1;
					list->y = femaley;
					finished = true;
				}
				break;
			case 1:
				if (grid[femalex + 1][femaley] == '.') {
					list->x = femalex + 1;
					list->y = femaley;
					finished = true;
				}
				break;
			case 2:
				if (grid[femalex][femaley - 1] == '.') {
					list->x = femalex;
					list->y = femaley - 1;
					finished = true;
				}
				break;
			case 3:
				if (grid[femalex][femaley + 1] == '.') {
					list->x = femalex;
					list->y = femaley + 1;
					finished = true;
				}
				break;
			default:
				insertFile("Error in function spawn(unkown value under //checks so bunny won;t overwrite\a\n", 5);
				break;
			}

			//Lost child (cheap way to dodge infinite loop)
			if (counter == 9) {
				list->x = rand() % 80;
				list->y = rand() % 80;
				std::cout << counter << " loop\n";
			}
		}

	//Decides radioactiveMutantVampiteBunny
	list->radioactiveMutantVampireBunny = (rand() % 100 >= 98) ? true : false;

	//Prints the event
	insertFile(" is born!\n", 2);

	//Allows the first node to be modified
	list->isModified = true;
	total++;
	sleep;
}

void overPopulation(int &total, const bool &viaMassMurder) {
	int tempTotal = total / 2;
	if (viaMassMurder == false) {
		insertFile("Big trouble! A bunny overpopulation is occuring, there is a shortage of food!\n", 5);
	}
	else {
		insertFile("You've initiated a mass murder!\n", 5);
	}
	
	sleep;
	//Keeps killing until half of total are left
	while (tempTotal > 0) {
		kill(total, true);
		tempTotal--;
	}
}

void kill(int &total, const bool &viaOverPopulation) {
	if (root != nullptr) {
		bunny *destructor;
		int counter = 0;
		destructor = root;
		list = destructor;
		while (destructor != nullptr) {
			//Initiate death by age
			if (destructor->age == 10 && destructor->radioactiveMutantVampireBunny == false || destructor->age == 50 && destructor->radioactiveMutantVampireBunny == true || viaOverPopulation == true) {
				insertFile(" died!\n", 2);
				grid[destructor->x][destructor->y] = '.';
				if (counter == 0) 
					root = root->next;
				else if (destructor->next != nullptr)
					list->next = list->next->next;
				destructor = nullptr;
				delete destructor;
				total--;
				sleep;
				if (viaOverPopulation != true)
					kill(total);
			}
			list = destructor;
			if (destructor != nullptr)
				destructor = destructor->next;
			counter++;
		}
	}
}

void print(const int &turn) {
	insertFile("\nListing bunnies...\n", 4, turn);
	sleep;

	//Fail-safe if no bunnies are found (otherwise will result in a crash)
	if (root != nullptr) {
		
		//Sorts list descending from age
		list = root;
		for (int i = 50; i >= 0; i--) {
			while (list != nullptr) {

				//Prints bunny data if age is the same
				if (list->age == i) {
					std::string tempRadioactiveMutantVampireBunny = (list->radioactiveMutantVampireBunny == true) ? "Positive" : "Negative";
					insertFile(tempRadioactiveMutantVampireBunny, 3);
				}
				list = list->next;
			}
			list = root;
		}
		insertFile("\n", 5);
		sleep;
		
		//Prints grid
		for (int x = 0; x < 80; x++) {
			for (int y = 0; y < 80; y++) 
				insertFile("", 6, 0, grid[x][y]);
			insertFile("\n", 5);
		}
		insertFile("\n", 5);
		sleep;
	}
	else 
		insertFile("No bunnies to be found!\n", 5);
	sleep;
}

void insertGrid() {
	if (list != nullptr)
	list = root;
		while (list != nullptr) {

			//Updates bunny icon
			if (list->radioactiveMutantVampireBunny == true)
				list->icon = 'X';
			else if (list->sex == "Male") {
				if (list->age > 2)
					list->icon = 'M';
				else
					list->icon = 'm';
			}
			else if (list->sex == "Female") {
				if (list->age > 2)
					list->icon = 'F';
				else
					list->icon = 'f';
			}

			//Moves bunny
			bool moved = false;
			for (int counter = 0; counter < 10, moved == false; counter++) {
				switch (rand() % 3) {
				case 0:
					if (grid[list->x - 1][list->y] == '.' && list->x != 0) {
						grid[list->x][list->y] = '.';
						list->x -= 1;
						moved = true;
					}
					break;
				case 1:
					if (grid[list->x + 1][list->y] == '.' && list->x != 97) {
						grid[list->x][list->y] = '.';
						list->x += 1;
						moved = true;
					}
					break;
				case 2:
					if (grid[list->x][list->y - 1] == '.' && list->y != 0) {
						grid[list->x][list->y] = '.';
						list->y -= 1;
						moved = true;
					}
					break;
				case 3:
					if (grid[list->x][list->y + 1] == '.' && list->y != 97) {
						grid[list->x][list->y] = '.';
						list->y += 1;
						moved = true;
					}
					break;
				default:
					insertFile("Error in function generateValue (unkown random value at moves bunny)\a\n", 5);
					break;
				}
				 	std::cout << counter <<" Warning overflow chance incoming\n";
				if (counter == 9)
					moved = true;
			}

			//Inserts bunnies into grid
			grid[list->x][list->y] = list->icon;

			list = list->next;
		}
}

void insertFile(const std::string &info, const int &phase, const int &extra, const char &xy) {
	/*
	Phases
	 Phase 1: _INFO_ _NAME_ \n
	 Phase 2: (Radioactive mutant vampire )bunny _NAME_ _INFO_
	 Phase 3: for funtion print
	 Phase 4: \nTurn _EXTRA_ _INFO_
	 Phase 5: _INFO_
	 Phase 6: for print grid
	*/

	std::ofstream output ("output.txt", std::ios::out | std::ios::app);
	if (output.is_open()) {
		switch (phase) {
		case 1:
			output << info << list->name << "\n";
			std::cout << info << list->name << "\n";
			break;
		case 2:
			if (list->radioactiveMutantVampireBunny == true) {
				output << "Radioactive mutant vampire bunny " << list->name << info;
				std::cout << "Radioactive mutant vampire bunny " << list->name << info;
			}
			else {
				output << "Bunny " << list->name << info;
				std::cout << "Bunny " << list->name << info;
			}
			break;
		case 3:
			output << "Name " << list->name << "\tsex " << list->sex << "\tage " << list->age << "\tcolor " << list->color << "\tRMVB " << info << std::endl;
			std::cout << "Name " << list->name << "\tsex " << list->sex << "\tage " << list->age << "\tcolor " << list->color << "\tRMVB " << info << std::endl;
			break;
		case 4:
			output << "\nTurn " << extra << info;
			std::cout << "\nTurn " << extra << info;
			break;
		case 5:
			output << info;
			std::cout << info;
			break;
		case 6:
			output << xy;
			std::cout << xy;
			break;
		default:
			std::cout << "Error in function insertFile (unknown phase value)\a\n";
			output << "Error in function insertFile (unknown phase value)\a\n";
			sleep;
			break;
		}
		output.close();
	}
	else
	{
		std::cout << "Error in function insertFile (else)\a\n";
		sleep;
	}

}
