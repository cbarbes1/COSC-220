/*
    Name          : Die.cpp
    Author        : Don Spickler
    Creation Date : 1/21/2022
    Last Update   : 1/21/2022
    Description   : Implememtation file for the Die class.
*/

#include <cstdlib>     // For rand and srand

#include "Die.h"

using namespace std;

/*
    Description: Constructor
    Parameters: numSides - Number of sides to the die.
    Return: None
    Note: This implementation requires the RNG seed to be set in the main, or at
    least before this class is instantiated.
*/

Die::Die(int numSides) {
    // Set the number of sides.
    sides = numSides;

    // Perform an initial roll.
    roll();
}

/*
    Description: Roll function that will roll the die and store the value.
    Parameters: None
    Return: None
*/

void Die::roll() {
    // Get a random value for the die.
    value = (rand() % sides) + MIN_VALUE;
}

/*
    Description: Accessor for the number of sides of the die.
    Parameters: None
    Return: Number of sides of the die.
*/

int Die::getSides() const {
    return sides;
}

/*
    Description: Accessor for the value of the last roll.
    Parameters: None
    Return: Value of the last roll.
*/

int Die::getValue() const {
    return value;
}

