//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: April 4, 2022
//Assignment: Lab Quiz 7

//This program creats a function that returns the maximum of 3 integers.

#include <iostream>
using namespace std;

int max3(int a, int b, int c){
    int max;
    
    if (a > b) max = a;
    else max = b;
    
    if (c > max) max = c;
    
    return max;
}

int main(){
    
    int a = 5, b = 7, c = 3;
    cout << max3(a, b, c) << endl;
    
    return 0;
}
