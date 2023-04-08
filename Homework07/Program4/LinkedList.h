// A class template for holding a linked list.
// The node type is also a class template.
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

using namespace std;

//*********************************************
// The ListNode class creates a type used to  *
// store a node of the linked list.           *
//*********************************************

template<class T>
class ListNode {
public:
	T value;           // Node value
	ListNode<T> *next; // Pointer to the next node

	// Constructor
	ListNode(T nodeValue);
};
// Constructor
template<class T>
ListNode<T>::ListNode(T nodeValue) {
	value = nodeValue;
	next = nullptr;
}

//*********************************************
// LinkedList class                           *
//*********************************************

template<class T>
class LinkedList {
private:
	ListNode<T> *head;   // List head pointer
	ListNode<T> *tail;

public:
	// Constructor
	LinkedList();
	LinkedList(const LinkedList<T>&);
	LinkedList<T>& operator=( const LinkedList<T>&);

	// Destructor
	~LinkedList();

	T& operator[](int);

	// Linked list operations
	void push_back(T);
	void insertNode(T);
	void deleteNode(T);
	void displayList() const;
	void push_front(T);
	T pop_front();
	T peakHead();
	T peakTail();
	void clear();
	
	T get(int);
	void set(int, T);
	int length();
};

//**************************************************
// Constructor for the linked list class           *
//**************************************************
template<class T>
LinkedList<T>::LinkedList() {
		head = nullptr;
		tail = nullptr;
}


//**************************************************
// Copy Constructor for the Linked List class      *
// Takes another linked list as a reference        *
//**************************************************
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
	ListNode<T> *nodePtr;

	nodePtr = other.head; // init ptr to the head

	
	head = nullptr;
	tail = nullptr;
	
	while(nodePtr != nullptr){
		push_back(nodePtr->value);
		nodePtr = nodePtr->next;

	}
}

//**************************************************
// overloaded equals for the Linked List class     *
// Takes another linked list as a reference        *
//**************************************************
template<class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T>& right)
{
	clear();
	ListNode<T> *nodePtr;

	nodePtr = right.head;
	
	while(nodePtr != nullptr){
		push_back(nodePtr->value);
		nodePtr = nodePtr->next;
	}	
	return *this;
}



//**************************************************
// appendNode appends a node containing the value  *
// pased into newValue, to the end of the list.    *
//**************************************************

template<class T>
void LinkedList<T>::push_back(T newValue) {
	ListNode<T> *newNode;  // To point to a new node
	ListNode<T> *nodePtr;

	// Allocate a new node and store newValue there.
	newNode = new ListNode<T>(newValue);

	// If there are no nodes in the list
	// make newNode the first node.
	if(!head){
		head = newNode;
		tail = newNode;
		tail->next = nullptr;
	}
	else  // Otherwise, insert newNode at end.
	{
		nodePtr = tail;
		// Insert newNode as the last node.
		nodePtr->next = newNode;
		tail = newNode;
	}
}

//**************************************************
// displayList shows the value stored in each node *
// of the linked list pointed to by head.          *
//**************************************************

template<class T>
void LinkedList<T>::displayList() const {
	ListNode<T> *nodePtr;  // To move through the list

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr points to a node, traverse
	// the list.
	while (nodePtr) {
		// Display the value in this node.
		cout << nodePtr->value<<" ";

		// Move to the next node.
		nodePtr = nodePtr->next;
	}
	
}

//**************************************************
// The insertNode function inserts a node with     *
// newValue copied to its value member.            *
//**************************************************

template<class T>
void LinkedList<T>::insertNode(T newValue) {
	ListNode<T> *newNode;				// A new node
	ListNode<T> *nodePtr;				// To traverse the list
	ListNode<T> *previousNode = nullptr; // The previous node

	// Allocate a new node and store newValue there.
	newNode = new ListNode<T>(newValue);

	// If there are no nodes in the list
	// make newNode the first node
	
	if (!head) {
		head = newNode;
		tail = newNode;
		newNode->next = nullptr;
		
	} else  // Otherwise, insert newNode
	{
		// Position nodePtr at the head of list.
		nodePtr = head;

		// Initialize previousNode to nullptr.
		previousNode = nullptr;

		// Skip all nodes whose value is less than newValue.
		while (nodePtr != nullptr && nodePtr->value < newValue) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If the new node is to be the 1st in the list,
		// insert it before all other nodes.
		if (previousNode == nullptr) {
			head = newNode;
			newNode->next = nodePtr;
		} else  // Otherwise insert after the previous node.
		{
			previousNode->next = newNode;
			newNode->next = nodePtr; 
			if(newNode->next == nullptr){
				tail = newNode;
			}
		}
	}
}

//*****************************************************
// The deleteNode function searches for a node        *
// with searchValue as its value. The node, if found, *
// is deleted from the list and from memory.          *
//*****************************************************

template<class T>
void LinkedList<T>::deleteNode(T searchValue) {
	ListNode<T> *nodePtr;       // To traverse the list
	ListNode<T> *previousNode;  // To point to the previous node

	// If the list is empty, do nothing.
	if (!head)
		return;

	// Determine if the first node is the one.
	if (head->value == searchValue) {
		//Determine if the list only has one node
		if(tail == head){	
			delete tail;
			delete head;
		} else{ 
			nodePtr = head->next;
			delete head;
			head = nodePtr;
		}
	} 
	else {
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes whose value member is
		// not equal to num.
		while (nodePtr != tail && nodePtr->value != searchValue) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		
		// If nodePtr is not at the end of the list,
		// link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr!=tail) {
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
		else if(tail->value == searchValue){
			previousNode->next = nullptr;
			delete tail;
			tail = previousNode;
		}
	}
}

