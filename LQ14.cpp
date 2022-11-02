//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: May 1, 2022
//Assignment: Lab Quiz 14

//Vectors Define function vector<int> makeVector(int n) which, if n is positive, returns a vector of ints of O to n-1.

#include <iostream>
#include <vector>
using namespace std;

vector<int> makeVector(int n){
    vector<int> v;
    
    if (n > 0){
        for (int i = 0; i < n; i++){
            v.push_back(i);             //adds elements 0 to n-1 to vector
        }
    }
        
    return v;
}

int main(){
    
    vector<int> u = makeVector(5);          //u = {0, 1, 2, 3, 4}
    
    for (int i = 0; i < u.size(); i++){
        if (i < u.size()-1)
            cout << u[i] << " ";
        else
            cout << u[i];
    }
    cout << endl;
    
    return 0;
}
