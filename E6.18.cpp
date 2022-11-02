//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: April 28, 2022
//Assignment: E6.18

//This program takes two vectors and puts the elements of the second at the end of the first.

#include <iostream>
#include <vector>
using namespace std;

vector<int> append(vector<int> a, vector<int> b){
    vector<int> appended = a;
    
    for (int i = 0; i < b.size(); i++){
        appended.push_back(b[i]);
    }
    
    return appended;
}

int main(){
    
    vector<int> v1{1, 4, 9, 16};
    vector<int> v2{9, 7, 4, 9, 11};
    
    vector<int> app = append(v1, v2);     //returns  {1, 4, 9, 16, 9, 7, 4, 9, 11}
    
    for (int i = 0; i < app.size(); i++){
        cout << app[i] << endl;
    }
    
    return 0;
}
