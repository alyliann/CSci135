//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: April 13, 2022
//Assignment: Lab Quiz 10

//Define int unbalanced_brackets(string input), return the difference between open curly brackets and closed curly brackets. For example, given "{}}}", return -2.

#include <iostream>
using namespace std;

int unbalanced_brackets(string input){
    int open = 0, closed = 0;
    
    for (int i = 0; i < input.length(); i++){
        if (input[i] == '{'){
            open++;
        }
        else closed++;
    }
    
    return open-closed;
}

int main(){
    
    cout << unbalanced_brackets("{}}}") << endl;
    
    return 0;
}
