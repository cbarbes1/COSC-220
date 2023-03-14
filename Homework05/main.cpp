#include <iostream>

#include "PersonData.h"
#include "CustomerData.h"
#include "PreferredCustomer.h"

using namespace std;

void menu();

int main()
{
    const int SIZE = 10;
    int choice = 0;
    int databaseSize = 0;
    PersonData *arr[SIZE];

    while(choice!=6){
        menu();
        cin>>choice;
        if(choice == 1){
            databaseSize++;
            string data, street, city, state, zipcode, phone;
            cout<<"Input Last Name: ";
            cin>>data;
            cout<<endl;
            arr[databaseSize]->setLast(data);
            cout<<"Input First Name: ";
            cin>>data;
            cout<<endl;
            arr[databaseSize]->setFirst(data);
            cout<<"Input Street Address: ";
            cin>>street;
            cout<<endl;
            cout<<"Input City: ";
            cin>>city;
            cout<<endl;
            cout<<"Input State: ";
            cin>>state;
            cout<<endl;
            cout<<"Input Zip Code: ";
            cin>>zipcode;
            cout<<endl;
            cout<<"Input Phone Number: ";
            cin>>phone;
            cout<<endl;
            arr[databaseSize]->setAddress(street, city, state, zipcode);
            arr[databaseSize]->setPhone(phone);
        }
        else if(choice ==2){
            databaseSize++;
            arr[databaseSize] = new CustomerData();
            string data, street, city, state, zipcode, phone;
            int cNum;
            char mailList;
            cout<<"Input Last Name: ";
            cin>>data;
            cout<<endl;
            arr[databaseSize]->setLast(data);
            cout<<"Input First Name: ";
            cin>>data;
            cout<<endl;
            arr[databaseSize]->setFirst(data);
            cout<<"Input Street Address: ";
            cin>>street;
            cout<<endl;
            cout<<"Input City: ";
            cin>>city;
            cout<<endl;
            cout<<"Input State: ";
            cin>>state;
            cout<<endl;
            cout<<"Input Zip Code: ";
            cin>>zipcode;
            cout<<endl;
            cout<<"Input Phone Number: ";
            cin>>phone;
            cout<<endl;
            cout<<"Input Customer Number: ";
            cin>>cNum;
            cout<<endl;
            cout<<"Do they wish to be on the mailing list? (Y/N):"<<endl;
            cin>>mailList;
            arr[databaseSize]->setAddress(street, city, state, zipcode);
            arr[databaseSize]->setPhone(phone);
            if(mailList=='Y'||mailList=='y'){ arr[databaseSize]->CustomerData::setMailingList(true);}
            else { arr[databaseSize].setMailingList(false);}
            arr[databaseSize]->setCustomerNumber(cNum);
        }
        else if(choice ==3){

        }
        else if(choice ==4){

        }
        else if(choice == 5){

        }
    }
    return 0;
}
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