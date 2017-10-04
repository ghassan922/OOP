#include<iostream>
#include "Room.h"
#include "Agent.h"
class Agent ;
using namespace std ;

    //Room ::int  i=0;
    void Room ::setname(string nn)
    {
        n=nn;
    }string Room ::getname ()
    {
        return n;
    }void Room ::setdire(string dd2)
    {
        d2=dd2;
    }string Room ::getdire()
    {
        return d2;
    }void Room ::setdesp(string dd)
    {
        d=dd;
    }
    string Room ::getdesp()
    {
        return d;
    }
    void Room::setcurrSize(int curr){

    this->currSize = curr ;
    }
    int Room::getcurrSize(){

    return this->currSize ;
    }
    void Room::setmaxSize(int n){

    this->maxSize = n ;
    }
    int Room::getmaxSize(){

    return this->maxSize ;
    }
   Room :: Room(){
       this-> n="";
        this->d="";
        this->d2="";
        this->currSize = 0;
        this->maxSize = 5 ;
        this->occupants = new Agent*[this->maxSize];


    }
    // NORTH , SOUTH , EAST , WEST , middle
    Room ::Room( string name , string descreption, int sizeMax)
    {
        this-> n=name;
        this->d=descreption;
        this->maxSize = sizeMax;
        this->currSize = 0 ;
        this->occupants = new Agent*[this->maxSize]();
    }
    void Room ::allocate()
    {
        linked = new Room[w];
        direction = new string [w];
    }
    void Room ::link (Room *r , string directionn )
    {

        linked[i]=*r;
        linked[i].setdire(directionn);
        direction[i]=directionn;
            i++;

    }
    Room* Room ::getlinked(string direc)
    {
        int index =0 , index2;

        while (index<w)
        {
            if (direc==linked[index].getdire()){index2=index;break;}

            else index ++ ;
        }

           return   &linked[index2];
    }
    void Room::print()
    {
       cout<< "#NEW position is "<<this->getname()<<endl;
       cout<< " #with direction : "<<this->getdire()<<endl;
       cout<<" #wih descreption : "<<this->getdesp()<<endl;
    }
    //////////////////////////////////////// ASS 2 Update
    void Room::enter(Agent* a){


        for(int i =0 ; i <this->maxSize ;i++){
            if(this->occupants[i]==0){
                a->setCurrRoom(this);
                this->occupants[i] = a ;
                this->currSize++;
                cout<<occupants[i]->getName()<<" is in "<<occupants[i]->getCurrRoom()->getname();
            }
            else{
                cout<<"SORRY .... Room is FULL .... :( "<<endl;
            }

        }

    }
    void Room::leave(Agent* a){
        string name ;
        for (int i = 0 ; i < this->maxSize; i ++){
            name = this->occupants[i]->getName();
            if (name == a->getName()){
                this->occupants[i] = 0 ;
                if(a->emptyRoom()){
                    cout<<"you left the room ... :)"<<endl;
                }
                else{
                    cout<<" !!!!! you are still in : "<<this->occupants[i]->getCurrRoom()->getname()<<endl;
                }
            }
            else{
                cout<<"Player is not in this room .... !! "<<endl;

            }
        }
    }
     void Room::printOccupants(){
         cout << "Occupants in this room:" << endl;
                for(int i=0; i<this->maxSize; i++){
            // use the Agent's getName() function
            cout <<"Occupants #"<<i+1<<" "<<this->occupants[i]->getName() << endl;
   }

     }

