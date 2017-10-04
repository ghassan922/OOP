#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED


#include<iostream>


using namespace std;

class Agent;
class Room
{
private:
    //n name . d descreption . d2 direction
    string n ;
    string  d;
    string d2;
    int currSize;
    int maxSize;
    Agent** occupants;


public :
    //Ass2 update
     void enter(Agent* a);
     void leave(Agent* a);
     void printOccupants();


     Room *linked;
    string *direction ;
 const static int w = 6;
    int i=0;
    void setname(string nn);
    string getname ();
    void setdire(string dd2);
    string getdire();
    void setdesp(string dd);
    string getdesp();
    void setcurrSize(int n);
    int getcurrSize();
    void setmaxSize(int n);
    int getmaxSize();
    Room();
    // NORTH , SOUTH , EAST , WEST , middle
    Room( string name , string descreption, int n);

    void allocate();

    void link (Room *r , string directionn );
    Room *getlinked(string direc);

    void print();

};


#endif // ROOM_H_INCLUDED
