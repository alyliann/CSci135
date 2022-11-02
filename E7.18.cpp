//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: April 7, 2022
//Assignment: E7.18

//this program uses E7.16 and adds a structure Triangle of 3 points along with a function to calculate the perimeter of a Triangle.

#include <iostream>
#include <cmath>
using namespace std;

struct Point {               //structure
public:
    double x;
    double y;
};

struct Triangle {
public:
    Point a;
    Point b;
    Point c;
};

double distance(Point a, Point b){
    
    double dist = sqrt((pow((b.x-a.x),2))+(pow((b.y-a.y),2)));      //equation
    
    return dist;
}

double perimeter(Triangle t){
    
    double perim = distance(t.a, t.b) + distance(t.b, t.c) + distance(t.c, t.a);
    
    return perim;
}

int main(){
    //Write a program that reads the coordinates of the points, calls your function, and displays the result.
    double ax, ay, bx, by, cx, cy;
    cout << "Enter first coordinates (x, y): ";
    cin >> ax;
    cin >> ay;
    
    cout << "Enter second coordinates (x, y): ";
    cin >> bx;
    cin >> by;
    
    cout << "Enter third coordinates (x, y): ";
    cin >> cx;
    cin >> cy;
    
    Triangle t = {{ax,ay},{bx,by},{cx,cy}};         //initialize triangle points
    //ex: 1,1 1,2 2,1 = 3.41421...
    
    double perim = perimeter(t);                    //call perimeter func
    cout << perim << endl;
    
    return 0;
}
