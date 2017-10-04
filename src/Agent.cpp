#include "Agent.h"
#include "stdio.h"

string Agent::getName(){
return this->name;
}
bool Agent::emptyRoom(){
if(this->curr_Room==NULL){
return true; }
else{
    cout<<this->name<<" is in "<<this->curr_Room->getname()<<endl;
    this->curr_Room = NULL;
}
if(this->curr_Room != NULL){
    return false ;
}
}
void Agent::setCurrRoom(Room* r){
this->curr_Room = r ;
}
Room* Agent::getCurrRoom(){
return this->curr_Room;
}
Agent::~Agent()
{
    //dtor
}
