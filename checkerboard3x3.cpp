/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: February 22, 2022
Assignment: Lab 4G

This program prints a checkerboard of 3x3 squares of a user-inputted width and height.
*/

#include <iostream>
using namespace std;

int main() {
    int w, h;                       //create variables, obtain inputs
    cout << "Input width: ";
    cin >> w;
    cout << "Input height: ";
    cin >> h;
    
    cout << "Shape: " << endl;
    for (int row = 0; row < h; row++){          //for each row
        for (int col = 0; col < w; col++){      //for each column
            if ((col/3)%2 == 0 && (row/3)%2 == 0){
                //"even" (0,1,2...6,7,8) columns and rows
                cout << "*";
            }
            else if ((col/3)%2 == 1 && (row/3)%2 == 1){
                cout << "*";
                //"odd" (3,4,5...9,10,11) columns and rows
            }
            else{
                cout << " ";
            }
            
        }
        cout << endl;
    }
    return 0;
}
