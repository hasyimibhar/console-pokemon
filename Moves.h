#ifndef MOVES_H_INCLUDED
#define MOVES_H_INCLUDED

#include "Move.h"

///////////////////////////////////////////////////////
// Class for any moves that simply inflicts damage
class AttackMove : public Move
{
public:
    AttackMove(std::string name, int maxPp, int damage);

protected:
    void _use(Monster *user, Monster *target);

private:
    int damage;
};

///////////////////////////////////////////////////////

class TackleMove : public AttackMove
{
public:
    TackleMove();
};

///////////////////////////////////////////////////////

class PunchMove : public AttackMove
{
public:
    PunchMove();
};

///////////////////////////////////////////////////////

class SandAttackMove : public Move
{
public:
    SandAttackMove();

protected:
    void _use(Monster *user, Monster *target);
};

///////////////////////////////////////////////////////

class HowlMove : public Move
{
public:
    HowlMove();

protected:
    void _use(Monster *user, Monster *target);
};

///////////////////////////////////////////////////////

class GrowlMove : public Move
{
public:
    GrowlMove();

protected:
    void _use(Monster *user, Monster *target);
};

///////////////////////////////////////////////////////

class HardenMove : public Move
{
public:
    HardenMove();

protected:
    void _use(Monster *user, Monster *target);
};

///////////////////////////////////////////////////////

class LeerMove : public Move
{
public:
    LeerMove();

protected:
    void _use(Monster *user, Monster *target);
};

#endif