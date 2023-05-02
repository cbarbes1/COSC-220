/*
Author: Cole Barbes
Creation Date: 04/14/23
Last Update: 04/14/23
Description: This header file declares a stack class using a Linked list, all implementation is contained in this file
*/
#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T> class Stack { // define stack class
    private:
        LinkedList<T> stack; // define the list

    public:
        Stack(); // constructor
        ~Stack(); // destructor
        void displayStack(bool nl = false) const; // display the stack

        Stack(const Stack &obj); // copy constructor 
        const Stack operator=(const Stack &right); // overloaded equals

        void clear(); // clear the stack
        int size(); // return the size
        void push(T); // push an item on the stack
        T pop(); // return the value of the last element
        bool isEmpty(); // return whether the list is empty or not
};

/*
Description: Constructor
*/
template <class T>
Stack<T>::Stack()
{

}

/*
Description: Display the stack 
*/
template <class T>
void Stack<T>::displayStack(bool n1) const
{

    stack.displayList(n1);
}

/*
Description: Copy another stacks contents 
Parameters: The other stack object
*/
template <class T>
Stack<T>::Stack(const Stack &obj)
{
    stack = obj.stack;
}

/*
Description: overload the equals to copy all contents of another stack
Parameters: the right hand stack
Return: the stack
*/
template <class T>
const Stack<T> Stack<T>::operator=(const Stack &right)
{
    stack = right.stack;
    return *this;
}

/*
Description: use the linked list clear function to empty the stack
*/
template <class T>
void Stack<T>::clear(){
    stack.clear();
}

/*
Description: return the size of the stack
return an integer value of the length
*/
template <class T>
int Stack<T>::size()
{
    return stack.length();
}

/*
Description: use the linked list push front function to push an item onto the stack
Parameters: The item being placed onto the stack
*/
template <class T>
void Stack<T>::push(T item)
{
    stack.push_front(item);
}

/*
Description: pop the top value and return it
*/
template <class T>
T Stack<T>::pop()
{
    return stack.pop_front();
}

/*
Description: return a boolean value of whether the list is empty  or not
*/
template <class T>
bool Stack<T>::isEmpty()
{
    if(stack.length() == 0){
        return true;
    }else{
        return false;
    }
}

/*
Description: destructor to clear the list using the clear function
*/
template <class T>
Stack<T>::~Stack()
{
    clear();
}

#endif