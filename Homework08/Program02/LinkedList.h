#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

template <class T> class ListNode {
  public:
    T value;
    ListNode<T> *next;

    ListNode(T nodeValue) {
        value = nodeValue;
        next = nullptr;
    }
};

template <class T> class LinkedList {
  private:
    ListNode<T> *head;
    ListNode<T> *tail;

  public:
    LinkedList();
    LinkedList(const LinkedList &obj);
    const LinkedList operator=(const LinkedList &right);
    ~LinkedList();

    void push_back(T);
    void push_front(T);
    T pop_front();
    void insertNode(T);
    void deleteNode(T);
    void displayList(bool vert = false) const;

    T peakHead();
    T peakTail();

    void clear();
    int length();

    T get(int);
    void set(int, T);
    T &operator[](const int &);
};

template <class T> LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

template <class T> LinkedList<T>::LinkedList(const LinkedList &obj) {
    head = nullptr;
    tail = nullptr;

    ListNode<T> *ptr = obj.head;
    while (ptr) {
        push_back(ptr->value);
        ptr = ptr->next;
    }
}

template <class T>
const LinkedList<T> LinkedList<T>::operator=(const LinkedList &right) {
    if (this == &right)
        return *this;

    clear();

    ListNode<T> *ptr = right.head;
    while (ptr) {
        push_back(ptr->value);
        ptr = ptr->next;
    }

    return *this;
}

template <class T> LinkedList<T>::~LinkedList() {
    ListNode<T> *nodePtr;
    ListNode<T> *nextNode;

    nodePtr = head;

    while (nodePtr != nullptr) {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

template <class T> void LinkedList<T>::push_back(T newValue) {
    ListNode<T> *newNode;

    newNode = new ListNode<T>(newValue);

    if (!head) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

template <class T> void LinkedList<T>::push_front(T newValue) {
    ListNode<T> *newNode;

    newNode = new ListNode<T>(newValue);

    if (!head) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

template <class T> T LinkedList<T>::pop_front() {
    string error;
    if (!head) {
        error = "Empty List Exception";
        throw error;
    }

    T val = head->value;

    ListNode<T> *nodePtr = head;
    head = head->next;
    delete nodePtr;
    if (head == nullptr)
        tail = nullptr;

    return val;
}

template <class T> void LinkedList<T>::insertNode(T newValue) {
    ListNode<T> *newNode;
    ListNode<T> *nodePtr;
    ListNode<T> *previousNode = nullptr;

    newNode = new ListNode<T>(newValue);

    if (!head) {
        head = newNode;
        tail = newNode;
    } else {
        nodePtr = head;

        previousNode = nullptr;

        while (nodePtr != nullptr && nodePtr->value < newValue) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (previousNode == nullptr) {
            head = newNode;
            newNode->next = nodePtr;
        } else {
            previousNode->next = newNode;
            newNode->next = nodePtr;
            if (nodePtr == nullptr)
                tail = newNode;
        }
    }
}

template <class T> void LinkedList<T>::deleteNode(T searchValue) {
    ListNode<T> *nodePtr;
    ListNode<T> *previousNode;

    if (!head)
        return;

    if (head->value == searchValue) {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
        if (head == nullptr)
            tail = nullptr;
    } else {
        nodePtr = head;

        while (nodePtr != nullptr && nodePtr->value != searchValue) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (nodePtr) {
            previousNode->next = nodePtr->next;
            delete nodePtr;
            if (previousNode->next == nullptr)
                tail = previousNode;
        }
    }
}

template <class T> void LinkedList<T>::displayList(bool vert) const {
    ListNode<T> *nodePtr;

    nodePtr = head;

    while (nodePtr) {
        cout << nodePtr->value << " ";
        nodePtr = nodePtr->next;
        if (vert)
            cout << endl;
    }
}

template <class T> T LinkedList<T>::peakHead() {
    string error = "Null pointer exception.";
    if (head)
        return head->value;
    else
        throw error;
}

template <class T> T LinkedList<T>::peakTail() {
    string error = "Null pointer exception.";
    if (tail)
        return tail->value;
    else
        throw error;
}

template <class T> void LinkedList<T>::clear() {
    ListNode<T> *nodePtr;
    ListNode<T> *nextNode;

    nodePtr = head;

    while (nodePtr != nullptr) {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
    head = nullptr;
    tail = nullptr;
}

template <class T> int LinkedList<T>::length() {
    if (!head)
        return 0;

    int count = 0;
    ListNode<T> *nodePtr = head;
    while (nodePtr) {
        nodePtr = nodePtr->next;
        count++;
    }
    return count;
}

template <class T> T LinkedList<T>::get(int pos) {
    string error;
    if (!head) {
        error = "Empty List Exception";
        throw error;
    }

    int sz = length();
    if (pos < 0 || pos >= sz) {
        error = "Index Out of Bounds Exception";
        throw error;
    }

    ListNode<T> *nodePtr = head;

    for (int i = 0; i < pos; i++)
        nodePtr = nodePtr->next;

    return nodePtr->value;
}

template <class T> void LinkedList<T>::set(int pos, T val) {
    string error;
    if (!head) {
        error = "Empty List Exception";
        throw error;
    }

    int sz = length();
    if (pos < 0 || pos >= sz) {
        error = "Index Out of Bounds Exception";
        throw error;
    }

    ListNode<T> *nodePtr = head;

    for (int i = 0; i < pos; i++)
        nodePtr = nodePtr->next;

    nodePtr->value = val;
}

template <class T> T &LinkedList<T>::operator[](const int &pos) {
    string error;
    if (!head) {
        error = "Empty List Exception";
        throw error;
    }

    int sz = length();
    if (pos < 0 || pos >= sz) {
        error = "Index Out of Bounds Exception";
        throw error;
    }

    ListNode<T> *nodePtr = head;

    for (int i = 0; i < pos; i++)
        nodePtr = nodePtr->next;

    return nodePtr->value;
}

#endif
