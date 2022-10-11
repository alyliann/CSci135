/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: March 28, 2022
Assignment: Lab 9F

This program
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

class Particle {
public:
    Coord3D pos;
    Coord3D vel;
};

// dynamically allocate memory for a particle and initialize it
Particle* createParticle(double x, double y, double z,
                         double vx, double vy, double vz){
    Particle* p = new Particle;
    p->pos = {x,y,z};
    
    return p;
}

// set its velocity to (vx, vy, vz)
void setVelocity(Particle *p, double vx, double vy, double vz){
    
    p->vel = {vx,vy,vz};

}

// get its current position
Coord3D getPosition(Particle *p){
    
    Coord3D position = p->pos;
    
    return position;
}

// update particle's position after elapsed time dt
void move(Particle *p, double dt){
    
    p->pos.x += p->vel.x * dt;
    p->pos.y += p->vel.y * dt;
    p->pos.z += p->vel.z * dt;
    
}

// delete all memory allocated for the particle passed by pointer
void deleteParticle(Particle *p){
    delete p;
}

int main() {
    // make new particle
    Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
    double time = 0.0;
    double dt = 0.1;
    while(time < 3.0) {
        // update its velocity
        setVelocity(p, 10.0 * time, 0.3, 0.1);

        // move the particle
        move(p, dt);
        time += dt;

        // reporting its coordinates
        cout << "Time: " << time << " \t";
        cout << "Position: "
             << getPosition(p).x << ", "
             << getPosition(p).y << ", "
             << getPosition(p).z << endl;
    }
    // remove the particle, deallocating its memory
    deleteParticle(p);
}
