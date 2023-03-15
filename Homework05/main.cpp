/*
Author: Cole Barbes
Creation Data: 03/14/23
Last Update: 03/14/23
Description: This program uses defined classes to create an array of objects of type person data
User Interface: User Options are 1. create a new personal data object 2. create a new customerdata object 3. create a new preferred customer 4.5. print in two different ways
*/
#include <iostream>
#include <ctype.h>
#include "PersonData.h"// include for base
#include "CustomerData.h" // include for derived class
#include "PreferredCustomer.h" // include for derived derived class

using namespace std;

void menu();// print menu

int main()
{
    const int SIZE = 10; // create size constant
    int choice = 0; // create choice var
    int databaseSize = 0; // create database size tracker
    PersonData *arr[SIZE]; // create array

    while(choice!=6){// while to check for end input from user
        cout<<endl;
        menu();// print the menu
        cin>>choice;
        cout<<endl;
        if(choice == 1){// if choice 1

            databaseSize++;// add 1 to the databaseSize

            arr[databaseSize-1] = new PersonData();// create the object

            string street, city, state, zipcode, phone, first, last = "";// create string vars to hold each input
            // take the input
            cout<<"Input Last Name: ";
            cin>>last;

            cout<<"Input First Name: ";
            cin>>first;

            cin.ignore(); // ignore for the getline functions to work

            cout<<"Input Street Address: ";
            getline(cin, street, '.');

            cin.ignore();// ignore for the getline functions to work
           
            cout<<"Input City: ";
            getline(cin, city);
         
            cout<<"Input State: ";
            cin>>state;
            
            cout<<"Input Zip Code: ";
            cin>>zipcode;
            
            cout<<"Input Phone Number: ";
            cin>>phone;
            //end input block

            // set into the data structure
            arr[databaseSize-1]->setName(first, last);
            arr[databaseSize-1]->setAddress(street, city, state, zipcode);
            arr[databaseSize-1]->setPhone(phone);

        }
        else if(choice ==2){// if choice 2

            databaseSize++;// add 1 to the databaseSize

            CustomerData* temp = new CustomerData(); // create the object

            // create storage variables for the data
            string street, city, state, zipcode, phone, first, last = ""; 
            int cNum = 0;
            char mailList = 0;

            // take the input
            cout<<"Input Last Name: ";
            cin>>last;

            cout<<"Input First Name: ";
            cin>>first;

            cin.ignore(); // ignore the whitespace

            cout<<"Input Street Address: ";
            getline(cin, street, '.');

            cin.ignore();// ignore the whitespace
           
            cout<<"Input City: ";
            getline(cin, city);
         
            cout<<"Input State: ";
            cin>>state;
            
            cout<<"Input Zip Code: ";
            cin>>zipcode;
            
            cout<<"Input Phone Number: ";
            cin>>phone;
            
            cout<<"Input Customer Number: ";
            cin>>cNum;
            
            cout<<"Do they wish to be on the mailing list? (Y/N):"<<endl;
            cin>>mailList;
            // end the input block

            // set the data into the data structure 
            temp->setName(first, last);
            temp->setAddress(street, city, state, zipcode);
            temp->setPhone(phone);

            // check mailing list setting
            if(mailList=='Y'||mailList=='y'){ temp->setMailingList(true);}
            else { temp->setMailingList(false);}

            temp->setCustomerNumber(cNum);
            arr[databaseSize-1] = temp; // set object into the array
            
        }
        else if(choice ==3){// if choice 3

            databaseSize++; // add to the size of the database

            PreferredCustomer *temp = new PreferredCustomer(); // create the object

            // create the temp vars
            string street, city, state, zipcode, phone, first, last = "";
            int cNum=0;
            char mailList=0;
            double purchAmount=0;

            // take the input 
            cout<<"Input Last Name: ";
            cin>>last;

            cout<<"Input First Name: ";
            cin>>first;

            cin.ignore();

            cout<<"Input Street Address: ";
            getline(cin, street, '.');

            cin.ignore();
           
            cout<<"Input City: ";
            getline(cin, city);
         
            cout<<"Input State: ";
            cin>>state;
            
            cout<<"Input Zip Code: ";
            cin>>zipcode;
            
            cout<<"Input Phone Number: ";
            cin>>phone;
            
            cout<<"Input Customer Number: ";
            cin>>cNum;
            
            cout<<"Do they wish to be on the mailing list? (Y/N):"<<endl;
            cin>>mailList;

            cout<<"Input purchases Amount: ";
            do{
                cin>>purchAmount;
            }while(purchAmount<0);
            // end of input

            // set the data into the structure 
            temp->setName(first, last);
            temp->setAddress(street, city, state, zipcode);
            temp->setPhone(phone);
            if(mailList=='Y'||mailList=='y'){ temp->setMailingList(true);}
            else { temp->setMailingList(false);}
            temp->setCustomerNumber(cNum);
            temp->setPurchasesAmount(purchAmount);
            arr[databaseSize-1] = temp;

        }
        else if(choice ==4){// if choice 4
        // print the data using short form
            for(int i = 0; i<databaseSize; i++){
                arr[i]->PrintRecord();
            }
        }
        else if(choice == 5){// if choice 5
        // print the data using long form
            for(int i = 0; i<databaseSize; i++){
                cout<<arr[i]->getRecord()<<endl;
                cout<<endl;
            }
        }

        
    }
    for(int i = 0; i<databaseSize; i++){
        delete arr[i];
        arr[i] = nullptr;
    }
    return 0;
}

/*
Description: simple function to print the menu
*/
void menu()
{
    cout<<"1. Add Personal Data Object"<<endl;
    cout<<"2. Add Customer Data Object"<<endl;
    cout<<"3. Add Preferred Customer Data Object"<<endl;
    cout<<"4. View Database Long Form"<<endl;
    cout<<"5. View Database Short Form"<<endl;
    cout<<"6. Quit"<<endl;
    cout<<"Choice: ";
}