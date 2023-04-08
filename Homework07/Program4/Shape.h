/*
 Author: Don Spickler
 Creation Date: 1/26/2022
 Last Update: 1/26/2022
 Description: Specification for the Shape class.
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include <string>

using namespace std;

class Shape {
protected:
	string name;  // Name of the shape
	string color; // Color of the shape.

public:
	Shape(string n = "", string c = "Red");
	virtual ~Shape();

	string getName();
	void setName(string);

	virtual double Area() = 0;
	virtual void draw() = 0;
};

#endif /* SHAPE_H_ */
