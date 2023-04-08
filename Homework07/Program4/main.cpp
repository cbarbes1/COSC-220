/*
Author: Cole Barbes
Creation Date: 04/07/23
Last Update: 04/07/23
Description: This program polymorphs a shape class using a linked list of pointers

*/
// include the necessary h files
#include "LinkedList.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0)); // seed the rand

    int numData  = 0;// create var to hold user request
    int choice = 0; // var for the choice

    // take user request 
    cout<<"How many objects would you like to store? ";
    cin>>numData;

    LinkedList<Shape*> ShapeList; // create the linked list to hold the shapes

    // for loop to traverse the list adding pointers to a triangle 
    for(int i = 0; i<numData; i++){
        choice = (rand()%2);
        if(choice == 0){ // if rand selection 0 set a triangle
            Triangle *Item = new Triangle(((rand()%10)+5), ((rand()%10)+5), ((rand()%10)+5));
            ShapeList.push_back(Item);
        }else if(choice ==1){ // if rand selection 1 set a rectangle
            Rectangle *Item = new Rectangle(((rand()%10)+5), ((rand()%10)+5));
            ShapeList.push_back(Item);
        }else{ // if rand selection 2 set a square
            Square *Item = new Square(((rand()%10)+5));
            ShapeList.push_back(Item);
        }
    }

    // for loop to traverse the list and draw each shape
    for(int i = 0; i<numData; i++){
        ShapeList[i]->draw();
    }

    // for loop to traverse the list and delete each shape
    for(int i = 0; i<numData; i++){
        delete ShapeList[i];
    }


    return 0;
}