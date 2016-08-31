#include <iostream>
#include <string>	
#include <time.h>
#include <chrono>
#include <thread> 
#include <fstream>

//Defines a sleep timer
#define sleeptime std::chrono::seconds(0)
#define sleep std::this_thread::sleep_for (sleeptime)

//Enumerated values for names and color
enum names {George, Leeroy, Frogsron, Bob, Zakje, Patat, Kebab, Auto, Nope, Lamp, Mac, KFC, Bal, Rondje, Kip, Comb, Schipje, RNG, Weeb, Dota, EUW, Poku};
enum color {White, Black, Brown, Sprouts};

int bunnyAmmount = 0;
int MbunnyAmmount = 0;
int turn = 0;
int fertile = 0;
int infested;
int number = 1;

std::string tempRMVB;

//Structure which contains all the necessary propeties of a bunny
struct Bunny {
	int age = 0;
	std::string name;
	std::string color;
	std::string	sex;
	bool RMVB;
	Bunny *next = nullptr;
}*root = new Bunny, *adress, *female;

//Pre-defined function list
void generateBunny(int phase);
void gatherValues(void);
void spawnBunny(void);
void contaminationBunny(void);
void killBunny(void);
void overpopulationBunny(void);
void printBunny(void);
void insertFile(std::string line, int phase);

int main() {
	srand(time(0));
	remove("Console output.txt");

	//Initialises 5 starting bunnys
	for (int i = 5; i > 0; i--)
		generateBunny(0);

	//Simulator loop
	while (bunnyAmmount != 0) {
		gatherValues();
		if (fertile > 0)
			spawnBunny();
		if (infested > 0)
			contaminationBunny();
		killBunny();
		if (bunnyAmmount >= 1000)
			overpopulationBunny();
		printBunny();
		sleep;
	}

	//End section
	std::cout << "\nAll the bunnies have died! The bunnies existed for " << turn << " Turns\n The end" << std::endl;
	insertFile(" Turns\n The end", 3);
	sleep;
	return 0;
}

void generateBunny(int phase) {
	adress = root;

	//Locates latest list
	while (adress->next != nullptr)
		adress = adress->next;

	//Creates new list
	adress->next = new Bunny;
	adress = adress->next;

	//Generate bunny age
	adress->age = 0;

	//Switch which enters a name
	
	switch (rand() % 22) {
	case George:
		adress->name = "George";
		break;
	case Leeroy:
		adress->name = "Leeroy";
		break;
	case Frogsron:
		adress->name = "Frogsron";
		break;
	case Bob:
		adress->name = "Bob";
		break;
	case Zakje:
		adress->name = "Zakje";
		break;
	case Patat:
		adress->name = "Patat";
		break;
	case Kebab:
		adress->name = "Kebab";
		break;
	case Auto:
		adress->name = "Auto";
		break;
	case Nope:
		adress->name = "Nope";
		break;
	case Lamp:
		adress->name = "Lamp";
		break;
	case Mac:
		adress->name = "Mac";
		break;
	case KFC:
		adress->name = "KFC";
		break;
	case Bal:
		adress->name = "Bal";
		break;
	case Rondje:
		adress->name = "Rondje";
		break;
	case Kip:
		adress->name = "Kip";
		break;
	case Comb:
		adress->name = "Comb";
		break;
	case Schipje:
		adress->name = "Schipje";
		break;
	case RNG:
		adress->name = "RNG";
		break;
	case Weeb:
		adress->name = "Weeb";
		break;
	case Dota:
		adress->name = "Dota";
		break;
	case EUW:
		adress->name = "EUW";
		break;
	case Poku:
		adress->name = "Poku";
		break;
	default:
		std::cout << "Error\n";
		break;
	}
	
	//Switch which enters a color
	if (phase == 0)
		switch (rand() % 4) {
		case White:
			adress->color = "white";
			break;
		case Black:
			adress->color = "black";
			break;
		case Brown:
			adress->color = "brown";
			break;
		case Sprouts:
			adress->color = "sprouts";
			break;
		}
	else
		adress->color = female->color;

	//Defies sex and RMVB
	if (rand() % 2 == 0) {
		adress->sex = "male";
		MbunnyAmmount++;
	}
	else
		adress->sex = "female";
	adress->RMVB = (rand() % 100 >= 98) ? true : false;

	//Prints event
	if (adress->RMVB == true) {
		std::cout << "Radioactive mutant vampire bunny " << adress->name << " was born!\n";
		insertFile("generatebunny rmvb true\n", 2);
		insertFile(" was born! ", 0);
		infested++;
	
	}
	else{
		std::cout << "Bunny " << adress->name << " was born!\n";
		insertFile("generatebunny rmvb false\n ", 2);
		insertFile(" was born! ", 0);
	}
	sleep;
	
	bunnyAmmount++;
}

