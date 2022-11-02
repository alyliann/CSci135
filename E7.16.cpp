//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: April 7, 2022
//Assignment: E7.16

//this program creates a structure Point and finds the distance between two points using a function.

#include <iostream>
#include <cmath>
using namespace std;

struct Point {               //structure
public:
    double x;
    double y;
};

double distance(Point a, Point b){
    
    double dist = sqrt((pow((b.x-a.x),2))+(pow((b.y-a.y),2)));      //equation
    
    return dist;
}

int main(){
    //Reads the coordinates of the points, calls your function, and displays the result.
    double ax, ay, bx, by;
    cout << "Enter first coordinates (x, y): ";
    cin >> ax;
    cin >> ay;
    
    cout << "Enter second coordinates (x, y): ";
    cin >> bx;
    cin >> by;
    
    double dist = distance({ax,ay}, {bx,by});           //ex: 1,1 4,5 = 5
    cout << dist << endl;
    
    return 0;
}
