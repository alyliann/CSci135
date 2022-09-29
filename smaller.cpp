/*
Author: Alysa Liann Vega
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab 1A

This program finds the smaller of two user-inputted integers.
*/

#include <iostream>
using namespace std;

int main()
{
	int int1, int2;				// creating variables //
	cout << "Enter the first number: ";
	cin >> int1;
	cout << "Enter the second number: ";
	cin >> int2;
	if (int1 < int2){
		cout << "The smaller of the two is " << int1 << endl;}
	else{
		cout << "The smaller of the two is " << int2 << endl;}
return 0;
}
