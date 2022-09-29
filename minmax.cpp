/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: February 14, 2022
Assignment: Lab 3B

This program finds the minimum and maximum East basin storage in 2018.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main(){
    
    ifstream fin("Current_Reservoir_Levels.tsv");
    string junk;
    getline (fin, junk);     //throw out first line (header)
    
    int i = 0;
    string date;
    double eastSt, min, max;
    while (fin >> date >> eastSt){  //reads file line-by-line, extracting 2 values on each iteration
        
        fin.ignore(INT_MAX, '\n');
        
        if (i++ == 0){              //for first iteration, do:
            min = eastSt;
            max = eastSt;
        }
        if (eastSt < min){          //always set min to lowest value
            min = eastSt;
        }
        else if (eastSt > max){     //always set max to highest value
            max = eastSt;
        }
    }
    cout << "Minimum storage in East basin: " << min << " billion gallons" << endl << "Maximum storage in East basin: " << max << " billion gallons" << endl;
    
    return 0;
}
