/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: March 24, 2022
Assignment: Lab 9 (not 9D)

This program uses pointer variables and arrays.
*/

#include <iostream>
#include <cmath>
using namespace std;

class Coord3D {
public:
    double x;
    double y;
    double z;
};

//Lab 9A:
// Computes the distance from the origin to a point.
// Input: a pointer to the point
// Output: the distance (via a return statement)
double length(Coord3D *p) {
    
    return sqrt(p->x*p->x+p->y*p->y+p->z*p->z);
    
}

//Lab 9B:
Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2){
    
    if (length(p1) > length(p2)) return p1;
    else return p2;
    
}

//Lab 9C:
void move(Coord3D *ppos, Coord3D *pvel, double dt){
    
    ppos->x = ppos->x + pvel->x * dt;
    ppos->y = ppos->y + pvel->y * dt;
    ppos->z = ppos->z + pvel->z * dt;
    
}

//Lab 9E:
// allocate memory and initialize
Coord3D* createCoord3D(double x, double y, double z){

    Coord3D *length;
    length = new Coord3D;         //dynamically allocate and initialize
    
    length->x = x;                //can also be written as: (*length).x
    length->y = y;
    length->z = z;
    
    return length;
}

// free memory
void deleteCoord3D(Coord3D *p){
    delete p;
}


int main() {
    double x, y, z;
    cout << "Enter position: ";
    cin >> x >> y >> z;
    Coord3D *ppos = createCoord3D(x,y,z);
    
    cout << "Enter velocity: ";
    cin >> x >> y >> z;
    Coord3D *pvel = createCoord3D(x,y,z);
    
    move(ppos, pvel, 10.0);
    
    cout << "Coordinates after 10 seconds: "
    << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;
    
    deleteCoord3D(ppos); // release memory
    deleteCoord3D(pvel);
}

