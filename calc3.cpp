/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: February 8, 2022
Assignment: Project 1D

 This program reads formulas from a .txt file and outputs each result, including squared numbers.
*/

#include <iostream>
using namespace std;

int main(){
    
    int sum = 0, num;
    char opr;               //variable for + and - and ^
    cin >> num;             //input 1st number of formula to num
    if (cin.peek() == '^'){     //check if opr is a ^
        num *= num;             //if so, square num
        cin >> opr;
    }
    sum = num;
    while (cin >> opr){     //while there are characters left in formula
        if (cin.peek() == '^'){
            num *= num;
        }
        else if (opr == '+'){
            cin >> num;
            if (cin.peek() == '^'){
                num *= num;
                cin >> opr;
            }
            sum += num;     //addition
        }
        else if (opr == '-'){
            cin >> num;
            if (cin.peek() == '^'){
                num *= num;
                cin >> opr;
            }
            sum -= num;     //subtraction
        }
        else if (opr == ';'){
            cout << sum << endl;
            cin >> num;
            if (cin.peek() == '^'){
                num *= num;
                cin >> opr;
            }
            sum = num;
        }
    }
    return 0;
}
