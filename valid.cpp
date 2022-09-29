/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: February 8, 2022
Assignment: Lab 2A

This program squares a user-inputted number between 0 and 100.
*/

#include <iostream>
using namespace std;

int main(){
    int num;            //declare variable, obtain input//
    cout << "Enter an integer between 0 and 100: ";
    cin >> num;
    
    while(num <= 0 || num >= 100){     //ask for new number while range invalid//
        cout << "Please re-enter: ";
        cin >> num;}
    
    cout << "Number squared is " << (num*num) << endl;
    
    return 0;
}
