#include <iostream>
#include <sstream>
#include <stack>
#include <queue>

using namespace std;

template <class T>
T calculate(T, T, string); // create function to calculate each computation

int main()
{
    stack<double> postFixStack; // stack to pop value onto
    queue<string> tokens; // queue to parse string into

    string input;
    cout << "Enter a postfix expression: ";
    getline(cin, input);

    stringstream inputstream(input);
    string token;
    string symbol;
    double val1 = 0;
    double val2 = 0;
    int value = 0;

    // tokenize the line into the queue
    while (getline(inputstream, token, ' ')){
        tokens.push(token);
    }

    try {
        while (!tokens.empty()){ // calculate the result by popping and pushing each calculation
            symbol = tokens.front();
            value = static_cast<int>(symbol[0]);
            if(value > 47 && value < 58){ // if the value is a number then push onto the stack
                postFixStack.push(stod(symbol));
            }else{ // if not pop the last two values and compute and store back on the stack
                val2 = postFixStack.top();
                postFixStack.pop();
                val1 = postFixStack.top();
                postFixStack.pop();
                postFixStack.push(calculate(val1, val2, symbol));
            }
            tokens.pop(); // pop the value off the token array to continue the computations or end
        }
    } catch (string s) {
        cout << s << endl;
    }

    cout<<"Value = "<<postFixStack.top()<<endl;


    return 0;
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