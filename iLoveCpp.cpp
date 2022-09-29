//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: February 14, 2022
//Assignment: Lab Quiz 1

//This program prints "I love C++" a user-inputted number of times.

#include <iostream>
using namespace std;

int main(){
    
    int num;
    cout << "Enter a number: ";
    cin >> num;

    for (int i = 0; i < num; i++){
        cout << "I love C++" << endl;
    }
    return 0;
}
