#include <iostream>
#include "IntArrayList.h"

using namespace std;

void div();

int main() {
    srand(time(0));

    IntArrayList L1, L2;

    for (int i = 0; i < 10; i++)
        L1.add(rand() % 100 + 1);

    L1.display();
    cout << L1.sorted() << endl;
    L1.sort();
    L1.display();
    cout << L1.sorted() << endl;

    div();

    L1.displayAddress();
    L2.displayAddress();
    L1.duplicate(L2);
    L1.display();
    L2.display();
    L1.displayAddress();
    L2.displayAddress();

    div();

    L2.set(34, 3);
    L2.set(21, 4);
    L2.set(-15, 5);
    L1.display();
    L2.display();

    div();

    L2.add(123);
    L2.add(27);
    L2.add(-19);
    L1.display();
    L2.display();
    L1.duplicate(L2);
    L1.display();
    L2.display();
    L1.displayAddress();
    L2.displayAddress();

    div();

    L2.resize(5);
    L1.display();
    L2.display();
    for (int i = 0; i < 5; i++)
        L2.set(rand() % 25, i);

    L1.display();
    L2.display();
    L1.concat(L2);
    L1.display();
    L2.display();
    div();
    L1.display();
    L1.sort();
    L1.display();
    L1.shuffle();
    L1.display();
    div();
    L1.display();
    L2.display();
    L1.insert(L2, 5);
    L1.display();
    div();
    L2.display();
    L2.insert(5, 0);
    L2.display();
    L2.insert(2, -5);
    L2.display();
    L2.insert(54, 100);
    L2.display();
    L2.insert(123, 4);
    L2.display();

    div();

    L1.display();
    L1.remove(5, 10);
    L1.display();
    L1.sub(4, 12);
    L1.display();

    for (int i = 0; i < L1.length(); i++)
        cout << L1.get(i) << endl;
    
    return 0;
}
void div() {
    cout << "\n--------------------------------\n\n";
}