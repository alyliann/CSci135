/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: February 17, 2022
Assignment: Lab 4B

This program prints a checkerboard of a user-inputted width and height.
*/

#include <iostream>
using namespace std;

int main(){
    
    int w, h;                       //create variables, obtain inputs
    cout << "Input width: ";
    cin >> w;
    cout << "Input height: ";
    cin >> h;
    
    cout << "Shape: " << endl;
    for (int row = 0; row < h; row++){      //for each row of amount h
        for (int col = 0; col < w; col++){  //for each col of amount w
            if (row%2 != 0){                //if row is odd
                if (col%2 != 0){            //if column is odd
                    cout << " *";
                }
            }
            else{                           //if row is even
                if (col%2 == 0){            //if column is even
                    cout << "* ";
                }
            }
        }
        cout << endl;                       //move to next row
    }
    
    return 0;
}
