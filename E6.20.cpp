//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: April 28, 2022
//Assignment: E6.20

//merges two sorted vectors, producing a new vector sorted from least to greatest.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> merge_sorted(vector<int> a, vector<int> b){
    vector<int> merged = a;
    
    for (int i = 0; i < b.size(); i++){
        merged.push_back(b[i]);             //merge vectors b4 sorting
    }
    
    sort(merged.begin(), merged.end());     //sort() func sorts array.
    
    return merged;
}

int main(){
    
    vector<int> v1{1, 4, 9, 16};
    vector<int> v2{4, 7, 9, 9, 11};

    
    vector<int> combo = merge_sorted(v1, v2);     //{1, 4, 4, 7, 9, 9, 9, 11, 16}
    
    for (int i = 0; i < combo.size(); i++){
        cout << combo[i] << endl;
    }
    
    return 0;
}
