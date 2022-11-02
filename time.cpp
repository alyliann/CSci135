/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: April 4, 2022
Assignment: Lab 10

This program uses class types and functions for various purposes.
*/

#include <iostream>
using namespace std;

class Time {
public:
    int h;
    int m;
};

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};
//Enum types work as sets of named values. A variable of type Genre can assume any of the values listed in the curly braces, example: Genre myFavorite = COMEDY;

class Movie {
public:
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

class TimeSlot {
public:
    Movie movie;     // what movie
    Time startTime;  // when it starts
};

void printTime(Time time) {
    cout << time.h << ":" << time.m;
}

//Task A:
int minutesSinceMidnight(Time time){
    int since;
    
    since = time.h * 60;                //converting hours to minutes
    since += time.m;
    
    return since;
}

int minutesUntil(Time earlier, Time later){
    
    int until = minutesSinceMidnight(later) - minutesSinceMidnight(earlier);
    
    return until;
}

//Task B:
Time addMinutes(Time time0, int min){
    
    Time newTime = {(minutesSinceMidnight(time0)+min)/60, (minutesSinceMidnight(time0)+min)%60};
    
    return newTime;
}

//Task C:
void printMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

void printTimeSlot(TimeSlot ts){
    //output ex: Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]
    printMovie(ts.movie);
    cout << " [starts at ";
    printTime(ts.startTime);
    cout << ", ends by ";
    Time endTime = addMinutes(ts.startTime, ts.movie.duration);
    printTime(endTime);
    cout << "]" << endl;
}

//Task D:
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    
    Time nextSlot = addMinutes(ts.startTime, ts.movie.duration);
    
    TimeSlot next = {nextMovie, nextSlot};
    
    return next;
}

//Task E:
bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
    
    Time end1 = addMinutes(ts1.startTime, ts1.movie.duration);
    Time end2 = addMinutes(ts2.startTime, ts2.movie.duration);
    
    if (minutesSinceMidnight(ts1.startTime) < minutesSinceMidnight(ts2.startTime)){
        if (end1.h < ts2.startTime.h || (end1.h == ts2.startTime.h && end1.m <= ts2.startTime.m)){
            return false;
        }
        else return true;
    }
    else {
        if (end2.h < ts1.startTime.h || (end2.h == ts1.startTime.h && end2.m <= ts1.startTime.m)){
            return false;
        }
        else return true;
    }
}

int main(){
    
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};
    Movie movie3 = {"Tinker Bell", ACTION, 78};
    Movie movie4 = {"The Count of Monte Cristo", DRAMA, 131};

    TimeSlot morning = {movie1, {9, 15}};
    TimeSlot daytime = {movie2, {12, 15}};
    TimeSlot evening = {movie2, {16, 45}};
    TimeSlot mine1 = {movie3, {13, 30}};
    TimeSlot mine2 = {movie4, {16, 10}};
    
    cout << timeOverlap({{"The Wolf of Wall Street", COMEDY, 180}, {10, 30}}, {{"5 Centimeters Per Second", DRAMA, 63}, {9, 10}}) << endl;
    
    return 0;
}
