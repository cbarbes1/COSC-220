/*
 Author: Don Spickler
 Creation Date: 1/26/2022
 Last Update: 1/26/2022
 Description: Implementation for the Square class.
 */

#include <iostream>

#include "Square.h"

using namespace std;

/*
 Description: Constructor
 Parameters: s - Side length.
 c - Color
 Return: None
 */

Square::Square(double s, string c) :
		Rectangle(s, s, c) {
	// No other assignments needed.
}

/*
 Description: Destructor
 Parameters: None
 Return: None
 */

Square::~Square() {
}

/*
 Description: Draws the rectangle, that is, prints out information about the
 rectangle to show that the function was called.
 Parameters: None
 Return: None
 */

void Square::draw() {
	cout << "Drawing Square --- ";
	cout << "Name: " << name << " : "; // Class now has access to name.
	//  cout << "Name: " << getName() << " : ";
	cout << "Attributes: " << width << " X " << height << "  Area = " << Area();
	cout << "   Color: " << color << endl;
}

