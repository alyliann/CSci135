/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: February 14, 2022
Assignment: Lab 3A

This program prints out the East basin storage on a user-inputted date in 2018.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main(){
    
    string inDate;        //create string, obtain input date
    cout << "Enter a date in MM/DD/YYYY format: ";
    cin >> inDate;
    
    ifstream fin("Current_Reservoir_Levels.tsv");
    string junk;
    getline (fin, junk);     //throw out first line (header)
    
    string date;
    double eastSt;
    while (fin >> date >> eastSt){  //reads file line-by-line, extracting 2 values on each iteration
        
        fin.ignore(INT_MAX, '\n');  //ignores remaining columns
        
        //finds exact date user entered, prints storage on that day:
        if (date == inDate){
            cout << "East basin storage: " << eastSt << " billion gallons" << endl;
        }
    }
    return 0;
}
