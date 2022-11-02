/*
 Author: Alysa Liann Vega
 Course: CSCI-135
 Instructor: Tong Yi
 Date: April 11, 2022
 Assignment: Lab 11C
 
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
    bool following[MAX_USERS][MAX_USERS];                                           // friendship matrix: following[id1][id2] == true when id1 is following id2
public:
    Network();                                                                        // Constructor, makes an empty network (numUsers = 0)
    bool addUser(string usrn, string dspn);                                           // Attempts to sign up a new user with specified username and displayname    // Return true if the operation was successful, otherwise return false
    bool follow(string usrn1, string usrn2);                                        // Make 'usrn1' follow 'usrn2' (if both usernames are in the network). return true if success (if both usernames exist), otherwise return false
    void printDot();                                                                // Print Dot file (graphical representation of the network)
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
    for (int i = 0; i < MAX_USERS; i++){
        for (int j = 0; j < MAX_USERS; j++){
            following[i][j] = false;
        }
    }
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

//Task C:
bool Network::follow(string usrn1, string usrn2){

    if (findID(usrn1) != -1 && findID(usrn2) != -1){
        following[findID(usrn1)][findID(usrn2)] = true;
        return true;
    }
    else return false;
    
}

void Network::printDot(){
    
    cout << "digraph {" << endl;
    //users:
    for (int i = 0; i < numUsers; i++){
        cout << "\"@" << profiles[i].username << "\"" << endl;
    }
    
    cout << endl;
    
    //following:
    for (int i = 0; i < numUsers; i++){
        for (int j = 0; j < numUsers; j++){
            if (following[i][j]){
                cout << "\"@" << profiles[i].username << "\" -> \"@" << profiles[j].username << "\"" << endl;
            }
        }
    }
    cout << "}" << endl;
}

int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}
