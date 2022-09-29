//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: February 17, 2022
//Assignment: E3.1

//This program prints whether an integer is negative, positive, or zero.

#include <iostream>
using namespace std;

int main(){
    
    int num;
    cout << "Enter an integer: ";
    cin >> num;
    
    if (num < 0){
        cout << "Negative" << endl;
    }
    else if (num > 0){
        cout << "Positive" << endl;
    }
    else{
        cout << "Zero" << endl;
    }
    
    return 0;
}
