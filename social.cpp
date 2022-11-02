/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: April 11, 2022
Assignment: Lab 11A

This program uses class Profile and methods for various purposes.
*/

#include <iostream>
using namespace std;

class Profile {
private:
    string username;
    string displayname;
public:
    Profile(string usrn, string dspn);                                              // Profile constructor for a user (initializing private variables username=usrn, displayname=dspn)
    Profile();                                                                      // Default Profile constructor (username="", displayname="")
    string getUsername();                                                           // Return username
    string getFullName();                                                           // Return name in the format: "displayname (@username)"
    void setDisplayName(string dspn);                                               // Change display name
};

Profile::Profile(string usrn, string dspn){
    username = usrn;
    displayname = dspn;
}

string Profile::getUsername(){
    return username;
}

string Profile::getFullName(){
    
    string fullName = displayname + " (@" + username + ")";
    
    return fullName;
}

void Profile::setDisplayName(string dspn){
    displayname = dspn;
}
    
int main() {
    Profile p1("marco", "Marco");
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco (@marco)

    p1.setDisplayName("Marco Rossi");
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco Rossi (@marco)
    
    Profile p2("tarma1", "Tarma Roving");
    cout << p2.getUsername() << endl; // tarma1
    cout << p2.getFullName() << endl; // Tarma Roving (@tarma1)
}
