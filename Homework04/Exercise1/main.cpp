#include <iostream>
#include "Point.h"

using namespace std;

int main()
{
    Point p1;
    Point p2(3, 5, 1);
    Point p3(-2, 4, 7);

    cout<<p1<<" "<<p2<<" "<<p3<<endl;

    Point p4 = p2;
    cout<<p4<<endl;

    p4 = p3;
    cout<<p4<<endl;

    p4 = p2 + p3;
    cout << p4 << endl;

    p4 = p2 - p3;
    cout << p4 << endl;

    double d = p2 * p3;
    cout << d << endl;

    p4 = p2;

    if (p2 == p4) {
        cout << "Points are equals." << endl;
    }
    else{
        cout<<"Points are different."<<endl;
    }
    cout << p4.length() << endl;

    cout << p4 << endl;
    cout << p4.getX() << endl;
    cout << p4.getY() << endl;
    cout << p4.getZ() << endl;

    p4.setX(-5.2);
    p4.setY(7.1);
    p4.setZ(3.5);

    cout << p4 << endl;
    cout << p4.getX() << endl;
    cout << p4.getY() << endl;
    cout << p4.getZ() << endl;

    p4.setXYZ(3.14159, 2.718281828, 1.618033988);
    cout << p4 << endl;

    cout << p3 << endl;
    cout << 3 * p3 << endl;
    cout << p3 * 2 << endl;
    cout << p3 / 4 << endl;

    return 0;
 
}