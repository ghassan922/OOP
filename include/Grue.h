#ifndef GRUE_H
#define GRUE_H

#include <Agent.h>


class Grue : public Agent
{
    public:
        Grue(string n, Room* room);
        bool act();
        virtual ~Grue();

    protected:

    private:
};

#endif // GRUE_H
