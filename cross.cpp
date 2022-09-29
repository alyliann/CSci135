/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: February 17, 2022
Assignment: Lab 4C

This program prints a cross of a user-inputted dimension.
*/

#include <iostream>
using namespace std;

int main(){
    
    int size;
    cout << "Input size: ";
    cin >> size;
    
    cout << "Shape: " << endl;
    for (int row = 0; row < size; row++){      //for each row
        for (int col = 0; col < size; col++){  //for each column
            if (row == col || col == size - (row+1)){      //creates cross shape
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
