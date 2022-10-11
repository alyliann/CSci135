/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: March 14, 2022
Assignment: Lab 7B

This program counts open blocks in a line of code.
*/

#include <iostream>
#include <cctype>       //isspace
using namespace std;

string removeLeadingSpaces(string line){
    string noSpaces = "";
    for (int i = 0; i < line.length(); i++){        //keeps empty lines
        if (isspace(line[i])){
            noSpaces += line[i];
        }
        else{
            noSpaces = "";
            break;
        }
    }
    for (int i = 0; i < line.length(); i++){
        if (!isspace(line[i])){           //if character is not a white-space
            for (int j = i; j < line.length(); j++){   //every char after non-space
                noSpaces += line[j];      //add char to return string
            }
            break;
        }
    }
    return noSpaces;
}

int countChar(string line, char c){
    int count = 0;
    for (int i = 0; i < line.length(); i++){
        if (line[i] == c){
            count += 1;
        }
    }
    return count;
}

int main(){
    
    string line;
    int count = 0;
    while (getline(cin, line)){
        line = removeLeadingSpaces(line);
        for (int i = 0; i < (line[0] == '}' ? count - 1 : count); i++){
            cout << "\t";                       //add tabs for # of blocks
        }
        cout << line << endl;
        count += countChar(line, '{');
        count -= countChar(line, '}');
    }

    return 0;
}
