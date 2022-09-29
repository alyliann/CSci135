/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: February 8, 2022
Assignment: Lab 2D

This program prints the first 60 numbers of the fibonacci sequence.
*/

#include <iostream>
using namespace std;

int main(){
    
    int fib[60];            //create 60-cell array//
    fib[0] = 0;              //0 and 1 are given terms//
    fib[1] = 1;
    cout << fib[0] << endl << fib[1] << endl;
    
    for (int i = 2; i < 60; i++){
        fib[i] = fib[i-1] + fib[i-2];     //fibonacci seq computation//
        cout << fib[i] << endl;
    }
    
    //observation: towards the end of the array, the numbers begin to go negative. I am unsure why.
    
    return 0;
}
