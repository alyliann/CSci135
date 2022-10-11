/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: March 3, 2022
Assignment: Lab 6A

This program converts each character of a string to its ASCII value.
*/

#include <iostream>
using namespace std;

int main(){
    
    string s;                                 //create string, obtain input
    cout << "Enter text: ";
    getline(cin, s);

    for (int i = 0; i < s.length(); i++){    //loops through all letters in string
        cout << s[i] << " " << int(s[i]) << endl;
        //converts each char to ASCII value
    }
    
    return 0;
}
