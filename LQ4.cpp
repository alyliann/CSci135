//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: March 28, 2022
//Assignment: Lab Quiz 4

//Creates an array of ints 1-10 and prints each cell on separate lines.

#include <iostream>
using namespace std;

int main(){
    
    int arr[10];
    for (int i = 0; i < 10; i++){
        arr[i] = i+1;
        cout << arr[i] << endl;
    }
    
    return 0;
}
