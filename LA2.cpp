//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: February 7, 2022
//Assignment: Lecture Activity 2/7

//This program takes a user-inputted name to print out last name followed by the first name, then their initials.

#include <iostream>
#include <string>
using namespace std;
//Enter a full name in format of first name first, last name last,
//find out the first name and last name,
//then find out the initial.
int main(){
    //Enter name from console interactively.
    cout << "Enter name in format of first name first, last name last: ";
    string name;
    getline(cin, name);      //like cin but doesn't stop after first space//
    //process name to extract last name and first name.
    size_t index = name.find(" ");
    //index is the location of the first occurrence of " " in name.
    if (index == string::npos){ //no space in name
        cerr << "no space in input name, cannot proceed" << endl;
        return -1;
    }
    string firstName = name.substr(0, index);
    string lastName = name.substr(index +1);
    cout << lastName + ", " + firstName << endl;
    
    //find out the initial
    cout << firstName[0] << lastName[0] << endl;
    
   return 0;
}
