//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: February 22, 2022
//Assignment: E5.6

//This program returns the middle letter(s) of a user-inputted string.

#include <iostream>
#include <string>
using namespace std;

string middle(string str){
    
    int i = str.length();
    if (i%2 == 0){                      //if string is even
        return str.substr((i/2) - 1, 2);
        //starting from letter before middle, stopping before 3rd char
    }
    else {                              //if string is odd
        return str.substr((i/2), 1);
        //starting from middle letter, stopping before 2nd char
    }
}

int main(){
    
    string word;
    cout << "Enter a word: ";
    cin >> word;
    
    cout << middle(word);
    
    return 0;
}
