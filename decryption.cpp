/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: March 7, 2022
Assignment: Lab 6D

This program encrypts and then decrypts a string using caesar and vigenere ciphers.
*/

#include <iostream>
#include <string>
using namespace std;

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

string decryptCaesar(string ciphertext, int rshift){
    int e;
    for (int i = 0; i < ciphertext.length(); i++){
        e = ciphertext[i];
        
        if (e >= 'A' && e <= 'Z'){
            e -= rshift;                    //subtract instead of add shift
            if (e < 'A'){
                e = e + 'Z' - 'A' + 1;      //opposite of encrypt equation
            }
            ciphertext[i] = e;
        }
        
        else if (e >= 'a' && e <= 'z'){
            e -= rshift;
            if (e < 'a'){
                e = e + 'z' - 'a' + 1;
            }
            ciphertext[i] = e;
        }
    }
    return ciphertext;                      //returns decrypted text
}

string encryptVigenere(string plaintext, string keyword){
    int e, k = 0;
    for (int i = 0, j = 0; i < plaintext.length(); i++){
        e = plaintext[i];
        k = keyword[j] - 'a';
        
        if (e >= 'A' && e <= 'Z'){
            e += k;
            if (e > 'Z'){
                e = e - 'Z' + 'A' - 1;
            }
            plaintext[i] = e;
            j = (j + 1) % keyword.length();
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

string decryptVigenere(string ciphertext, string keyword){
    int e, k = 0;
    for (int i = 0, j = 0; i < ciphertext.length(); i++){
        e = ciphertext[i];
        k = keyword[j] - 'a';
        
        if (e >= 'A' && e <= 'Z'){
            e -= k;                    //subtract instead of add k
            if (e < 'A'){
                e = e + 'Z' - 'A' + 1;      //opposite of encrypt equation
            }
            ciphertext[i] = e;
            j = (j + 1) % keyword.length();
        }
        
        else if (e >= 'a' && e <= 'z'){
            e -= k;                    //subtract instead of add k
            if (e < 'a'){
                e = e + 'z' - 'a' + 1;      //opposite of encrypt equation
            }
            ciphertext[i] = e;
            j = (j + 1) % keyword.length();
        }
    }
    return ciphertext;                      //returns decrypted text
}


int main(){
    
    string text;
    int shift;
    string key;
    cout << "Enter plaintext\t: ";
    getline(cin, text);                     //gets input including spaces
    
    //Caesar
    cout << endl << "= Caesar =" << endl;
    do {
        cout << "Enter shift\t\t: ";
        cin >> shift;
    } while (shift < 0 || shift > 25);
    string cCipher = encryptCaesar(text, shift);
    cout << "Ciphertext\t\t: " << cCipher << endl;
    string cDecrypt = decryptCaesar(cCipher, shift);
    cout << "Decrypted\t\t: " << cDecrypt << endl << endl;
    
    //Vigenere
    cout << "= Vigenere =" << endl;
    cout << "Enter keyword\t: ";
    cin >> key;
    string vCipher = encryptVigenere(text, key);
    cout << "Ciphertext\t\t: " << vCipher << endl;
    string vDecrypt = decryptVigenere(vCipher, key);
    cout << "Decrypted\t\t: " << vDecrypt << endl;
    
    return 0;
}
