//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: March 28, 2022
//Assignment: Lab Quiz 5

//This program opens a .txt file and prints every line in the file before closing.

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    
    ifstream fin;
    fin.open("data.txt");
    string line;
    
    while (getline(fin, line)){
        cout << line << endl;
    }
    
    fin.close();
    
    return 0;
}
