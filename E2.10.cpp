//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: February 3, 2022
//Assignment: E2.10

//This program takes user inputs to print cost per 100 miles in a car and how far the car can go with amount of gas in the tank.

#include <iostream>
using namespace std;

int main(){
	float gas, eff, price;			//declare variables, obtain inputs//
	cout<<"Enter gallons of gas in tank: ";
	cin>>gas;
	cout<<"Enter fuel efficiency in miles per gallon: ";
	cin>>eff;
	cout<<"Enter price of gas per gallon: ";
	cin>>price;
	
	float ans1 = (100/eff)*price;
	float ans2 = eff*gas;
	
	//output//
	cout<< "The cost per 100 miles is $"<<ans1<<", and the car can go "<<ans2<<" miles with the gas in the tank."<<endl;
	
	return 0;
}
