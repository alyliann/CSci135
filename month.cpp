/*
Author: Alysa Liann Vega
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab 1D

Take user-inputted month and output number of days in month.
*/

#include <iostream>
using namespace std;

int main()
{
	int year, month;			//declare variables, obtain inputs//
	cout << "Enter year: ";
	cin >> year;
	cout << "Enter month: ";
	cin >> month;

	if (month == 2){				//leap year if-conditions, from leap.cpp//
		if (year%4 != 0){
		cout << "28 days" << endl;}
		else if (year%100 != 0){
		cout << "29 days" << endl;}
		else if (year%400 != 0){
		cout << "28 days" << endl;}
		else{
		cout << "29 days" << endl;}
	}
	else{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
	    cout << "31 days" << endl;}
		else{
		cout << "30 days" << endl;}
	}

	return 0;
}
