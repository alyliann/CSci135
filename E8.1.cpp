//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: February 28, 2022
//Assignment: E8.1

//This program opens and closes a .txt file and prints the text it contains.

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    
    ofstream file;                  //output file stream
    file.open("hello.txt");
    
    file << "Hello, World!";        //inserts "Hello, World!" into file
    
    file.close();
    ifstream file2;                 //input file stream
    file2.open("hello.txt");
    
    string line;
    getline(file2, line);           //get first line in .txt file
    
    cout << line << endl;           //print "Hello, World!"
    
    return 0;
}
