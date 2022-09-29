/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: February 14, 2022
Assignment: Lab 3D

This program prints dates and West basin elevations within a time frame in reverse order.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main(){
    
    string earlDate, latDate;        //create strings, obtain time frame
    cout << "Enter earlier date: ";
    cin >> earlDate;
    cout << "Enter later date: ";
    cin >> latDate;
    
    ifstream fin("Current_Reservoir_Levels.tsv");
    string junk;
    getline (fin, junk);     //throw out first line (header)
    
    string array[1000], temp;
    int index = 0;
    bool timeFrame = false;
    string date;
    double eastSt, eastEl, westSt, westEl;
    while (fin >> date >> eastSt >> eastEl >> westSt >> westEl){
        // this loop reads the file line-by-line, extracting 5 values on each iteration
        
        fin.ignore(INT_MAX, '\n');
        
        string wEl = to_string(westEl);
        for (int i = 0; i < wEl.length(); i++){
            if (wEl[i] == '.'){
                if (wEl[i+1] == '0'){
                    if (wEl[i+2] == '0'){
                        temp = wEl.substr(0, i);
                    }
                    else {
                        temp = wEl.substr(0, i+3);
                    }
                }
                else if (wEl[i+2] == '0'){
                    temp = wEl.substr(0, i+2);
                }
                else {
                    temp = wEl.substr(0, i+3);
                }
                break;
            }
        }
        
        if (date == earlDate){         //boolean for time frame
            timeFrame = true;
        }
        if (timeFrame == true){
            array[index] = date + " " + temp + " ft";
                //adds each date and corresponding elevation to array
            index += 1;     //adds 1 to index each time to eventually have index = to number of dates in array
            }
        if (date == latDate){       //sets bool to false at end of time frame
            break;
        }
    }
    for (int i = index; i >= 0; i--){     //counts backwards from index to 0
        cout << array[i] << endl;
    }
    return 0;
}
