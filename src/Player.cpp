#include "Player.h"

Player::Player(string n,Room* room)
{
    this->name = n ;
    this->curr_Room = room;
}
bool Player::act()
{
    int n ;
    cout<<"you are in : "+this->curr_Room->getname()<<endl;
    cout<<"Choose a direction :"<<endl;
    cout<<"(0)North\n(1)South\n(2)West\n(3)East\n**********(4)Quit"<<endl;
    cin>>n;

    string direction;
switch(n) {
    case 0: direction = "north"; break;
    case 1: direction = "south"; break;
    case 2: direction = "west"; break;
    case 3: direction = "east"; break;
    case 4: direction = "quit";break;
 }
 if(direction == "quit")
    return false;
 else{
    this->curr_Room = this->curr_Room->getlinked(direction);
    cout<<this->name+" is in : "+this->curr_Room->getname()<<endl;
    return true;
    }
}
Player::~Player()
{
    //dtor
}
