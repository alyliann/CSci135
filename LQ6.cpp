//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: March 28, 2022
//Assignment: Lab Quiz 6

//This program creats a 6 by 5 rectangle of "*"s.

#include <iostream>
using namespace std;

int main(){
    
    for (int row = 0; row < 6; row++){
        for (int col = 0; col < 5; col++){
            if (col == 4) cout << "*";
            else cout << "* ";
        }
        cout << endl;
    }
    
    
    return 0;
}
