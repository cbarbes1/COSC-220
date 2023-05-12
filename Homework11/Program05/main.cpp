#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "BinaryTree.h"
#include "LinkedList.h"

using namespace std;

template <class T> void squarert(T &i) { i = sqrt(i); }

template <class T> void sqr(T &i) { i = i * i; }

template <class T> void pt(T &item) { cout << item << " "; }

void toupperchar(char &c) { c = toupper(c); }

void upppercase(string &str) { for_each(str.begin(), str.end(), toupperchar); }

void div() { cout << "\n------------------------------------\n\n"; }

int main() {
    srand(time(0));

    // Create the trees.
    BinaryTree<int> bt;

    bt.insertNode(10);
    bt.insertNode(4);
    bt.insertNode(12);
    bt.insertNode(7);
    bt.insertNode(15);

    bt.PrintTree();

    cout << endl;

    bt.apply(pt);

    cout << endl << endl;

    bt.apply(sqr);
    bt.PrintTree();

    cout << endl;

    div();

    BinaryTree<double> btd;

    btd.insertNode(10);
    btd.insertNode(4);
    btd.insertNode(12);
    btd.insertNode(7);
    btd.insertNode(15);

    btd.PrintTree();

    cout << endl;

    btd.apply(squarert);
    btd.PrintTree();

    cout << endl;
    btd.apply(pt);
    cout << endl;

    div();

    BinaryTree<string> btstr;

    btstr.insertNode("Steve");
    btstr.insertNode("John");
    btstr.insertNode("Sue");
    btstr.insertNode("Kim");
    btstr.insertNode("Tom");

    btstr.PrintTree();

    cout << endl;

    btstr.apply(upppercase);
    btstr.PrintTree();

    cout << endl;

    btstr.apply(pt);

    cout << endl;

    div();

    LinkedList<int> LLi;

    LLi.appendNode(10);
    LLi.appendNode(5);
    LLi.appendNode(17);
    LLi.appendNode(121);
    LLi.appendNode(15);

    LLi.displayList();

    LLi.apply(pt);

    cout << endl;

    LLi.apply(sqr);
    LLi.apply(pt);

    cout << endl;

    div();

    LinkedList<string> LLs;

    LLs.appendNode("Steve");
    LLs.appendNode("John");
    LLs.appendNode("Sue");
    LLs.appendNode("Kim");
    LLs.appendNode("Tom");

    LLs.apply(pt);

    cout << endl;

    LLs.apply(upppercase);
    LLs.apply(pt);

    cout << endl;
    
    return 0;
}