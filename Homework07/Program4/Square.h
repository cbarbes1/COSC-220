/*
 Author: Don Spickler
 Creation Date: 1/26/2022
 Last Update: 1/26/2022
 Description: Specification for the Square class.
 */

#ifndef SQUARE_H_
#define SQUARE_H_

#include "Rectangle.h"

class Square : public Rectangle {
public:
	Square(double s = 0, string c = "Red");
	virtual ~Square(); // virtual tag not needed but good practice to include.

	void draw();
};

#endif /* SQUARE_H_ */
