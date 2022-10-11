//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: March 24, 2022
//Assignment: Lab Quiz 3

//This program prints the larger of two numbers.

#include <iostream>
using namespace std;

int main(){
    
    int x, y;
    cin >> x;
    cin >> y;
    
    if (x > y) cout << x << " is greater." << endl;
    else cout << y << " is greater." << endl;
    
    return 0;
}
