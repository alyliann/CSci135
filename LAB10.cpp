/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: April 4, 2022
Assignment: Lab 10 intro

This program prints a time in 24-hour format using a class/datatype.
*/

#include <iostream>
using namespace std;

class Time {
public:
    int h;
    int m;
};

void printTime(Time time) {
    cout << time.h << ":" << time.m;
}

int main(){
    
    Time now;    // creates a new variable (or object)
    now.h = 17;  // assigns its hours field
    now.m = 45;  // assigns its minutes field
    //OR: Time now = { 17, 45 };
    
    printTime(now);
    
    return 0;
}
