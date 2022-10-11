//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: March 16, 2022
//Assignment: E7.1

//This program sorts two double values using a pass by address func

#include <iostream>
using namespace std;

void sort2 (double* p, double* q){
    
    if (*p > *q){
        double temp = *p;
        *p = *q;
        *q = temp;
    }
    return;
}

int main(){
    
    double x, y;
    cin >> x;
    cin >> y;
    sort2(&x, &y);      //address of x and y passed to sort2
    cout << "x = " << x << " and y = " << y << endl;
    
    return 0;
}
