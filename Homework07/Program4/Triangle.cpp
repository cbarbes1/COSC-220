/*
 Author: Don Spickler
 Creation Date: 1/26/2022
 Last Update: 1/26/2022
 Description: Implementation for the Triangle class.
 */

#include <cmath>
#include <iostream>

#include "Triangle.h"

using namespace std;

/*
 Description: Constructor
 Parameters: a - Side A length.
 b - Side B length.
 c - Side C length.
 col - color.
 Return: None
 */

Triangle::Triangle(double a, double b, double c, string col) :
		Shape("Triangle", col) {
	sides[0] = a;
	sides[1] = b;
	sides[2] = c;
}

/*
 Description: Destructor
 Parameters: None
 Return: None
 */

Triangle::~Triangle() {
}

/*
 Description: Determines if the side lengths create a legitimate triangle.
 Parameters: None
 Return: True if the sides create a triangle and false otherwise.
 */

bool Triangle::isTriangle() {
	double max = sides[0];
	if (max < sides[1])
		max = sides[1];
	if (max < sides[2])
		max = sides[2];

	double sumsides = Perimeter() - max;
	if (max <= sumsides)
		return true;
	else
		return false;
}

/*
 Description: Calculates the perimeter of the triangle.
 Parameters: None
 Return: Value of the perimeter of the triangle.
 */

double Triangle::Perimeter() {
	return sides[0] + sides[1] + sides[2];
}

/*
 Description: Calculates the area of the triangle.
 Parameters: None
 Return: Value of the area of the triangle.
 */

double Triangle::Area() {
	double sp = Perimeter() / 2;
	return sqrt(sp * (sp - sides[0]) * (sp - sides[1]) * (sp - sides[2]));
}

/*
 Description: Draws the triangle, that is, prints out information about the
 triangle to show that the function was called.
 Parameters: None
 Return: None
 */

void Triangle::draw() {
	cout << "Drawing Triangle --- ";
	cout << "Name: " << name << " : "; // Class now has access to name.
	//cout << "Name: " << getName() << " : "; // Old code line.
	cout << "Attributes: <" << sides[0] << ", " << sides[1] << ", " << sides[2]
			<< ">   Area = " << Area();
	cout << "   Color: " << color << endl;
}

