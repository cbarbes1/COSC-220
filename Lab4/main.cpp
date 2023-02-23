#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Array2D.h"
using namespace std;

int main() {
    srand(time(0));
    Array2D A(3, 5, -1);
    Array2D B;

    A.display();
    cout << endl;

    for (int i = 0; i < A.getRows(); i++)
        for (int j = 0; j < A.getCols(); j++)
            A.set(i, j, rand() % 100);
    
    A.display();
    cout << endl;

    A.set(10, 3, -15);
    A.display();
    cout << endl;

    A.set(1, 3, -15);
    A.display();
    cout << endl;

    cout << A.get(2, 2) << endl;
    cout << A.get(2, 20) << endl;
    cout << endl;
    B.display();

    return 0;
}