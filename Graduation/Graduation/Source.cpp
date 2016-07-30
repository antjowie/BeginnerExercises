#include <iostream>
#include <string>	
#include <time.h>

//TODOLIST
//count fixen = mutated en normaal splitsen
//main fixen




struct type {
	int age;
	std::string name;
	std::string sex;
	std::string color;
	bool rmvb;
	type *next;
}*root, *adress, *female;

int rmvbammount = 0;
int count = 0;
int malecount = 0;
int femalecount = 0;

void printbunny();
void generatebunny(int phase);
void spawnbunny();
void gathervalue();
void killbunny();
void infestbunny();
int main() {

//Initialize 5 starting bunnys
	srand(time(0));
	root = new type;
	root->next = 0;
	for (int i = 0; i < 5; i++)
		generatebunny(0);
	printbunny();
	do{
		gathervalue();
		if (malecount >= 1 && femalecount >= 1)
			for (femalecount; femalecount >= 0; femalecount--)
				spawnbunny();
		printbunny();
	} while (malecount + femalecount != 0);

	std::cout << "How sad, no bunnies to be seen." << std::endl;
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
				}
				adress = adress->next;
			}
			adress = root->next;
		}
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
	int random = rand() % 10;
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
	std::string rmvb = (adress->rmvb == true)? "Radioactive mutant vampire bunny ": "Bunny ";
	std::cout << rmvb << adress->name << " was born!" << std::endl;
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
			if (female->sex == "Female")
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
			else
				femalecount++;
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
				std::cout << "Bunny " << adress->name << " died of age!";
				delete adress->next;
				adress = root;
			}
			else if (adress->age == 50 && adress->rmvb == true) {
				std::cout << "Bunny " << adress->name << " died of age!";
				delete adress->next;
				adress = root;
			}
			adress = adress->next;
		}
}

void infestbunny() {
	adress = root->next;
	if (adress != 0)
		while (adress != nullptr && rmvbammount >= 0) {
			if (adress->rmvb == false) {
				adress->rmvb = true;
				std::cout << "Bunny " << adress->name << " became a radioactive mutant vampire bunny!";
				rmvbammount--;
			}
			adress = adress->next;
		}
}
