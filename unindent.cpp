/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: March 7, 2022
Assignment: Lab 7A

This program removes leading spaces/indents from a line of code.
*/

#include <iostream>
#include <cctype>       //isspace
using namespace std;


//Iterate over the input string, skip all spaces, and after it finds the first non-space character, start accumulating the characters into a new string, which will be returned.
string removeLeadingSpaces(string line){
    string noSpaces = "";
    for (int i = 0; i < line.length(); i++){
        if (!isspace(line[i])){               //if character is not a white-space
            for (int j = i; j < line.length(); j++){
                noSpaces += line[j];              //add char to return string
            }
            break;
        }
    }
    return noSpaces;
}


int main(){
    
    string inS;
    while (getline(cin, inS)){
        string fixed = removeLeadingSpaces(inS);
        cout << fixed << endl;
    }
    
    return 0;
}
