/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: February 14, 2022
Assignment: Lab 3C

This program compares E&W basin storage within a time frame, printing the higher storage for each day in the time frame.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main(){
    
    string startDate, endDate;        //create strings, obtain time frame
    cout << "Enter starting date: ";
    cin >> startDate;
    cout << "Enter ending date: ";
    cin >> endDate;
    
    ifstream fin("Current_Reservoir_Levels.tsv");
    string junk;
    getline (fin, junk);     //throw out first line (header)
    
    string date;
    double eastSt, eastEl, westSt, westEl;
    while (fin >> date >> eastSt >> eastEl >> westSt >> westEl){
        // this loop reads the file line-by-line, extracting 5 values on each iteration
        
        fin.ignore(INT_MAX, '\n');
        
        bool timeFrame;                 //create boolean outside of if-statement
        if (date == startDate){         //boolean for time frame
            timeFrame = true;
        }
        if (timeFrame == true){         //runs if bool == false
            if (eastEl == westEl){
                cout << date << " Equal" << endl;
            }
            if (eastEl < westEl){
                cout << date << " West" << endl;
            }
            else {          //east > west
                cout << date << " East" << endl;
            }
        }
        if (date == endDate){       //sets bool to false at end of time frame
            timeFrame = false;
        }
    }
    return 0;
}
