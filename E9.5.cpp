//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: April 14, 2022
//Assignment: E9.5

//Implement a class Rectangle. Provide a constructor to construct a rectangle with a given width and height, member functions get perimeter and get area that compute the perimeter and area, and a member function void resize (double factor) that resizes the rectangle by multiplying the width and height by the given factor.

#include <iostream>
using namespace std;

class Rectangle {
private:
    double width;
    double height;
public:
    Rectangle(double input_w, double input_h);
    double get_perimeter();
    double get_area();
    void resize(double factor); //resizes  rectangle by multiplying the width and height by the given factor.
};

Rectangle::Rectangle(double input_w, double input_h){
    width = input_w;
    height = input_h;
}

double Rectangle::get_perimeter(){
    return (2 * (width + height));
}

double Rectangle::get_area(){
    return (width * height);
}

void Rectangle::resize(double factor){                                                 //resizes  rectangle by multiplying the width and height by the given factor.
    width *= factor;
    height *= factor;
}

int main(){
    
    
    
    return 0;
}
