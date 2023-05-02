/*
Author: Cole Barbes
Creation Date: 04/14/23
Last Update: 04/14/23
Description: 
User Interface: <List of all user options and short descriptions of each option>
Notes: <Any notes that a user of the program should know about>
*/
#include "Queue.h"
#include "Stack.h"
#include <iostream>
#include <sstream>

using namespace std;

template <class T>
T calculate(T, T, string);

int main()
{
// string input = "234 32 + 7 *";
// Must have spaces between tokens.

    string input;
    cout << "Enter a postfix expression: ";
    getline(cin, input);

    Queue<string> tokens; // tokens stack to parse the input
    Stack<double> postFixStack; // post fix stack for calculation
    stringstream inputstream(input); // convert input to a usable stream

    string token; // token val
    string symbol;
    double val1 = 0;
    double val2 = 0;
    int value = 0;

    while (getline(inputstream, token, ' ')){
        tokens.enqueue(token);
    }

    // Printing the token queue for testing.
    try {
        while (!tokens.isEmpty()){
            symbol = tokens.dequeue();
            value = static_cast<int>(symbol[0]);
            if(value > 47 && value < 58){
                postFixStack.push(stod(symbol));
            }else{
                val2 = postFixStack.pop();
                val1 = postFixStack.pop();
                
                postFixStack.push(calculate(val1, val2, symbol));
            }
        }
    } catch (string s) {
        cout << s << endl;
    }

    cout<<"Value = "<<postFixStack.pop()<<endl; // print the value at the end

}

/*
Description: simply calculate an operation dependent on a symbol
Parameters: 2 values one left value and one right value, then the operator
return: the result as whatever type the values are
*/
template <class T> 
T calculate(T leftVal, T rightVal, string symbol)
{
    T result = 0;
    // if else to find which operation to perform
    if(symbol == "*"){ 
        result = leftVal*rightVal;
    }else if(symbol == "/"){
        result = leftVal/rightVal;
    }else if(symbol == "+"){
        result = leftVal+rightVal;
    }else{
        result = leftVal-rightVal;
    }

    return result; // return the resulting value
}