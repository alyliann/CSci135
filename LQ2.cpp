//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: March 10, 2022
//Assignment: Lab Quiz 2

//This program prints a pyramid using a string.

#include <iostream>
#include <string>
using namespace std;

int main(){
    
    string str;
    cout << "Input a string: ";
    getline(cin, str);                     //include spaces
    
    //top half:
    for (int line = 0; line < str.length(); line++){    //for each line
        for (int let = 0; let < str.length(); let++){   //for each letter
            if (line == let || line > let){
                cout << str[let];
            }
        }
        cout << endl;                       //move to next line
    }
    //bottom half:
    for (int line = str.length()-2; line >= 0; line--){
        for (int let = 0; let <= line; let++){
            if (line == let || line > let){
                cout << str[let];
            }
        }
        cout << endl;                       //move to next line
    }
    
    return 0;
}
