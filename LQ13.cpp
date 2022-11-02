//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: May 1, 2022
//Assignment: Lab Quiz 13

//Define class Customer, which as data member name and unique_id, both of string type. Define default and non-default constructor, setter, and getter.

#include <iostream>
using namespace std;

class Customer {
private:
    string name;
    string unique_id;
public:
    Customer(string name, string unique_id);        //default constructor
    Customer();                                     //non-default constructor
    string get_name();                              //getters
    string get_unique_id();
    void set_name(string input_name);               //setters
    void set_unique_id(string input_unique_id);
};

Customer::Customer(string name, string unique_id){
    set_name(name);
    set_unique_id(unique_id);
}

Customer::Customer(){
    
}

string Customer::get_name(){
    return name;
}

string Customer::get_unique_id(){
    return unique_id;
}

void Customer::set_name(string input_name){
    name = input_name;
}

void Customer::set_unique_id(string input_unique_id){
    unique_id = input_unique_id;
}

int main(){
    
    Customer("Zoe", "Seven");                   //test
    Customer c = Customer("Mary", "Three");     //test
    
    cout << c.get_name() << " " << c.get_unique_id() << endl; //"Mary Three"
    
    return 0;
}

