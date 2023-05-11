/*
Author: Cole Barbes
Creation Date: 05/11/23
Last Update: 05/11/23
Description:    This program uses a map structure as a database for employees at a given company
*/
#include <iostream>
#include <map> // include for the map

using namespace std;

void printMenu(); // prototype of simple print function for menu

// structure to hold the data for each employee
struct employee{
    int age;
    int employeeID;
    double wage;
};

int main()
{
    // create variables to use for input
    int select = 4;
    string name = "";
    
    map<string, employee> dataBase; // init database to hold all employees

    printMenu();// print the menu
    cin>>select; // take the input

    while(select != 0){ // while not quit continue
        if(select == 1){ // if 1 enter data

            cin.ignore();// ignore previous cin 
            
            employee temp; // create temp employee for saving purposes
            // take all necessary input
            cout<<"Employee Name: ";
            getline(cin, name);
            cout<<"Employee ID: ";
            cin>>temp.employeeID;
            cout<<"Employee Age: ";
            cin>>temp.age;
            cout<<"Employee Wage: ";
            cin>>temp.wage;
            dataBase[name] = temp; // set temp into the map
            name = "";
            cout<<endl;
        }
        else if(select == 2){ // if 2 update data

            cin.ignore(); // ignore previous cin

            cout<<"Employee Name: ";
            getline(cin, name);
            map<string, employee>::iterator iter = dataBase.find(name); // create iterator to the point with the given name
            if(iter != dataBase.end()){ // if the iterator is existent
                employee temp;
                cout<<"Input New Information for "<<name<<endl;
                cout<<"Employee ID: ";
                cin>>temp.employeeID;
                cout<<"Employee Age: ";
                cin>>temp.age;
                cout<<"Employee Wage: ";
                cin>>temp.wage;
                dataBase[name] = temp; // set temp into the map
                name = "";
            }
            else { // if non existent
                cout<<name<<" is not employed at this company."<<endl;
            }
            cout<<endl;
        }
        else if(select == 3){ // if 3 print the database
        // for loop using an iterator from the beginning of the data base to the end 
            for(auto it = dataBase.begin(); it != dataBase.end(); it++){ 
                // name, employee id, age, and wage 
                cout<<it->first<<" / "<<"ID: "<<it->second.employeeID<<" / Age: "<<it->second.age<<" / Wage:"<<it->second.wage<<endl;
            }
            cout<<endl;
        }
        printMenu(); // print the menu
        cin>>select;// take the input
    }

    return 0;
}

/*
Print the menu
*/
void printMenu()
{
    cout<<"1. Input Employee"<<endl;
    cout<<"2. Update Employee Information"<<endl;
    cout<<"3. Print Employee List"<<endl;
    cout<<"0. Quit"<<endl;
    cout<<"Selection: ";
}