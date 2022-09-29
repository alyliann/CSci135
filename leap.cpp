/*
Author: Alysa Liann Vega
Course: CSCI-136
Instructor: Tong Yi
Date: February 2, 2022
Assignment: Lab 1C

This program prints whether the inputted year is/was a leap year or not.
*/

#include <iostream>
using namespace std;

int main()
{
	int year;			//declare variable, obtain input//
	cout << "Enter year: ";
	cin >> year;

	if (year%4 != 0){		//if conditions//
	cout << "Common year" << endl;}
	else if (year%100 != 0){
	cout << "Leap year" << endl;}
	else if (year%400 != 0){
	cout << "Common year" << endl;}
	else{
	cout << "Leap year" << endl;}
	
	return 0;
}
