#include <iostream>

#include "LinkedList.h"

using namespace std;

template <class T> void displayHeadTail(LinkedList<T> &);

void div() { cout << "\n----------------------------------\n\n"; }

int main() {
    srand(time(0));
    LinkedList<int> lst;

    lst.push_back(12);
    lst.push_back(4);
    lst.push_back(54);
    lst.push_back(10);

    lst.displayList();
    cout << endl;
    displayHeadTail(lst);

    lst.push_back(101);
    lst.push_back(17);
    lst.push_back(21);

    lst.displayList();
    cout << endl;
    displayHeadTail(lst);

    lst.deleteNode(12);

    lst.displayList();
    cout << endl;
    displayHeadTail(lst);

    lst.deleteNode(101);

    lst.displayList();
    cout << endl;
    displayHeadTail(lst);

    lst.deleteNode(1234);

    lst.displayList();
    cout << endl;
    displayHeadTail(lst);

    lst.deleteNode(21);

    lst.displayList();
    cout << endl;
    displayHeadTail(lst);

    lst.push_back(112);
    lst.push_back(14);
    lst.push_back(154);
    lst.push_back(110);

    lst.displayList();
    cout << endl;
    displayHeadTail(lst);

    lst.clear();
    displayHeadTail(lst);

    div();

    lst.insertNode(45);
    lst.displayList();
    cout << endl;
    displayHeadTail(lst);

    lst.insertNode(21);
    lst.displayList();
    cout << endl;
    displayHeadTail(lst);
    
    lst.insertNode(57);
    
    lst.displayList();
    
    cout << endl;
    displayHeadTail(lst);
    
    for (int i = 0; i < 10; i++)
        lst.insertNode(rand() % 100);

    
    lst.displayList();
    cout << endl;
    displayHeadTail(lst);

    div();

    lst.clear();
    lst.push_front(12);
    lst.displayList();
    cout << endl;
    displayHeadTail(lst);

    lst.push_front(15);
    lst.displayList();
    cout << endl;
    displayHeadTail(lst);
    
    lst.push_front(25);
    lst.displayList();
    cout << endl;
    displayHeadTail(lst);
    
    for (int i = 0; i < 10; i++)
        lst.push_front(rand() % 100);

    lst.displayList();
    cout << endl;
    displayHeadTail(lst);
    
    div();
    
    try {
        cout << lst.pop_front() << endl;
        lst.displayList();
        cout << endl;
        displayHeadTail(lst);
        
        cout << lst.pop_front() << endl;
        lst.displayList();
        cout << endl;
        displayHeadTail(lst);
        
        cout << lst.pop_front() << endl;
        lst.displayList();
        cout << endl;
        displayHeadTail(lst);
        
        cout << lst.pop_front() << endl;
        lst.displayList();
        cout << endl;
        displayHeadTail(lst);
        
    } catch (string err) {
        cout << err << endl;
    }
    
    try {
        cout << lst[5] << endl;
        cout << lst[2] << endl;
        cout << lst[6] << endl;
        cout << lst[21] << endl;
    } catch (string err) {
        cout << err << endl;
    }

    lst.displayList();
    cout << endl;

    try {
        lst[5] = 17;
        lst[1] = 29;
        lst[3] = 11;
        lst[52] = 7;
    } catch (string err) {
        cout << err << endl;
    }

    lst.displayList();
    cout << endl;
    displayHeadTail(lst);

    try {
        lst.set(5, -17);
        lst.set(1, -29);
        lst.set(3, -11);
        lst.set(52, -7);
    } catch (string err) {
        cout << err << endl;
    }

    lst.displayList();
    cout << endl;
    displayHeadTail(lst);
    
    div();

    LinkedList<int> L1;
    
    for (int i = 0; i < 5; i++){
        L1.push_back(rand());
    }

    LinkedList<int> L2 = L1;

    L1.displayList();
    cout << endl;
    L2.displayList();
    cout << endl;

    L1[3] = 1234567;

    L1.displayList();
    cout << endl;
    L2.displayList();
    cout << endl;

    L2 = L1;

    L1.displayList();
    cout << endl;
    L2.displayList();
    cout << endl;

    L1[3] = 987654321;

    L1.displayList();
    cout << endl;
    L2.displayList();
    cout << endl;

    return 0;
}

template <class T> void displayHeadTail(LinkedList<T> &L) {
    cout << "Head: ";
    try {
        cout << L.peakHead() << endl;
    } catch (string s) {
        cout << s << endl;
    }

    cout << "Tail: ";
    try {
        cout << L.peakTail() << endl;
    } catch (string s) {
        cout << s << endl;
    }
}
