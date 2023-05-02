/*
 Author: Don Spickler
 Creation Date: 1/26/2022
 Last Update: 1/26/2022
 Description: Specification for the Triangle class.
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Shape.h"

class Triangle: public Shape {
private:
	double sides[3];

public:
	Triangle(double a = 1, double b = 1, double c = 1, string col = "Red");
	virtual ~Triangle();  // virtual tag not needed but good practice to include.

	double Perimeter();
	bool isTriangle();

	double Area();
	void draw();
};

#endif /* TRIANGLE_H_ */
