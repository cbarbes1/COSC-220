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
        PQNode<T>& operator[](const int &);

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
    if (queue.empty()) {
		T defaultObj;
		return defaultObj;
	}

	int maxpriority = 0;
	for (unsigned int i = 0; i < queue.size(); i++)
		if (maxpriority < queue[i].priority)
			maxpriority = queue[i].priority;

	int pos = 0;
	while (maxpriority != queue[pos].priority)
		pos++;

	T saveData = queue[pos].data;
	queue.erase(queue.begin() + pos);
	return saveData; 
}
/*
Description: This function simply returns an read write reference to a var
*/
template<class T>
PQNode<T>& PriorityQueue<T>::operator[](const int &pos)
{
    if (pos < 0)
		return queue[0];

	if (pos >= queue.size())
		return queue[queue.size() - 1];

	return queue[pos];
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
