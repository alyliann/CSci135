//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: April 13, 2022
//Assignment: Lab Quiz 9

//Define class Date with public data members year, month, day as int and day_of_week as string. Define printDate(Date *input) prints day_of_week, month/day/year. 12/6/2021, Monday, is printed "Monday, 12/6/2021"

#include <iostream>
using namespace std;

class Date {
    public:
        int year;
        int month;
        int day;
        string day_of_week;
};

void printDate(Date *input){
    // prints "day_of_week, month/day/year".
    // 12/6/2021 Monday is printed "Monday, 12/6/2021"
    
    cout << input->day_of_week << ", " << input->month << "/" << input->day << "/" << input->year << endl;
}

int main(){
    
    Date given = {2021, 12, 6, "Monday"};
    Date birthday = {2003, 3, 25, "Tuesday"};
    Date today = {2022, 4, 13, "Wednesday"};
    
    printDate(&given);
    printDate(&birthday);
    printDate(&today);
    
    return 0;
}
