/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: February 8, 2022
Assignment: Lab 2B

This program prints out all integers within a user-inputted range.
*/

#include <iostream>
using namespace std;

int main(){
    
    int L, U;           //declare variables, obtain inputs//
    cout << "Please enter L: ";
    cin >> L;
    cout << "Please enter U: ";
    cin >> U;
    
    for (int i = L; i < U; i++){
        // the body of the loop will get executed for
        // all values of i starting at L
        // and ending at the largest integer less than U
        cout << i << " ";
    }
    
    return 0;
}
