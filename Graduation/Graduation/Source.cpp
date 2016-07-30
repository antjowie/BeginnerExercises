#include <iostream>
#include <string>	
#include <time.h>
#include <chrono>
#include <thread> 
#include <fstream>

#define sleeptime std::chrono::seconds(0)
#define sleep std::this_thread::sleep_for (sleeptime)

struct type {
	int age;
	std::string name;
	std::string sex;
	std::string color;
	bool rmvb;
	type *next;
}*root, *adress, *female;

int rmvbammount;
int count;
int malecount;
int femalecount;
int Mmalecount;
int Mfemalecount;
int turn = 0;
int random;
std::ofstream output;
std::string rmvb;

void printbunny();
void generatebunny(int phase);
void spawnbunny();
void gathervalue();
void killbunny();
void infestbunny();
void overflowbunny(int total);
void insertfile(std::string line, int eventkind, int ammount);
int main() {

//Initialize 5 starting bunnys
	std::remove("console output.txt");
	srand(time(0));
	root = new type;
	root->next = 0;
	for (int i = 0; i < 5; i++)
		generatebunny(0);
	printbunny();
	do{
		gathervalue();
		spawnbunny();
		infestbunny();
		killbunny();
		turn++;
		if (malecount + femalecount >= 1000)
			overflowbunny((malecount + femalecount) / 2);
		std::cout << "\nTurn " << turn << std::endl;
		insertfile("\nTurn ", 3, turn);
		printbunny();
		std::cout << "Turn " << turn << std::endl;
		std::cout << "Amount of bunnies is " << malecount+ femalecount<< std::endl;
		insertfile("Turn ", 3, turn);
		insertfile("\nAmount of bunnies is ", 3, malecount + femalecount);
	} while (malecount + femalecount != 0);

	std::cout << "\nHow sad, no bunnies to be seen." << std::endl;
	insertfile("\nHow sad, no bunnies to be seen.", 3, 0);
	return 0;
}

void printbunny() {
	adress = root->next;
	if (adress != 0)
		for (int i = 50; i >= 0; i--) {
			while (adress != nullptr) {
				if (adress->age == i) {
					std::string val = (adress->rmvb == true) ? "Positive" : "Negative";
					std::cout << "Age " << adress->age << "\t| Name " << adress->name << "\t| Sex " << adress->sex << "\t| Color " << adress->color << "\t| Radioactive mutant vampire = " << val << "\t|\n";
					output.open("console output.txt", std::ios::app);
					output << "Age " << adress->age << "\t| Name " << adress->name << "\t| Sex " << adress->sex << "\t| Color " << adress->color << "\t| Radioactive mutant vampire = " << val << "\t|\n";
					output.close();
				}
				adress = adress->next;
			}
			adress = root->next;
		}
	sleep;
	sleep;
}

void generatebunny(int phase) {
	
	//Locates latest list
	adress = root;
	if (adress != 0)
		while (adress->next != nullptr)
			adress = adress->next;
	adress->next = new type;
	adress = adress->next;
	adress->next = 0;
	adress->age = 0;
	//Names
	random = rand() % 10;
	switch (random) {
	case 0:
		adress->name = "Gordon";
		break;
	case 1:
		adress->name = "Brotato";
		break;
	case 2:
		adress->name = "SprEagle";
		break;
	case 3:
		adress->name = "JohnCena";
		break;
	case 4:
		adress->name = "Arnold";
		break;
	case 5:
		adress->name = "Olegna";
		break;
	case 6:
		adress->name = "Lamp";
		break;
	case 7:
		adress->name = "Dolfyn";
		break;
	case 8:
		adress->name = "Temmie";
		break;
	case 9:
		adress->name = "MiBigBut";
		break;
	}
	rmvb = (adress->rmvb == true)? "Radioactive mutant vampire bunny ": "Bunny ";
	std::cout << rmvb << adress->name << " was born!" << std::endl;
	insertfile(" was born!\n", 2, 0);
	sleep;
	//Sex
	random = rand() % 2;
	switch (random)	{
	case 0:
		adress->sex = "Male";
		break;
	case 1:
		adress->sex = "Female";
		break;
	}
	//Color
	if (phase == 0) {
	random = rand() % 4;
	switch (random) {
	case 0:
		adress->color = "white";
		break;
	case 1:
		adress->color = "brown";
		break;
	case 2:
		adress->color = "black";
		break;
	case 3:
		adress->color = "spotted";
		break;
	}
	}
	else 
		adress->color = female->color; 
	//rmvb
	random = rand() % 100 + 1;
	if (random <= 2)
		adress->rmvb = true;
	else
		adress->rmvb = false;
}

void spawnbunny() {
	female = root;
	adress = root;

	if (adress != 0)
		while (female->next != nullptr) {
			female = female->next;
			if (female->sex == "Female" && female->age >= 2 && female->rmvb == false)
				generatebunny(1);
		}
}

void gathervalue(){
	count = 0;
	rmvbammount = 0;
	malecount = 0;
	femalecount = 0;
	adress = root->next;
	if (adress != 0)
		while (adress != nullptr) {
			adress->age++;
			if (adress->sex == "Male")
				malecount++;
			if (adress->sex == "Male" && adress->age >= 2)
				Mmalecount++;
			if (adress->sex == "Female")
				femalecount++;
			if (adress->sex == "Female" && adress->age >= 2)
				Mfemalecount++;
			if (adress->rmvb == true)
				rmvbammount++;
			adress = adress->next;
		}
}

void killbunny() {
	adress = root->next;
	if (adress != 0)
		while (adress != nullptr) {
			if (adress->age == 10 && adress->rmvb == false ) {
				std::cout << "Bunny " << adress->name << " died of age!" << std::endl;
				adress = adress->next;
				delete female->next;
				female = adress;
				sleep;
			}
			else if (adress->age == 50 && adress->rmvb == true) {
				std::cout << "Bunny " << adress->name << " died of age!" << std::endl;
				adress = adress->next;
				delete female->next;
				female = adress;
				sleep;
			}
			adress = adress->next;
		}
}

void infestbunny() {
	adress = root->next;
	if (adress != 0)
		while (adress != nullptr && rmvbammount > 0) {
			if (adress->rmvb == false) {
				adress->rmvb = true;
				std::cout << "Bunny " << adress->name << " became a radioactive mutant vampire bunny!" << std::endl;
				insertfile("became a radioactive mutant vampire bunny!\n", 0, 0);
				rmvbammount--;
				sleep;
			}
			adress = adress->next;
		}
}

void overflowbunny(int total) {
	std::cout << "Oh no! There is an abundance of bunny which leeds to a shortage of food! " << total << " Bunnies are dying!";
	insertfile("Oh no! There is an abundance of bunny which leeds to a shortage of food! ", 1, total);
	sleep;
	adress = root->next;
	for (total; total >= 0; total--) {
		random = rand() % 1;
		while (adress != nullptr) {
			female = adress;
			if (random == 0) {
				std::cout << "Bunny " << adress->name << " died of food shortage!" << std::endl;
				insertfile(" died of food shortage!\n", 0, 0);
				adress = adress->next;
				delete female->next;
				break;
			}
			adress = adress->next;
		}
	}
}

void insertfile(std::string line, int eventkind, int ammount) {
	output.open("console output.txt", std::ios::out | std::ios::app);
	if (eventkind == 0)
		output << "Bunny" << adress->name << line;
	else if (eventkind == 1)
		output << line << ammount << "Bunnies are dying!\n";
	else if (eventkind == 2)
		output << rmvb << adress->name << line;
	else if (eventkind == 3)
		output << line;
	output.close();
}
