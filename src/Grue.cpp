#include "Grue.h"
#include <cstdlib>

Grue::Grue(string n , Room* room)
{
   this->name =n ;
   this->curr_Room = room ;
}

bool Grue::act()
{
    int n = rand() % 4;
    string direction;
switch(n) {
    case 0: direction = "north"; break;
    case 1: direction = "south"; break;
    case 2: direction = "west"; break;
    case 3: direction = "east"; break;
 }
if(this->curr_Room->getlinked(direction) != NULL) {
   this->curr_Room = this->curr_Room->getlinked(direction);
}
cout<<this->name<<" is in Room : "<<this->curr_Room->getname()<<endl;
return true;
}
Grue::~Grue()
{
    //dtor
}
