/*
 Author: Don Spickler
 Creation Date: 1/26/2022
 Last Update: 1/26/2022
 Description: Implementation for the Rectangle class.
 */

#include <iostream>

#include "Rectangle.h"

using namespace std;

/*
 Description: Constructor
 Parameters: w - width of the rectangle.
 h - height of the rectangle.
 c - color.
 Return: None
 */

Rectangle::Rectangle(double w, double h, string c) :
		Shape("Rectangle", c) {
	width = w;
	height = h;

	// Not needed for the class, just an example for memory leaks.
	dumb = new int[1000];
}

/*
 Description: Destructor
 Parameters: None
 Return: None
 */

Rectangle::~Rectangle() {
	delete [] dumb;
}

/*
 Description: Calculates the area of the rectangle.
 Parameters: None
 Return: Value of the area of the rectangle.
 */

double Rectangle::Area() {
	return width * height;
}

/*
 Description: Calculates the perimeter of the rectangle.
 Parameters: None
 Return: Value of the perimeter of the rectangle.
 */

double Rectangle::Perimeter() {
	return 2 * (width + height);
}

/*
 Description: Draws the rectangle, that is, prints out information about the
 rectangle to show that the function was called.
 Parameters: None
 Return: None
 */

void Rectangle::draw() {
	cout << "Drawing Rectangle --- ";
	cout << "Name: " << name << " : "; // Class now has access to name.
	// cout << "Name: " << getName() << " : ";
	cout << "Attributes: " << width << " X " << height << "  Area = " << Area();
	cout << "   Color: " << color << endl;
}

