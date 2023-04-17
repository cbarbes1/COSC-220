/*
Author: Cole Barbes
Creation Date: 04/15/23
Last Update: 04/16/23
Description: Implement a delimiters analysis on a string using a stack and queue 
User Interface: Simple input and output
*/
#include <iostream> 
#include <sstream>
#include <stack> 
#include <queue>

using namespace std;

int main()
{
    string input; // var for the input
    char token; // token var for the characters 
    stack<char> dataStack; // character stack to use  for the left delimiters in the analysi
    // take the input string
    
    cout<<"Enter Expression: ";
    getline(cin, input);
    
    if(input.length()>1 && input[0]!= '}' && input[0] != ')' && input[0] !=']'){
    	for(int i = 0; i<static_cast<int>(input.length()); i++){
        	token = input[i];
        	if(token == '{' || token == '('|| token == '['){ // if left delim place into the dataStack
				dataStack.push(token);
			}
        	else if((token == '}')||(token == ')')|| (token == ']')){ // if right delim
				if(dataStack.empty()){ // if the stack is empty invalid case reached kick out
					token = 'x';
					break;
				}
				// if right delim and stack top is the left delim pop the stack
				else if((token == '}' &&dataStack.top()=='{')||(token == ')' &&dataStack.top()=='(')|| (token == ']' &&dataStack.top()=='[')){
					dataStack.pop();
				}
        	}
    	}
    

    	if(!dataStack.empty()){ // check if the stack is empty
        	cout<<"Delimiters aren't Balanced"<<endl;
    	}
		else if(dataStack.empty() && token == 'x'){ //if error case 
			cout<<"Delimiters aren't Balanced"<<endl;
		}
		else{ // if else is reached it can be assumed all cases are met
        	cout<<"Delimiters are balanced"<<endl; 
    	}
    }else{ // if there only one delimiter it is invalid
	    cout<<"Delimiters aren't Balanced"<<endl;
    }
	return 0;
}
