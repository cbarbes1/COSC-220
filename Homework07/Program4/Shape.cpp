/*
 Author: Don Spickler
 Creation Date: 1/26/2022
 Last Update: 1/26/2022
 Description: Implementation for the Shape class.
 */

#include <iostream>

#include "Shape.h"

using namespace std;

/*
 Description: Constructor
 Parameters: n - name of the shape.
 c - color of the shape.
 Return: None
 */

Shape::Shape(string n, string c) {
	name = n;
	color = c;
}

/*
 Description: Destructor
 Parameters: None
 Return: None
 */

Shape::~Shape() {
}

/*
 Description: Extracts the name of the shape.
 Parameters: None
 Return: Name of the shape as a string type.
 */

string Shape::getName() {
	return name;
}

/*
 Description: Sets the name of the shape.
 Parameters: n - name of the shape.
 Return: None
 */

void Shape::setName(string n) {
	name = n;
}
