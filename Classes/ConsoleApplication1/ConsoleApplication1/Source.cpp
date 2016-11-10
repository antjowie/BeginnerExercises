#include <iostream>

// Classes part 1 and 2 summed up
/*
class Rectangle{
	int width, heigth;
public:
	// Overload operator+
	Rectangle operator+ (const Rectangle&);
	
	// Default constructor
	Rectangle(int x, int y) : width(x), heigth(y) { }
	Rectangle() : width(0), heigth(0) { }
	
	// Disabling explict functions
		// Copy constructor
	Rectangle(const Rectangle&) = default;
		// Move constructor
	//Rectangle(const Rectangle&&) = delete;
		// Used for backwards compatibility

	// Return values
	int area() {return (width*heigth);}
};

Rectangle Rectangle::operator+(const Rectangle& param) {
		Rectangle temp;
		temp.width = width + param.width;
		temp.heigth = heigth + param.heigth;
		return temp;
}

int main() {
	Rectangle a(3, 2);
	Rectangle b(4, 3);
	Rectangle c = a + b;
	std::cout << "Rectangle a: " << a.area()
			  << "\nRectangle b: " << b.area()
		      << "\nRectangle c: " << c.area() << std::endl;
	
	return 0;
}
*/

// Inheritance
/*

// Base class
class Shapes {
protected:
	int width, length;
public:
	Shapes(int x, int y) : width(x), length(y) {}
};

class Square : public Shapes {
public:
	Square (int x, int y) : Shapes (x,y) {}
	int area() 
	{ return width*length; }
};

class Triangle : public Shapes {
public:
	Triangle(int x, int y) : Shapes(x,y) {}
	int area()
	{ return width*length / 2; }
};

int main() {
	Square squ1(10,5);
	Triangle tri1(2,5);
	std::cout << "Square 1: " << squ1.area()
			<< "\nTriangle 1: " << tri1.area() << std::endl;
	return 0;
}
*/

// Polymorphism


// Base class
class Shapes {
protected:
	int width, length;
public:
	Shapes(int x, int y): width(x), length(y) {}

	// Virtual allows us to acces area in every derived class. It can also be redefined in them

	
	// This makes our base class an abstract class meaning it can no longer declare objects but it can be pointed to.
	virtual int area() = 0;
	void printarea() 
		{ std::cout << this->area() << '\n'; }
};

class Square : public Shapes {
public:

	//Constructor will be linked to Shapes his constructor
	Square(int x, int y) : Shapes(x,y) {}
	int area()
		{ return width*length; }
};

class Triangle : public Shapes {
public:
	Triangle(int x, int y) : Shapes(x,y) {}
	int area()
		{ return width*length/2; }
};

int main() {
	/*
	Square squ1;
	Triangle tri1;
	Shapes* ptr1 = &squ1;
	Shapes* ptr2 = &tri1;
	ptr1->set_values(2, 4);
	ptr2->set_values(5, 10);
	*/
	// Because of polymorphism every derived class can be made by pointers

	Shapes* rect = new Square(5, 4);
	Shapes* tria = new Triangle(5, 4);
	rect->printarea();
	tria->printarea();
	delete rect;
	delete tria;
	return 0;
}
