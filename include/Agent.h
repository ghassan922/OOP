#ifndef AGENT_H
#define AGENT_H
#include "../Room.h"

using namespace std;

class Agent
{
    public:

        virtual bool act()=0;
        virtual ~Agent();
        string getName();
        bool emptyRoom();
        void setCurrRoom(Room* r);
        Room* getCurrRoom();

    protected:
        string name ;
        Room* curr_Room;

};

#endif // AGENT_H
