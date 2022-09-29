//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: February 28, 2022
//Assignment: E5.15

//This program swaps 3 integers to arrange them in sorted order.

#include <iostream>
using namespace std;

void sort2(int& a, int& b){         //swaps a and b if a > b
    
    if (a >= b){
        int old_a = a;              //holds original value of a
        a = b;
        b = old_a;
    }
    
}

void sort3(int& a, int& b, int& c){     //sorts integers a, b, and c
    
    sort2(a,c);
    sort2(a,b);
    sort2(b,c);
    
}

int main(){
    
    int v = 3;                          //integers to sort
    int w = 4;
    int x = 1;
    sort3(v, w, x);                     //v is now 1, w is now 3, x is now 4
    
    cout << "v is " << v << ", w is " << w << ", and x is " << x << endl;
    
    return 0;
}
