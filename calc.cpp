/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: February 7, 2022
Assignment: Project 1B

This program takes a formula from a .txt file and outputs the result.
*/

#include <iostream>
using namespace std;

int main(){
    
    int sum = 0, num;
    char opr;
    cin >> num;
    sum = num;
    while (cin >> opr){
        cin >> num;
        if (opr == '+'){
            sum += num;
        }
        else{
            sum = sum - num;
        }
    }
    cout << sum << endl;
    
    return 0;
}
