/*
Author: Cole Barbes
Creation Date: 04/14/23
Last Update: 04/14/23
Description: This header file declares a queue class using a Linked list, all implementation is contained in this file
*/
#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T> class Queue { //define queue class
    private:
        LinkedList<T> queue; // define the list

    public:
        Queue();// default constructor
        ~Queue(); // destructor
        void displayQueue(bool nl = false) const; // display the list

        Queue(const Queue &obj); // copy constructor for the list
        const Queue operator=(const Queue &right); // overloaded equals sign

        void clear(); // clear function to empty the list
        int size(); // return size of the queue
        void enqueue(T); // place an item into the queue at the back
        T dequeue(); // take something off the front of the queue
        bool isEmpty(); // determine if the queue is empty
};

// Constructor
template <class T>
Queue<T>::Queue()
{

}

/*
Description: Displays the queue
Parameters: boolean of whether to print
*/
template <class T>
void Queue<T>::displayQueue(bool n1) const
{
    queue.displayList(n1);
}

/*
Description: Copy constructor for the queue
Parameters: The other queue
*/
template <class T>
Queue<T>::Queue(const Queue &obj)
{
    queue = obj.queue;
}

/*
Description: overloaded equals sign to set one queue to the other
Parameters: the right hand queue 
Return: return this queue
*/
template <class T>
const Queue<T> Queue<T>::operator=(const Queue &right)
{
    queue = right.queue;
    return *this;
}

/*
Description: clear the queue
*/
template <class T>
void Queue<T>::clear()
{
    queue.clear();
}

/*
Description: get the size of the queue
Return: return the size of the queue
*/
template <class T>
int Queue<T>::size()
{
    return queue.length();
}

/*
Description: Enqueue an item onto the queue
Parameters: the item to be added
*/
template <class T>
void Queue<T>::enqueue(T item)
{
    queue.push_back(item);
}

/*
Description: This function dequeues the first item on the list FIFO
Return: The Item on the front of the list
*/
template <class T>
T Queue<T>::dequeue()
{
    return queue.pop_front();
}

/*
Description: Simply Check if the queue is empty
Return: boolean true or false whether the queue is empty
*/
template <class T>
bool Queue<T>::isEmpty()
{
    if(queue.length() == 0){
        return true;
    }else{
        return false;
    }
}

/*
Description: destructor clear all used memory using clear
*/
template <class T>
Queue<T>::~Queue()
{
    clear();
}
#endif