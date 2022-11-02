/*
 Author: Alysa Liann Vega
 Course: CSCI-135
 Instructor: Tong Yi
 Date: April 13, 2022
 Assignment: Lab 11D
 
 This program uses struct Post, classes Profile and Network, and methods for various purposes.
 */

#include <iostream>
using namespace std;

struct Post{
    string username;
    string message;
};

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
    static const int MAX_POSTS = 100;
    int numPosts;                                                                   // number of posts
    Post posts[MAX_POSTS];                                                          // array of all posts
public:
    Network();                                                                        // Constructor, makes an empty network (numUsers = 0)
    bool addUser(string usrn, string dspn);                                           // Attempts to sign up a new user with specified username and displayname    // Return true if the operation was successful, otherwise return false
    bool follow(string usrn1, string usrn2);                                        // Make 'usrn1' follow 'usrn2' (if both usernames are in the network). return true if success (if both usernames exist), otherwise return false
    void printDot();                                                                // Print Dot file (graphical representation of the network)
    bool writePost(string usrn, string msg);                                       // Add a new post
    bool printTimeline(string usrn);                                                // Print user's "timeline"
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
    numPosts = 0;
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

//Task D:
bool Network::writePost(string usrn, string msg){
    if (numPosts < 100){
        posts[numPosts] = {usrn, msg};
        numPosts++;
        return true;
    }
    else return false;
}

bool Network::printTimeline(string usrn){
    
    int usr = findID(usrn);
    
    for (int i = numPosts-1; i >= 0; i--){
        for (int j = 0; j < numUsers; j++){
            if (following[usr][j] && (posts[i].username == profiles[j].username)){
                cout << profiles[j].displayname << " (@" << profiles[j].username << "): " << posts[i].message << endl;
            }
            else if (usr == j && (posts[i].username == usrn)){
                cout << profiles[j].displayname << " (@" << profiles[j].username << "): " << posts[i].message << endl;
            }
        }
    }
    return true;
}

int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");
    
    nw.follow("mario", "luigi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    
    // write some posts
    nw.writePost("mario", "It's a-me, Mario!");
    nw.writePost("luigi", "Hey hey!");
    nw.writePost("mario", "Hi Luigi!");
    nw.writePost("yoshi", "Test 1");
    nw.writePost("yoshi", "Test 2");
    nw.writePost("luigi", "I just hope this crazy plan of yours works!");
    nw.writePost("mario", "My crazy plans always work!");
    nw.writePost("yoshi", "Test 3");
    nw.writePost("yoshi", "Test 4");
    nw.writePost("yoshi", "Test 5");
    
    cout << endl;
    cout << "======= Mario's timeline =======" << endl;
    nw.printTimeline("mario");
    cout << endl;
    
    cout << "======= Yoshi's timeline =======" << endl;
    nw.printTimeline("yoshi");
    cout << endl;
}