//**************************************************
// Push Front for the Linked List class            *
// take a value of type t and inserts a node for it*
//**************************************************
template<class T>
void LinkedList<T>::push_front(T Val){
	// init a new node for the value given
	ListNode<T> *newNode = new ListNode<T>(Val);

	if(!head){ // if empty list add node 
		head = newNode;
		tail = newNode;
	}
	else{ // if full add to the front
		ListNode<T> *nodePtr = head;
		head = newNode;
		newNode->next = nodePtr;
	}
}

//**************************************************
// Pop the front value and return it               *
// Return the value of type t or throw excep       *
//**************************************************
template<class T>
T LinkedList<T>::pop_front()
{
	string error; // string for the error
	if (!head) { // if empty throw exception
		error = "Empty List Exception";
		throw error;
	}
	else{ // if full pop the front and set head
		T val = head->value;
		ListNode<T> *newHead = head->next;
		delete head;
		head = newHead;
		return val;
	}

}

//**************************************************
// Peak head simply returns the value of the head  *
// Return the value of type t value or throw excep *
//**************************************************
template<class T>
T LinkedList<T>::peakHead()
{
	string error; // string for the throw
	if (!head) { // if empty throw exception, handle in main!!!
		error = "Null Pointer Exception!";
		throw error;
	}
	
	return head->value; // return val
}

//**************************************************
// Peak tail simply returns the value of the tail  *
// Return the value of type t value or throw excep *
//**************************************************
template<class T>
T LinkedList<T>::peakTail()
{
	
	string error;// string for the throw
	if (!tail) { // if empty throw 
		error = "Null Pointer Exception!";
		throw error;
	}
	return tail->value; // return val
}

//**************************************************
// This function clears out the list               *
// prep for use again or simply to delete          *
//**************************************************
template<class T>
void LinkedList<T>::clear()
{
	ListNode<T> *nodePtr;   // To traverse the list
	ListNode<T> *nextNode;  // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != nullptr) {
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
		
	}
	head = nullptr;
	tail = nullptr;
}


//*************************************************
// This function finds the length and returns it  *
// return an integer size                         *
//*************************************************
template<class T>
int LinkedList<T>::length()
{
	int numNodes = 0; // create iterator

	if(head){ // if list has value then runs task
		ListNode<T> *nodePtr = head; // init the ptr to head

		while(nodePtr != nullptr){ // while not at the end iterate the count
			numNodes++;
			nodePtr = nodePtr->next;
		}
	}
	return numNodes;
}


//*************************************************
// get the value at the specified index           *
// throw exception or return the value            *
// special case is if length is <=0               *
// and out of bound                               *
// one can assume there exists a node in the bound*
//*************************************************
template<class T>
T LinkedList<T>::get(int itervar)
{
	int length = LinkedList<T>::length(); // get the length of the list

	string error; // set string for the throw 

	if(length <= 0){ // special case *
		error = "Empty List Exception";
		throw error;
	}
	else if(itervar > length){ // special case *
		error = "Index Out of Bounds Exception";
		throw error;
	}
	else{ //  if all is clear get the value of the node
		int count = 0;

		ListNode<T> *nodePtr = head; // init the pointer

		while(nodePtr != nullptr && count != itervar){ // iterate until the iterator is reached
			nodePtr = nodePtr->next;
			count++;
		}
		return nodePtr->value;// return the val
	}
}

//**************************************************
// set the value at the specified index            *
// throw exception or set the value at the index   *
// special case is if length is <=0                *
// and out of bound                                *
// one can assume there exists a node in the bound *
//**************************************************
template<class T>
void LinkedList<T>::set(int itervar, T value)
{
	int length = LinkedList<T>::length(); // get the length of the list

	string error;// create string for the throw 

	if(length <= 0){ // special case *
		error = "Empty List Exception";
		throw error;
	}
	else if(itervar > length){ // special case *
		error = "Index Out of Bounds Exception";
		throw error;
	}
	else{ // if all clear set the value into the spot
		int count = 0;

		ListNode<T> *nodePtr = head; // init the ptr to the head

		while(nodePtr != nullptr && count != itervar){ // while index not found iterate the pointer
			nodePtr = nodePtr->next;
			count++;
		}
		nodePtr->value = value;
	}
}

//**************************************************
// overload the access operator                    *
// throw exception or return the value             *
// special case if out of bound or not existant    *
//**************************************************
template<class T>
T& LinkedList<T>::operator[](int itervar)
{
	int length = LinkedList<T>::length();

	string error;
	if(length <= 0){ // if length is 0 
		error = "Empty List Exception";
		throw error;
	}
	else if(itervar > length){ // if greater than length 
		error = "Index Out of Bounds Exception";
		throw error;
	}
	else{ // if clear return the address
		int count = 0;

		ListNode<T> *nodePtr = head; // init the prt to the head

		while(nodePtr != nullptr && count != itervar){
			nodePtr = nodePtr->next;
			count++;
		}
		return nodePtr->value;
	}
}


//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

template<class T>
LinkedList<T>::~LinkedList() {
	clear();
}
#endif
