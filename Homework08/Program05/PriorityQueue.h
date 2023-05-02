/*
Author: Cole Barbes
Creation Date: 04/16/23
Last Update: 04/16/23
Description: This file implements a priority queue
*/
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <vector>
#include <iterator>

/*8 Templated Priority Queue class that uses the STL vector as the underlying storage
structure.

Note: The template class T must
1. overloaded =
2. Have a default constructor
3. Overloaded >>
4. Copy Constructor
 */

using namespace std;

// Node data type that holds the data and priority of the item.

template<class T>
class PQNode {
    public:
        T data;
        int priority;

        PQNode(T Data) {
            data = Data;
            priority = 1;
        }

        PQNode(T Data, int Priority) {
            data = Data;
            if (Priority < 1)
                Priority = 1;

            priority = Priority;
        }
};

template<class T>
class PriorityQueue {
    private:
        vector<PQNode<T> > queue; // The vector holding all of the items in the queue.

    public:
        // Constructors and Destructor
        PriorityQueue();
        PriorityQueue(const PriorityQueue &obj);
        ~PriorityQueue();
        // Acessors and Mutators
        void enqueue(T Data, int Priority = 1);
        T dequeue();

        // Other Functions
        void print();
        bool isEmpty();
        void clear();
        int size();
};

/*Description: Constructor
*/
template<class T> 
PriorityQueue<T>::PriorityQueue()
{  
}

/*
 * Description: Copy constructor
 * Parameters: The queue to be copied
 */
template<class T> 
PriorityQueue<T>::PriorityQueue(const PriorityQueue &obj)
{
    queue = obj.queue;
}

/*
 * Description: This function places data at the end of the queue and sets its priority
 * Parameters: The data to be added and the priority
 */
template<class T> 
void PriorityQueue<T>::enqueue(T data, int priority)
{
    PQNode<T> temp(data, priority);
    queue.push_back(temp);
}

/*
 * Description: This function takes the item with the highest priority first
 * return the value 
 */
template<class T>
T PriorityQueue<T>::dequeue()
{
    T temp = T(); // initialize the Templated value
    if(isEmpty()){ // if the list is empty return the temp item
        return temp;
    }else{ 
        int max_priority = 1; // set the max priority to the default priority
	// linear search for the highest priority item
        for(unsigned int i = 1; i<queue.size(); i++){
            if(queue[i].priority > max_priority)
                max_priority = queue[i].priority;
        }

        typename vector<PQNode<T>>::iterator it; // create the iterator 
        for(it = queue.begin(); it!=queue.end(); it++){// move the iterator through the list
            if((*it).priority == max_priority){// if the iterator priority is equal to the max
                temp = (*it).data; // hold the value to be returned
                queue.erase(it); // erase the value at the iterator
                return temp;
            }
        }
    }
    return temp; 
}

/*
 * Description: This function simply prints the queue 
 */
template<class T>
void PriorityQueue<T>::print()
{
    for(unsigned int i = 0; i<queue.size(); i++){
        cout<<queue[i].data<<" --- "<<queue[i].priority<<endl; 
    }
}

/*
 * Description: This function checks whether the queue is empty
 * Return: a boolean value true if the queue is empty and false if not empty
 */
template<class T>
bool PriorityQueue<T>::isEmpty()
{
    return queue.empty();
}

/*
 * Description: This function Clears all items out of the queue
 */
template<class T>
void PriorityQueue<T>::clear()
{
    queue.clear();
}

/*
 * Description: This function Gets the size of the queue
 * Return: an integer size
 */
template<class T>
int PriorityQueue<T>::size()
{
    return queue.size();
}

/*
 * Description: This function uses the clear function to delete the queue
 */
template<class T> 
PriorityQueue<T>::~PriorityQueue()
{
    clear();
}

#endif
