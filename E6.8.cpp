//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: March 7, 2022
//Assignment: E6.8

//This program uses a boolean function to check if two arrays have the same elements in the same order

#include <iostream>
using namespace std;

bool equals(int a[], int a_size, int b[], int b_size){
    
    bool TorF = true;
    
    int size = a_size;
    if (b_size > a_size){
        size = b_size;
    }
    for (int i = 0; i < size; i++){
        if (a[i] != b[i]){              //compares every element in both arrays
            TorF = false;
            break;                      //breaks at first non-equal element
        }
    }
    return TorF;                        //returns true or false
}

int main(){
    
    int a[5], b[5];
    for (int i = 0; i < 5; i++){
        cout << "Input element of first array: ";
        cin >> a[i];
    }
    for (int i = 0; i < 5; i++){
        cout << "Input element of second array: ";
        cin >> b[i];
    }
    
    /*{6, 46, 98, 18, 69};
    {6, 46, 98, 18, 69};
    {'L', 'B', 'M', 'V', 'A'};
    {'T', 'B', 'R', 'E', 'H'};*/
    
    cout << equals(a, (sizeof(a)/sizeof(a[0])), b, (sizeof(b)/sizeof(b[0])) << endl;
    
    /*if (test == true){
        cout << "Arrays are equal" << endl;
    }
    else{
        cout << "Arrays are not equal" << endl;
    }*/
    
    return 0;
}
