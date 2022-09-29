/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: February 8, 2022
Assignment: Lab 2C

This program outputs the result of user-inputted array values and indexes.
*/

#include <iostream>
using namespace std;

int main(){
    int myData[10];         //create array of 10 cells//
    for (int i = 0; i < 10; i++){       //for loop to make every cell = 1//
        myData[i] = 1;
        cout << myData[i] << " ";      //print array//
    }
    cout << endl;
    
    int i, v;               //obtains initial user index and value//
    cout << "Input index: ";
    cin >> i;
    cout << "Input value: ";
    cin >> v;
    
    while (i >= 0 && i < 10){
        myData[i] = v;              //change array to user inputs//
        for (int i = 0; i < 10; i++){   //prints array//
            cout << myData[i] << " ";
        }
        cout << endl;
        cout << "Input index: ";    //obtains user index and value//
        cin >> i;
        cout << "Input value: ";
        cin >> v;
    }
    cout << endl;
    
    if (i < 0 || i >= 10){          //ends program if index out of range//
        cout << "Index out of range. Exit." << endl;
    }
    
    return 0;
}
