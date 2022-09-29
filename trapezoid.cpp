/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: February 22, 2022
Assignment: Lab 4F

This program prints out bottom-left half of a square of a user-inputted dimension.
*/

#include <iostream>
using namespace std;

int main(){
    
    int w, h;                       //create variables, obtain inputs
    cout << "Input width: ";
    cin >> w;
    cout << "Input height: ";
    cin >> h;
    
    if (w%2 == 0 && h > (w/2)){
        cout << "Impossible shape!" << endl;
        return 0;
    }
    else if (w%2 != 0 && h >= w-1){
        cout << "Impossible shape!" << endl;
        return 0;
    }
    
    cout << "Shape: " << endl;
    for (int row = 0; row < h; row++){      //for each row of amount h
        for (int col = 0; col < w; col++){  //for each col of amount w
            if (col >= w - row){
                cout << " ";
            }
            else if (row == col || row < col){       //creates triangle shape
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
