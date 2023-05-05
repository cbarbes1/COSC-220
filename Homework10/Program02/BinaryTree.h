/*
Author: Cole Barbes
Creation Date: 05/03/23
Last Update: 05/03/23
Description: This class implements a binary tree
*/
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

using namespace std;

template<class T>
class BinaryTree {
    private:
        struct TreeNode {
            T value;           // The value in the node
            TreeNode *left;    // Pointer to left child node
            TreeNode *right;   // Pointer to right child node
        };

        TreeNode *root;       // Pointer to the root node

        // Private member functions
        void insert(TreeNode*&, TreeNode*&);
        void destroySubTree(TreeNode*);
        void deleteNode(T, TreeNode*&);
        void makeDeletion(TreeNode*&);
        void displayInOrder(TreeNode*) const;
        void displayPreOrder(TreeNode*) const;
        void displayPostOrder(TreeNode*) const;
        void IndentBlock(int);
        void PrintTree(TreeNode*, int, int);
        void loadInOrderRec(TreeNode *nodePtr, T A[], int &pos);
        int numberOfNodes(TreeNode*);
        int numberOfLeafNodes(TreeNode*);
        int height(TreeNode*);
        void copyTree(TreeNode *&nodePtr, TreeNode *rootOldNode);

    public:
        // Constructor
        BinaryTree() {
            root = nullptr;
        }

        // copy constructor
        BinaryTree(BinaryTree<T>& obj);

        // equals operator
        BinaryTree<T>& operator=(BinaryTree<T>& other);

        // Destructor
        ~BinaryTree() {
            destroySubTree(root);
        }

        // Binary tree operations
        void insertNode(T);
        bool searchNode(T);
        void remove(T);

        void displayInOrder() const {
            displayInOrder(root);
        }

        void displayPreOrder() const {
            displayPreOrder(root);
        }

        void displayPostOrder() const {
            displayPostOrder(root);
        }

        void PrintTree(int Indent = 4, int Level = 0);

        void loadInOrder(T A[]);

        int numberOfNodes(){
            return numberOfNodes(root);
        }

        int numberOfLeafNodes(){
            return numberOfLeafNodes(root);
        }

        int height(){
            return height(root);
        }

        void clear();

};

/*
Description: This function places a node into a tree
Parameters: A pointer to a tree node and a pointer to a new node 
*/
template<class T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
    if(nodePtr == nullptr){ // insert the node
        nodePtr = newNode;
    }
    else if(newNode->value < nodePtr->value){ // skate down the left tree 
        insert(nodePtr->left, newNode);
    }
    else{ // skate down the right tree
        insert(nodePtr->right, newNode);
    }
}

/*
Description: This function creates a node for a value and places it into the tree
parameters: the item of type T
*/
template<class T>
void BinaryTree<T>::insertNode(T item){
    TreeNode *newNode = nullptr; // pointer for the ndde

    //create the node
    newNode = new TreeNode;
    newNode->value = item;
    newNode->left = newNode->right = nullptr;

    // use the insert function to set the node into the tree
    insert(root, newNode);
}

/*
This function simply destroys the sub tree of a given node recursively
*/
template<class T> 
void BinaryTree<T>::destroySubTree(TreeNode* nodePtr)
{
    if(nodePtr){
        if(nodePtr->left)
            destroySubTree(nodePtr->left);
        if(nodePtr->right)
            destroySubTree(nodePtr->right);
        delete nodePtr;
    }
}

/*
Description: This function searches the tree for a node with the parameter value
Parameters: item of type T being searched for 
*/
template<class T>
bool BinaryTree<T>::searchNode(T item)
{
    TreeNode *nodePtr = root;

    while(nodePtr){
        if(nodePtr->value == item){ // if the value is equal return
            return true;
        }
        else if(nodePtr->value > item){ // if the item is less than the node go down left tree
            nodePtr = nodePtr->left;
        }
        else{ //  if greater go down right tree
            nodePtr = nodePtr->right;
        }
    }
    return false;
}

/*
This function simply calls the recursive function to delete the node with the value
*/
template<class T> 
void BinaryTree<T>::remove(T item)
{
    deleteNode(item, root);
}

//********************************************
// deleteNode deletes the node whose value   *
// member is the same as num.                *
//********************************************
template<class T>
void BinaryTree<T>::deleteNode(T item, TreeNode *&nodePtr) {
    if(!nodePtr){
        return;
    }
	if (item < nodePtr->value)
		deleteNode(item, nodePtr->left);
	else if (item > nodePtr->value)
		deleteNode(item, nodePtr->right);
	else
		makeDeletion(nodePtr);
}

