/*
Author: Alysa Liann Vega
Course: CSCI-136
Instructor: Tong Yi
Date: February 2, 2022
Assignment: Lab 1B

This program finds the smallest of three user-inputted integers.
*/

#include <iostream>
using namespace std;

int main(){

	int int1, int2, int3, small;			//declaring variables//
	cout << "Enter the first number: " << endl;
	cin >> int1;
	cout << "Enter the second number: " << endl;
	cin >> int2;
	cout << "Enter the third number: " << endl;
	cin >> int3;

	if (int1 < int2){		//if conditions//
	small = int1;}
	else{
	small = int2;}
	if (int3 < small){
	small = int3;}

	cout << "The smaller of the three is " << small << endl;	

    return 0;
}
