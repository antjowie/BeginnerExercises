#include <iostream>
#include <string>

std::string replacechar(std::string a) {
	for (int i = a.size(); i > 0; i--) {
		if (a[i] == 'a')
			a[i] = 'z';
		else if (a[i] == 'e')
			a[i] = 'z';
		else if (a[i] == 'i')
			a[i] = 'z';
		else if (a[i] == 'o')
			a[i] = 'z';
		else if (a[i] == 'u')
			a[i] = 'z';
	}
	return a;
}

std::string combinestring(std::string a, std::string b) {
	return (a + " " + b);
}

std::string reverse(std::string a) {
	
	std::string temp = a;
	int j = 0;
	for (int i = a.size() - 1; i > j ; i--, j++){
		temp[j] = a[i];
		temp[i] = a[j];
	}
	return temp;
}

int main() {
	std::string first, last;
	std::cout << "First name: ";
	std::getline(std::cin, first);
	std::cout << "Last name: ";
	std::getline(std::cin, last);
	
	std::cout << reverse(combinestring(first, last)) << std::endl;
	return 0;
}