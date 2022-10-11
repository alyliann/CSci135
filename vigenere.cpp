/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: March 7, 2022
Assignment: Lab 6C

This program shifts each letter of a string by a number corresponding to each letter of a word.
*/

#include <iostream>
#include <string>
using namespace std;

string encryptVigenere(string plaintext, string keyword){   //encrypts text
    int e, k = 0;
    for (int i = 0, j = 0; i < plaintext.length(); i++){
        e = plaintext[i];
        k = keyword[j] - 'a';
        
        if (e >= 'A' && e <= 'Z'){        //same thing as caesar, but:
            e += k;                       //shifts letter by letter in keyword
            if (e > 'Z'){
                e = e - 'Z' + 'A' - 1;
            }
            plaintext[i] = e;             //set letter to encrypted letter
            j = (j + 1) % keyword.length();     //keeps j below keyword.length()
        }
        
        else if (e >= 'a' && e <= 'z'){
            e += k;
            if (e > 'z'){
                e = e - 'z' + 'a' - 1;
            }
            plaintext[i] = e;
            j = (j + 1) % keyword.length();
        }
    }
    return plaintext;                        //returns encrypted text
}


int main() {
    string text;                            //declare variables, obtain inputs
    string key;                             //1 word, lowercase
    cout << "Enter plaintext\t: ";
    getline(cin, text);                     //gets input including spaces
    cout << "Enter keyword\t: ";
    cin >> key;
    
    string cipher = encryptVigenere(text, key);     //call to encryption func
    
    cout << "Ciphertext\t\t: " << cipher << endl;
    
    return 0;
}
