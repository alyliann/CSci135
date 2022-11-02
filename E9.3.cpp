//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: April 14, 2022
//Assignment: E9.3

//This program simulates a circuit controlling hallway lamp.

#include <iostream>
using namespace std;

class Circuit {
private:
    int first_switch = 0;
    int second_switch = 0;
    int lamp_state = 0;
public:
    int get_first_switch_state();
    int get_second_switch_state();
    int get_lamp_state();
    void toggle_first_switch();
    void toggle_second_switch();
};

int Circuit::get_first_switch_state(){ // 0 for down, 1 for up
    return first_switch;
}

int Circuit::get_second_switch_state(){
    return second_switch;
}
int Circuit::get_lamp_state(){ // 0 for off. 1 for on
    if (first_switch == second_switch){
        lamp_state = 0;
    }
    else lamp_state = 1;
    return lamp_state;
}

void Circuit::toggle_first_switch(){
    if (first_switch == 0) first_switch = 1;
    else first_switch = 0;
}

void Circuit::toggle_second_switch(){
    if (second_switch == 0) second_switch = 1;
    else second_switch = 0;
}

int main(){
    
    
    
    return 0;
}
