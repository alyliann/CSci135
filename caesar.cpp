/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: March 3, 2022
Assignment: Lab 6B

This program shifts each letter of a string by a user-inputted number.
*/

#include <iostream>
#include <string>
using namespace std;

char shiftChar(char c, int rshift){         //required helper funciton for 1 char
    int e = c;
    if (e >= 'A' && e <= 'Z'){           //all capital letters
        e += rshift;                     //shift by rshift
        if (e > 'Z'){
            e = e - 'Z' + 'A' - 1;       //loops back to 'A' after 'Z'
        }
        c = e;
    }
    
    else if (e >= 'a' && e <= 'z'){      //all lowercase letters
        e += rshift;
        if (e > 'z'){
            e = e - 'z' + 'a' - 1;
        }
        c = e;
    }
    return c;                        //returns encrypted text
}

string encryptCaesar(string plaintext, int rshift) {    //encrypts text
    int e;
    for (int i = 0; i < plaintext.length(); i++){
        e = plaintext[i];
        
        if (e >= 'A' && e <= 'Z'){           //all capital letters
            e += rshift;                     //shift by rshift
            if (e > 'Z'){
                e = e - 'Z' + 'A' - 1;       //loops back to 'A' after 'Z'
            }
            plaintext[i] = e;                //change letter to encrypted letter
        }
        
        else if (e >= 'a' && e <= 'z'){      //all lowercase letters
            e += rshift;
            if (e > 'z'){
                e = e - 'z' + 'a' - 1;
            }
            plaintext[i] = e;
        }
    }
    return plaintext;                        //returns encrypted text
}

int main() {
    /*string text;
    int shift;
    cout << "Enter plaintext\t: ";
    getline(cin, text);                     //gets input including spaces
    do {
        cout << "Enter shift\t: ";
        cin >> shift;
    } while (shift < 0 || shift > 25);      //rshift must be btwn 0 and 25
    
    string cipher = encryptCaesar(text, shift);     //call to encryption func
    
    cout << "Ciphertext\t\t: " << cipher << endl;*/
    
    cout << shiftChar('z', 8) << endl;
    
    return 0;
}
