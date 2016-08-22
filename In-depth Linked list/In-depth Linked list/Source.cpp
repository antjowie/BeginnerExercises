#include <iostream>
#include <string>
#include <sstream>

struct Music {
	int number;
	std::string title;
	Music * next;
};



Music * head = new Music;
Music * next;
Music * destructor;
std::string name;
int number;
int total = 0;
int newnumber;

void add(const std::string &title);
void remove(const std::string &title = "nullptr", const int &number = 0);
void list(int phase = 1);

int	main() {
	do {
		std::cout << "Make a choice by index\n 0 - Exit\t1 - Add song\t2 - Remove song\t3 - list songs\n";
		std::cin >> number;
		std::cin.ignore();
		//Main menu
		switch (number) {
		case 0:
			break;
		case 1:
			std::cout << "Enter the name of the song" << std::endl;
			std::getline(std::cin, name);
			add(name);
			break;
		case 2:
			std::cout << "Make a choice by index\n 0 - Type name\t1 - Type index\n";
			list();
			std::cin >> number;
			switch (number) {
			case 0:
				std::getline(std::cin, name);
				remove(name);
				break;
			case 1:
				std::cin >> number;
				remove("",number);
				break;
			default:
				std::cout << "Incorrect value!\n";
			}
		case 3:
			list();
			break;
		default:
			std::cout << "Incorrect value!\n";
		}
	} while (number != 0);
	return 0;
}

void add(const std::string &title) {
	list();
	next = new Music;
	next->title = title;
	list(2);
	total++;
}

void remove(const std::string &title, const int &number) {
	list();
	//Initiates phase 3
	if (title != "nullptr")
		list(3);
	else
		list(4);
}

void list(int phase) {
	//phase 1 prints linked lists
	//phase 2 insert number value during function add
	//phase 3 remove by index
	//phase 4 remove by string
	next = head->next;
	if (next != nullptr && phase == 1 || phase == 2)
		for (int i = 1; i <= total; i++)
			while (next != nullptr) {
				if (next->number == i && phase == 1)
					std::cout << next->number << " - " << next->title << std::endl;
				else if (phase == 2){
					if (i != next->number){
						newnumber = i;
						break;
					}
				}
				else if (phase == 3 || phase == 4) {
					destructor = next;
					if (next->number == number && phase == 3 || next->title == name && phase == 4) {
						delete destructor;
						break;
					}
				}
				next = next->next;
			}
}