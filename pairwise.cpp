/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: April 26, 2022
Assignment: Lab 12D

This program returns a vector of integers whose elements are the pairwise sum of the elements from the two vectors passed as arguments.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> sumPairWise(vector<int> &v1, vector<int> &v2){
    int size;
    if (v1.size() < v2.size()) size = v1.size();
    else size = v2.size();              //choose size based on smaller vector
    
    vector<int> sum;
    
    for (int i = 0; i < size; i++){
        int num = v1[i] + v2[i];
        sum.push_back(num);             //add elements to sum vector
    }
    
    //add remaining elements to sum vector based on which vector is larger:
    if (v1.size() > v2.size()){
        for (int i = size; i < v1.size(); i++){
            sum.push_back(v1[i]);
        }
    }
    else{
        for (int i = size; i < v2.size(); i++){
            sum.push_back(v2[i]);
        }
    }
    
    return sum;
}

int main(){
    
    vector<int> v1{1,2,3};
    vector<int> v2{4,5};

    vector<int> vsum = sumPairWise(v1, v2); // returns [5, 7, 3]
    
    for (int i = 0; i < vsum.size(); i++){
        cout << vsum[i] << endl;
    }
    
    return 0;
}
