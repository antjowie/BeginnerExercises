#include <iostream>
#include <string>

void say_hello(int a) {
	for (a; a > 0; a--)
		std::cout << "Hello" << std::endl;
}

int addup(int a, int b) {
	return (a + b);
}

void half(int a) {
	std::cout << a << std::endl;
	a /= 2;
	if (a > 0)
		half(a);
}

int main() {
	half(100);
	return 0;
}