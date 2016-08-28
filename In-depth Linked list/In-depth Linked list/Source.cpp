#include <iostream>
#include <string>
#include <sstream>

struct song {
	int number;
	std::string title = "HEAD";
	song *next = nullptr;
}*root, *list;

void addSong(const std::string &title, int &total);
void removeSong(const int &number, const std::string &title, int &total);
void listSongs(const int &total);

int main() {
	int input;
	int total = 0;
	std::string title;
	root = new song;
	do {
		std::cout << "\nSelect by index...\n"
			<< "1 - add song.\n"
			<< "2 - remove song.\n"
			<< "3 - list songs.\n"
			<< "0 - quit program.\n";
		std::cin >> input;
		switch (input) {
		case 0:
			std::cout << "\nExiting program...\n";
			break;
		case 1:
			std::cout << "\nEnter title...\n";
			std::cin.ignore();
			std::getline(std::cin, title);
			addSong(title,total);
			break;
		case 2:
			if (total > 0) {
				std::cout << "\nSelect by index...\n"
					<< "1 - remove song by title.\n"
					<< "2 - remove song by number.\n";
				std::cin >> input;
				listSongs(total);
				switch (input) {
				case 1:
					std::cout << "\nEnter title...\n";
					std::cin.ignore();
					std::getline(std::cin, title);
					input = 0;
					break;
				case 2:
					std::cout << "Enter number...\n";
					std::cin >> input;
					break;
				default:
					std::cout << "(ERROR) entered invalid value!\n";
					break;
				}
				removeSong(input, title, total);
				input = 3;
			}
			else
				std::cout << "\nNo songs to be found...\n";
			break;
		case 3:
			listSongs(total);
			break;
		default:
			std::cout << "(ERROR) entered invalid value!\n";
			break;
		}
	} while (input != 0);
	return 0;
}

void addSong(const std::string &title, int &total) {
	list = root;
	while (list->next != nullptr)
		list = list->next;
	list->next = new song;
	list = list->next;
	list->title = title;
	total++;
}

void removeSong(const int & number, const std::string & title, int & total){
	song * destructor;
	destructor = root;
	//runs remove title program
	if (number == 0) {
		while (destructor->title != title) {
			list = destructor;
			destructor = destructor->next;
			if (destructor == nullptr) {
				std::cout << "\n(ERROR) entered invalid title! try by index.\n";
				return;
			}
		}
	}
	else 
		while (destructor->number != number) {
			list = destructor;
			destructor = destructor->next;
			if (destructor == nullptr) {
				std::cout << "\n(ERROR) entered invalid number! try a lower number.\n";
				return;
			}
		}
	std::cout << "\nRemoved\n" << destructor->number << "\t|\t" << destructor->title << "\nSuccessfully!\n";
	//runs remove middle node program if the song isn't the last one
	if (destructor->next != nullptr)
		list->next = list->next->next;
	delete destructor;
}

void listSongs(const int &total) {
	if (total != 0) {
		std::cout << std::endl;
		int counter = 1;
		list = root->next;
		while (list != nullptr) {
			list->number = counter;
			std::cout << list->number << "\t|\t" << list->title << '\n';
			counter++;
			list = list->next;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "\nNo songs to be found...\n";
	}