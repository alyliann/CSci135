//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: February 17, 2022
//Assignment: E4.8

//This program prints characters of a word on separate lines.

#include <iostream>
using namespace std;

int main(){
    
    string word;
    cout << "Enter a word: ";
    cin >> word;
    
    for (int i = 0; i < word.length(); i++){
        cout << word[i] << endl;
    }
    
    return 0;
}
