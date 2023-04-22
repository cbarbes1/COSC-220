/*
Author: Cole Barbes
Creation Date: 04/21/23
Last Update: 04/21/23
Description: This function implements a palindrome function 
User Interface: simple user input
*/
#include <iostream>

using namespace std;

bool isPal(const string&, int, int); // prototype for the is palindrome function

int main()
{
    string word = ""; // init var for word

    // take the input
    cout<<"Enter a string, no spaces and all lower case:";
    getline(cin, word);

    // if true print a message
    if(isPal(word, 0, word.length()-1)){
        cout<<word<<" is a palindrome."<<endl;
    }else{
        cout<<word<<" is not a palindrome."<<endl;
    }

    return 0;
}

/*
Description: Recursive function to find out if a word is a palindrome by checking the characters as they approach the center
Parameters: a string, the start index, and the end index
return true or false
*/
bool isPal(const string& str, int startIndex, int endIndex)
{
    if(str[startIndex] != str[endIndex]){ // if the characters are not equal it isnt a palindrome return false
        return false;
    }
    else if(startIndex > endIndex){ // if at the center return true
        return true;
    }
    else{ // recursive step
        return isPal(str, startIndex+1, endIndex-1);
    }
}