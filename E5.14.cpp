//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: February 28, 2022
//Assignment: E5.14

//This program uses another function to determine if int a is greater than int b, and swaps them if it is.

#include <iostream>
using namespace std;

void sort2(int& a, int& b){         //swaps a and b if a > b
    
    if (a > b){
        int old_a = a;              //holds original value of a
        a = b;
        b = old_a;
    }
    
}

int main(){
    
    int u = 2;                      //integers to compare
    int v = 3;
    int w = 4;
    int x = 1;
    sort2(u, v);                    //u is still 2, v is still 3
    sort2(w, x);                    //w is now 1, x is now 4
    
    cout << "u is " << u << " and v is " << v << endl;
    cout << "w is " << w << " and x is " << x << endl;
    
    return 0;
}
