/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: April 26, 2022
Assignment: Lab 12B

This program creates a vector of ints 0 through n.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> goodVibes(const vector<int> v) {
    vector<int> pos;
    
    for (int i = 0; i < v.size(); i++){
        if (v[i] > 0)
            pos.push_back(v[i]);                //add positive elements only
    }
    
    return pos;
}

int main(){
    
    vector<int> v{1,2,-1,3,4,-1,6};
    
    vector<int> fixed = goodVibes(v);
    
    for (int i = 0; i < fixed.size(); i++){
        cout << fixed[i] << endl;
    }
    
    return 0;
}
