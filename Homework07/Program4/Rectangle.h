/*
 Author: Don Spickler
 Creation Date: 1/26/2022
 Last Update: 1/26/2022
 Description: Specification for the Rectangle class.
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"

class Rectangle : public Shape {
private:
	int *dumb;

protected:
	double width;  // Width of the rectangle.
	double height;  // Height of the rectangle.

public:
	Rectangle(double w = 0, double h = 0, string c = "Red");
	virtual ~Rectangle();  // virtual tag not needed but good practice to include.

	double Perimeter();

	double Area();
	void draw();
};

#endif /* RECTANGLE_H_ */
