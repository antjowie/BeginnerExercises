#include <iostream>
#include <string>	
#include <time.h>
#include <chrono>
#include <thread> 
#include <fstream>
#include <conio.h>

//Defines a sleep timer
#define sleep std::this_thread::sleep_for (std::chrono::seconds(1))

//Names and color are in enumerated value for better readability in function generatebunny
enum name { George, Leeroy, Frogsron, Bob, Zakje, Patat, Kebab, Auto, Nope, Lamp, Mac, KFC, Bal, Rondje, Kip, Comb, Schipje, RNG, Weeb, Dota, EUW, Poku };
enum color { White, Black, Brown, Sprouts };

struct bunny {
	std::string name;
	std::string color;
	std::string sex;
	int age = 0;
	bool radioactiveMutantVampireBunny;
	bool isModified = false;
	bunny *next = nullptr;
}*root, *list;

//Function declarations
void gatherValues(int &fertileFemales, int &fertileMales, int &infested);				//Complete
void contaminate(int &infested);														//Complete
void generate(int &total, int &fertileFemales);											//Complete
void spawn(int &total, const std::string &femaleColor = "NULL");						//Complete
void overPopulation(int &total, const bool &viaMassMurder = false);						//Complete
void kill(int &total, const bool &viaOverPopulation = false);							//Complete
void print(const int &turn);															//Complete
void insertFile(const std::string &info, const int &phase, const int &extra = 0);		//Complete

int main() {
	int total = 0;
	int turn = 0;
	int fertileMale = 0;
	int fertileFemale = 0;
	int infested = 0;
	root = new bunny;
	srand(time(0));
	remove ("output.txt");
	insertFile("Welcome to the bunny daily life simulator!\n", 5);
	sleep;

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
		gatherValues(fertileFemale, fertileMale, infested);

		//Phase 2
		//Looks to contaminate bunnies
		contaminate(infested);

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
		//Prints the bunny data
		print(turn);
	}
	insertFile("\n...\n It appears that all of the bunnies have died .-.\n The end\n", 5);
	sleep;
	return 0;
}

void gatherValues(int &fertileFemales, int &fertileMales, int &infested) {

	//Reset value
	fertileMales = 0;
	fertileFemales = 0;
	infested = 0;

	if (root != nullptr) {
		list = root;
		while (list != nullptr) {
			
			//Checks the value for function contaminate
			if (list->radioactiveMutantVampireBunny == true)
				infested++;
			
			//Checks the values for function generate
			if (list->age >= 3 && list->sex == "Female" && list->radioactiveMutantVampireBunny == false)
				fertileFemales++;
			else if (list->age >= 3 && list->sex == "Male" && list->radioactiveMutantVampireBunny == false)
				fertileMales++;
			
			list->age++;
			list = list->next;
		}
	}
}

void contaminate(int &infested) {
	if (root != nullptr) {
		list = root;
		while (infested > 0 && list != nullptr) {

			//Turns false rmvb bunnies into true rmvb bunnies for each true rmvb bunny
			if (list->radioactiveMutantVampireBunny == false){
				list->radioactiveMutantVampireBunny = true;
				insertFile("Contaminated bunny ", 1);
				infested--;
			}
				list = list->next;
		}
	}
}

void generate(int &total, int &fertileFemales) {
	bunny *female = root;

	//While fertilefemale >= 0 (gathered at function gathervalue) this loop runs
	for (fertileFemales; fertileFemales >= 0; fertileFemales--) {
		if (female->age >= 3 && female->sex == "Female" && female->radioactiveMutantVampireBunny == false)
			spawn(total, female->color);
		female = female->next;
	}
}

void spawn(int &total, const std::string &femaleColor) {
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
		std::cout << "Error in function generate (name)!\a\n";
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
		std::cout << "Error in function generate (sex)!\a\n";
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
			std::cout << "Error in funcion generate (color)\a\n";
		}
	else
		list->color = femaleColor;

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
	}
	else 
		insertFile("No bunnies to be found!\n", 5);
	sleep;
}

void insertFile(const std::string &info, const int &phase, const int &extra) {
	/*
	Phases
	 Phase 1: _INFO_ _NAME_ \n
	 Phase 2: (Radioactive mutant vampire )bunny _NAME_ _INFO_
	 Phase 3: for funtion print
	 Phase 4: \nTurn _EXTRA_ _INFO_
	 phase 5: _INFO_
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
		default:
			std::cout << "AN ERROR OCCURED! (function insertFile unknown phase value)\n";
			output << "AN ERROR OCCURED! (function insertFile unknown phase value)\n";
			sleep;
			break;
		}
		output.close();
	}
	else
	{
		std::cout << "AN ERROR OCCURED! (output.txt can't be opened)\n";
		output << "AN ERROR OCCURED! (output.txt can't be opened)\n";
		sleep;
	}
}