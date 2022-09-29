/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: February 3, 2022
Assignment: Project 1A

This program takes a set of numbers from a .txt file and outputs their sum.
*/

#include <iostream>
using namespace std;

int main(){
    
    int nums;
    int sum = 0;              //declare variables//
    while(cin >> nums){         //add numbers from .txt file until none left//
        sum = sum + nums;}
    
    cout << sum;                //output sum//
    
    return 0;
}