/*
Description: This function deletes a node 
Parameters: The pointer to the node
*/
template<class T>
void BinaryTree<T>::makeDeletion(TreeNode *&nodePtr)
{
    //define a temporary pointer to use in reattaching
    //the left subtree.
    TreeNode *tempNodePtr = nullptr;

    if(nodePtr == nullptr){
        cout<<"There is no tree here."<<endl;
    }
    else if (nodePtr->right == nullptr) {
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left;   // Reattach the left child
		delete tempNodePtr;
	} else if (nodePtr->left == nullptr) {
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;  // Reattach the right child
		delete tempNodePtr;
	}
    // If the node has two children.
	else {
		// Move one node the right.
		tempNodePtr = nodePtr->right;
		// Go to the end left node.
		while (tempNodePtr->left)
			tempNodePtr = tempNodePtr->left;
		// Reattach the left subtree.
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		// Reattach the right subtree.
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}

//****************************************************************
// The displayInOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via inorder traversal.  *
//****************************************************************
template<class T>
void BinaryTree<T>::displayInOrder(TreeNode *nodePtr) const {
	if (nodePtr) {
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << endl;
		displayInOrder(nodePtr->right);
	}
}

//****************************************************************
// The displayPreOrder member function displays the values       *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//****************************************************************
template<class T>
void BinaryTree<T>::displayPreOrder(TreeNode *nodePtr) const {
	if (nodePtr) {
		cout << nodePtr->value << endl;
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}

//****************************************************************
// The displayPostOrder member function displays the values      *
// in the subtree pointed to by nodePtr, via postorder traversal.*
//****************************************************************
template<class T>
void BinaryTree<T>::displayPostOrder(TreeNode *nodePtr) const {
	if (nodePtr) {
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		cout << nodePtr->value << endl;
	}
}

//****************************************************************
// Simple helper function to do the indentations for the tree
// printing algorithm.
//****************************************************************

template<class T>
void BinaryTree<T>::IndentBlock(int num) {
	for (int i = 0; i < num; i++)
		cout << " ";
}

//****************************************************************
// This function recursively prints the tree contents to the
// console using a reverse inorder traversal with indenting.
//****************************************************************

template<class T>
void BinaryTree<T>::PrintTree(TreeNode *t, int Indent, int Level) {
	if (t != NULL) {
		PrintTree(t->right, Indent, Level + 1);
		IndentBlock(Indent * Level);
		cout << t->value << "\n";
		PrintTree(t->left, Indent, Level + 1);
	}
}

//****************************************************************
// This function initiates the recursive printing function to
// print the contents of the tree in tree form sideways with the
// root at the far left.
//****************************************************************

template<class T>
void BinaryTree<T>::PrintTree(int Indent, int Level) 
{
	if (root != NULL)
		PrintTree(root, Indent, Level);
}

/*
Description: This function recursively calls itself to load an array in an inorder fashion
Parameters: The node pointing to the start of the tree needing to be searched
*/
template<class T>
void BinaryTree<T>::loadInOrderRec(TreeNode *nodePtr, T A[], int &pos)
{
    if(nodePtr){
        loadInOrderRec(nodePtr->left, A, pos);
        A[pos++] = nodePtr->value;
        loadInOrderRec(nodePtr->right, A, pos);
    }
}

/*
Description: This function calls the recursive function to load the array in order
Parameters: the array to place values in 
*/
template<class T> 
void BinaryTree<T>::loadInOrder(T A[])
{
    int size = 0;
    loadInOrderRec(root, A, size);
}

/*
*/
template<class T>
int BinaryTree<T>::numberOfNodes(TreeNode *nodePtr)
{
    if(nodePtr){
        if(!nodePtr->left && !nodePtr->right){
            return 1;
        }
        else if(!(nodePtr->left)){
            return numberOfNodes(nodePtr->right) + 1;
        }
        else if(!(nodePtr->right)){
            return numberOfNodes(nodePtr->left) + 1;
        }
        else {
            return numberOfNodes(nodePtr->left) + numberOfNodes(nodePtr->right) + 1;
        }
    }
    return 0;
}

template<class T>
int BinaryTree<T>::numberOfLeafNodes(TreeNode* nodePtr)
{
    if(nodePtr){
        if(!(nodePtr->left)&&!(nodePtr->right)){
            return 1;
        }
        else {
            return numberOfLeafNodes(nodePtr->left)+numberOfLeafNodes(nodePtr->right);
        }
    }
    return 0;
}

template<class T>
int BinaryTree<T>::height(TreeNode *nodePtr){
    if(!nodePtr){
        return 0;
    }

    if(!nodePtr->left && !nodePtr->right){
        return 1;
    }
    else {
        int left_height = 0;
        int right_height = 0;
        left_height = height(nodePtr->left)+1;
        right_height = height(nodePtr->right)+1;
        return left_height>right_height ? left_height : right_height;
    }
}

template<class T> 
void BinaryTree<T>::clear()
{
    destroySubTree(root);
}

template<class T>
void BinaryTree<T>::copyTree(TreeNode*& nodePtr, TreeNode *rootOther)
{
    if(rootOther){
        TreeNode* newNode = new TreeNode;
        newNode->value = rootOther->value;
        newNode->left = newNode->right = nullptr;
        nodePtr = newNode;
        copyTree(nodePtr->left, rootOther->left);
        copyTree(nodePtr->right, rootOther->right);
    }
    return;
}


template<class T>
BinaryTree<T>::BinaryTree(BinaryTree<T>& obj)
{
    if(obj.root){
        copyTree(root, obj.root);
    }
}

template<class T>
BinaryTree<T>& BinaryTree<T>::operator=(BinaryTree<T>& other){
    clear();
    if(other.root){
        copyTree(root, other.root);
    }
    return *(this);
}



#endif