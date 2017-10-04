#ifndef PLAYER_H
#define PLAYER_H

#include <Agent.h>


class Player : public Agent
{
    public:
        Player(string n, Room* room);
        bool act();
        virtual ~Player();

    protected:

    private:
};

#endif // PLAYER_H