void gatherValues() {
	turn++;
	infested = 0;

	//Checks the bunnies properties for fertile, necessary for function spawnBunny
	adress = root->next;
	while (adress != nullptr) {
		adress->age++;
		if (adress->age == 3 && adress->sex == "female" && adress->RMVB==false) {
			std::cout << "Bunny " << adress->name << " became fertile\n";
			insertFile(" became fertile\n", 0);
			sleep;
		}
		if (adress->age == 3 && adress->sex == "male" && adress->RMVB == false) {
			std::cout << "Bunny " << adress->name << " is ready to mate\n";
			insertFile(" is ready to mate\n", 0);
			fertile++;
			sleep;
		}
		if (adress->RMVB == true)
			infested++;
		adress = adress->next;
	}
}

void spawnBunny() {
	female = root;
	while (female != nullptr) {
		if (female->age >= 3 && female->sex == "female" && female->RMVB == false)
			generateBunny(1);
		female = female->next;
	}
}

void contaminationBunny() {
	adress = root;
	if (adress != nullptr)
		while (adress != nullptr) {
			//Breaks loop if all the infested bunnies are done contaminating the others
			if (infested == 0)
				break;
			if (adress->RMVB == false) {
				adress->RMVB = true;
				if (adress->sex == "male")
					fertile--;
				std::cout << "Bunny " << adress->name << " has been contaminated\n";
				insertFile(" has been contaminated\n", 0);
				infested--;
				sleep;
			}
			adress = adress->next;
		}
}

void killBunny() {
	adress = root;
	if (adress != nullptr){
			Bunny * linker;
		while (adress != nullptr) {
			//Checks RMVB value because they die in 50 years
			if (linker->age == 10 && linker->RMVB == false) {
				std::cout << "Bunny " << adress->name << " died!\n";
				insertFile("killbunny rmvb false\n", 2);
				insertFile(" died! ", 0);
				adress = adress->next;
				delete linker;
				bunnyAmmount--;
				
				if (adress->sex == "male")
					fertile--;
				sleep;
			}
			else if (adress->age == 50 && linker->RMVB == true) {
				std::cout << "Bunny " << adress->name << " died!\n";
				insertFile("killbunny rmvb true\n", 2);
				insertFile(" died! ", 0);
				adress = adress->next;
				delete linker;
				bunnyAmmount--;
				
				sleep;
			}
			else
				adress = adress->next;
		}
	}
}

void overpopulationBunny() {
	int tempbunnyAmmount = bunnyAmmount / 2;
	adress = root;
	std::cout << "A food shortage has occured!\n";
	insertFile("A food shortage has occured!\n", 2);
	sleep;
	while (tempbunnyAmmount != 0) {
		//Randomizer for killing bunnies
		Bunny * linker = adress;
		if (rand() % 2 == 0) {
			std::cout << "Bunny " << adress->name << " died!\n";
			insertFile(" died!\n", 0);
			adress = adress->next;
			delete linker;
			tempbunnyAmmount--;
			bunnyAmmount--;
			
			if (adress->sex == "male"&&adress->RMVB == false)
				fertile--;
			sleep;
		}
		else
			adress = adress->next;
		if (adress == nullptr)
			adress = root->next;
	}
}

void printBunny() {
	std::cout << "\n---\n";
	insertFile("\n---\n", 5);
	adress = root;
	if (adress != nullptr)
		for (int i = 50; i >= 0; i--) {
			while (adress != nullptr) {
				if (adress->age == i) {
					tempRMVB = (adress->RMVB == true) ? "positive" : "negative";
					std::cout << "Age " << adress->age << "\t| Name " << adress->name << "\t| Sex " << adress->sex << "\t| Color " << adress->color << "\t| RMVB " << tempRMVB << "\t| " << std::endl;
					insertFile("", 4);
				}
				adress = adress->next;
			}
			adress = root->next;
		}
	std::cout << std::endl;
	sleep;
	sleep;
}

void insertFile(std::string line, int phase) {
	//phase 0 Bunny .name. "line"
	//phase 1 RMVB bunny .name. "line"
	//phase 2 "line"
	//phase 3 \nAll the bunnies have died! The bunnies existed for ..turn.. "line"
	//phase 4 printBunny
	std::ofstream insert("Console output.txt", std::ios::out | std::ios::app);
	if (insert.is_open()) {
		switch (phase) {
		case 0:
			insert << "Bunny " << adress->name << line << std::endl;
			break;
		case 1:
			insert << "Radioactive mutant vampire bunny " << adress->name << line;
			break;
		case 2:
			insert << line;
			break;
		case 3:
			insert << "\nAll the bunnies have died! The bunnies existed for " << turn << line;
			break;
		case 4:
			insert << "Age " << adress->age << "\t| Name " << adress->name << "\t| Sex " << adress->sex << "\t| Color " << adress->color << "\t| RMVB " << tempRMVB << "\t|" << std::endl;
			break;
		default:
			insert << "Error\n";
			break;
		}
		insert.close();
	}
}