#include <iostream>
#include <string>	
#include <time.h>
#include <chrono>
#include <thread> 
#include <fstream>

//Defines a sleep timer
#define sleep std::this_thread::sleep_for (std::chrono::seconds(0))

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
void print(const int &turn);															//Complete
void contaminate(int &infested);														//Complete
void generate(int &total, int &fertileFemales);											//Complete
void spawn(int &total, const std::string &femaleColor = "NULL");						//Complete
void overPopulation();
void kill(int &total, const bool &viaOverPopulation = false);
void inserFile();


int main() {
	int total = 0;
	int turn = 0;
	int fertileMale = 0;
	int fertileFemale = 0;
	int infested = 0;
	root = new bunny;
	srand(time(0));

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

	while (total >= 0) {
		turn++;

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


		//Phase 5
		//Kills the bunny by age
		kill(total);

		//Phase 6
		//Prints the bunny data
		print(turn);
	}
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
			if (list->radioactiveMutantVampireBunny == false){
				list->radioactiveMutantVampireBunny = true;
				infested--;
			}
				list = list->next;
		}
	}
}

void generate(int &total, int &fertileFemales) {
	bunny *female = root;
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
	if (list->radioactiveMutantVampireBunny == true) {
		std::cout << "Radioactive mutant vampire bunny " << list->name << " is born!\n";
	}
	else{
		std::cout << "Bunny " << list->name << " is born!\n";
	}
	
	//Allows the first node to be modified
	list->isModified = true;
	total++;
	sleep;
}

void kill(int &total, const bool &viaOverPopulation) {
	if (root != nullptr) {
		bunny *destructor;
		int counter = 0;
		destructor = root;
			list = destructor;
		while (destructor != nullptr) {
			std::cout << counter;
			//Initiate death by age
			if (destructor->age == 10 && destructor->radioactiveMutantVampireBunny == false || destructor->age == 50 && destructor->radioactiveMutantVampireBunny == true || viaOverPopulation == true) {
				if (counter == 0)
					std::cout << "REMOVE NODE \a";
//					root = root->next;
				else if (destructor->next != nullptr)
					list = list->next->next;
				delete destructor;
				total--;
				kill(total);
			}
			list = destructor;
			destructor = destructor->next;
			counter++;
		}
	}
}

void print(const int &turn) {
	std::cout << "\nTurn " << turn << "\nListing bunnies...\n";
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
					std::cout << "Name " << list->name << "\tsex " << list->sex << "\tage " << list->age << "\tcolor " << list->color << "\tRMVB " << tempRadioactiveMutantVampireBunny << std::endl;
				}
				list = list->next;
			}
			list = root;
		}
		sleep;
	}
	else
		std::cout << "No bunnies to be found!\n";
	sleep;
}