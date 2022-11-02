/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: April 26, 2022
Assignment: Lab 12C

This program uses two vectors, fills the first with the second vector's elements, and empties the second vector.
*/

#include <iostream>
#include <vector>
using namespace std;

void gogeta(vector<int> &goku, vector<int> &vegeta){
    for (int i = 0; i < vegeta.size(); i++){
        goku.push_back(vegeta[i]);              //add elements of vegeta to goku
    }
    
    vegeta.clear();                             //empty vegeta
}

int main(){
    
    vector<int> v1{1,2,3};
    vector<int> v2{4,5};

    gogeta(v1, v2);
    
    for (int i = 0; i < v1.size(); i++){
        cout << v1[i] << endl;
    }
    
    return 0;
}
