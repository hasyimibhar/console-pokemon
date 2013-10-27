#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED

#include <string>

class Monster;

class Move
{
public:
    Move(std::string name, int maxPp);
    virtual ~Move() {}

    std::string getName() const;
    int getPp() const;
    int getMaxPp() const;

    bool use(Monster *user, Monster *target);

protected:
    std::string name;
    int pp;
    int maxPp;

    virtual void _use(Monster *user, Monster *target) = 0;
};

#endif