//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: February 17, 2022
//Assignment: E3.5

//This program prints if a 3-number sequence is increasing, decreasing, or neither.

#include <iostream>
using namespace std;

int main(){
    
    int num1, num2, num3;
    cout << "Enter a number: ";
    cin >> num1;
    cout << "Enter another number: ";
    cin >> num2;
    cout << "Enter another number: ";
    cin >> num3;
    
    if (num1 < num2 && num2 < num3){
        cout << "Increasing" << endl;
    }
    else if (num3 < num2 && num2 < num1){
        cout << "Decreasing" << endl;
    }
    else{
        cout << "Neither" << endl;
    }
    
    return 0;
}
