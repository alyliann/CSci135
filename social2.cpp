/*
 Author: Alysa Liann Vega
 Course: CSCI-135
 Instructor: Tong Yi
 Date: April 11, 2022
 Assignment: Lab 11B
 
 This program uses classes Profile and Network and methods for various purposes.
 */

#include <iostream>
using namespace std;

class Profile {
public:
    string username;
    string displayname;
    Profile(string usrn, string dspn);                                              // Profile constructor for a user (initializing private variables username=usrn, displayname=dspn)
    Profile();                                                                      // Default Profile constructor (username="", displayname="")
    string getUsername();                                                           // Return username
    string getFullName();                                                           // Return name in the format: "displayname (@username)"
    void setDisplayName(string dspn);                                               // Change display name
};

class Network {
private:
    static const int MAX_USERS = 20;                                                  // max number of user profiles
    int numUsers;                                                                      // number of registered users
    Profile profiles[MAX_USERS];                                                      // user profiles array: mapping integer ID -> Profile
    int findID (string usrn);                                                         // Returns user ID (index in the 'profiles' array) by their username (or -1 if username is not found)
public:
    Network();                                                                        // Constructor, makes an empty network (numUsers = 0)
    bool addUser(string usrn, string dspn);                                           // Attempts to sign up a new user with specified username and displayname    // Return true if the operation was successful, otherwise return false
};

//Task A:
Profile::Profile(string usrn, string dspn){
    username = usrn;
    displayname = dspn;
}

Profile::Profile(){
    username = "";
    displayname = "";
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

//Task B:
int Network::findID(string usrn){
    for (int i = 0; i < MAX_USERS; i++){
        if (profiles[i].username == usrn){
            int ID = i;
            return ID;
        }
    }
    return -1;
}

Network::Network(){
    numUsers = 0;
}

bool Network::addUser(string usrn, string dspn){
    // User must meet conditions:
    // the new username usrn must be a non-empty alphanumeric string,
    // there is no other users in the network with the same username,
    // the array profiles is not full.
    
    if (usrn.length() == 0) return false;       //if empty
    for (int i = 0; i < usrn.length(); i++){
        if (isalpha(usrn[i]) || isdigit(usrn[i]));
        else return false;      //if not alpha-numeric
    }
    if (numUsers == 20) return false;           //if array profiles is full
    if (usrn[usrn.length()-1] != dspn[dspn.length()-1]) return false;
    
    profiles[numUsers] = {usrn, dspn};
    numUsers++;                 //increase numUsers to match number of users
    return true;
}

int main() {
    Network nw;
    cout << nw.addUser("mario", "Mario") << endl;     // true (1)
    cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)
    
    cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
    cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
    cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)
    
    for(int i = 2; i < 20; i++)
        cout << nw.addUser("mario" + to_string(i),
                           "Mario" + to_string(i)) << endl;   // true (1)
    
    cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
}
