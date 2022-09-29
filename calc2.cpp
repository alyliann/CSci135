/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: February 8, 2022
Assignment: Project 1C

This program reads formulas from a .txt file and outputs each result.
*/

#include <iostream>
using namespace std;

int main(){
    
    int sum = 0, num;
    char opr;               //variable for + and -
    cin >> num;             //input 1st number of formula to num
    sum = num;              //set sum = to 1st number of formula
    while (cin >> opr){     //while there are characters left in formula
        cin >> num;         //holds numbers in num
        if (opr == '+'){
            sum += num;     //addition
        }
        else if (opr == '-'){
            sum -= num;     //subtraction
        }
        else if (opr == ';'){
            cout << sum << endl;
            sum = num;
        }
    }
    
    return 0;
}
