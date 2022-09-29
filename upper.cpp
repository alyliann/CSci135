/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: February 22, 2022
Assignment: Lab 4E

This program prints out top-right half of a square of a user-inputted dimension.
*/

#include <iostream>
using namespace std;

int main(){
    
    int size;                       //create variables, obtain inputs
    cout << "Input side length: ";
    cin >> size;
    
    cout << "Shape: " << endl;
    for (int row = 0; row < size; row++){       //for each row
        for (int col = 0; col < size; col++){   //for each column
            if (row == col || row < col){       //creates triangle shape
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;                       //move to next row
    }
    
    return 0;
}
