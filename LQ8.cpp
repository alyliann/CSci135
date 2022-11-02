//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: April 7, 2022
//Assignment: Lab Quiz 8

//This program creates a function that removes all 'e' characters from a string

#include <iostream>
using namespace std;

void remove_e(string &sentence){
    //removes all 'e' from original string, no return variable
    string og = sentence;
    sentence = "";
    char e = 'e';
    char E = 'E';
    
    for (int i = 0; i < og.length(); i++){
        if (og[i] != e && og[i] != E){      //if char is NOT e or E
            sentence += og[i];
        }
    }
//    cout << sentence << endl;
}

int main(){
    
    string s = "Early bird catches the worm";
    
    remove_e(s);
    
    return 0;
}
