#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
    srand(time(0));

    Matrix A(3, 5, 3.14);
    Matrix B = A;
    Matrix C;

    A.display(7);
    cout << endl;

    for (int i = 0; i < A.getRows(); i++)
        for (int j = 0; j < A.getCols(); j++)
            A.set(i, j, (rand() % 1000) / 10.0);

    A.display(7);
    cout << endl;

    A.set(10, 3, -15);
    A.display(7);
    cout << endl;

    A.set(1, 3, -15);
    A.display(7);
    cout << endl;

    cout << A.get(2, 2) << endl;
    cout << A.get(2, 20) << endl;
    cout << endl;

    B.display();
    cout << endl;

    C = A = B;

    A.display(7);
    cout << endl;

    C.display(6);
    cout << endl;

    for (int i = 0; i < B.getRows(); i++)
        for (int j = 0; j < B.getCols(); j++)
            B.set(i, j, rand() % 10);

    for (int i = 0; i < C.getRows(); i++)
        for (int j = 0; j < C.getCols(); j++)
            C.set(i, j, rand() % 10);

    B.display(7);
    cout << endl;

    C.display(7);
    cout << endl;

    A = B + C;
    A.display(7);
    cout << endl;

    A = B - C;

    A.display(7);
    cout << endl;

    for (int i = 0; i < A.getRows(); i++)
        for (int j = 0; j < A.getCols(); j++)
            A.set(i, j, (rand() % 1000) / 10.0);

    A.display(7);
    cout << endl;

    B = 3 * A;
    B.display(7);
    cout << endl;
    B = A * 7;
    B.display(7);
    cout << endl;
    B = 2 * A - 7 * C;
    B.display(7);
    cout << endl;

    A.display(7);
    cout << endl;

    A[2][2] = 123;
    A[1][3] = -15;
    A[0][4] = -25;

    A.display(7);
    cout << endl;
    cout << A[0][1] << " " << A[1][4] << " " << A[2][3] << " " << endl;
    //cout << A[10][11] << endl; // Error

    cout << A << endl << endl;

    Matrix D(3, 4);
    Matrix E(4, 2);

    for (int i = 0; i < D.getRows(); i++)
        for (int j = 0; j < D.getCols(); j++)
            D[i][j] = rand() % 11 - 5;

    for (int i = 0; i < E.getRows(); i++)
        for (int j = 0; j < E.getCols(); j++)
            E[i][j] = rand() % 11 - 5;

    D.display(7);
    cout << endl;

    E.display(7);
    cout << endl;
    
    B = D * E;
    B.display(7);
    cout << endl;

    cout << B << endl << endl;

    B = B.transpose();
    B.display(7);
    cout << endl;
    cout << B << endl << endl;

    return 0;
}