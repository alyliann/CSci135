/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: April 26, 2022
Assignment: Lab 12A

This program creates a vector of ints 0 through n.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> makeVector(int n){
    vector<int> v;
    
    for (int i = 0; i < n; i++){
        v.push_back(i);                 //add i to vector v
    }
    
    return v;
}

int main(){
    
    
    
    return 0;
}
