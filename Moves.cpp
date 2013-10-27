#include "Moves.h"
#include "Monster.h"
#include <cstdlib>

///////////////////////////////////////////////////////

AttackMove::AttackMove(std::string name, int maxPp, int damage)
: Move(name, maxPp), damage(damage)
{
}

void AttackMove::_use(Monster *user, Monster *target)
{
    float chance = (float)rand() / (float)RAND_MAX;
    if (chance < user->getAccuracy()) 
    {
        target->takeDamage(user, damage);
    }
    else
    {
        // Missed!
        target->takeDamage(user, 0);
    }
}

///////////////////////////////////////////////////////

TackleMove::TackleMove()
: AttackMove("Tackle", 40, 6)
{
}

///////////////////////////////////////////////////////

PunchMove::PunchMove()
: AttackMove("Punch", 30, 10)
{
}

///////////////////////////////////////////////////////

SandAttackMove::SandAttackMove()
: Move("Sand Attack", 30)
{
}

void SandAttackMove::_use(Monster *user, Monster *target)
{
    target->setAccuracy(
        target->getAccuracy() * 0.75f);
}

///////////////////////////////////////////////////////

HowlMove::HowlMove()
: Move("Howl", 15)
{
}

void HowlMove::_use(Monster *user, Monster *target)
{
    user->setAttack(user->getAttack() + 2);
}

///////////////////////////////////////////////////////

GrowlMove::GrowlMove()
: Move("Growl", 20)
{
}

void GrowlMove::_use(Monster *user, Monster *target)
{
    target->setAttack(target->getAttack() - 2);
}

///////////////////////////////////////////////////////

HardenMove::HardenMove()
: Move("Harden", 25)
{
}

void HardenMove::_use(Monster *user, Monster *target)
{
    user->setDefense(user->getDefense() + 2);
}

///////////////////////////////////////////////////////

LeerMove::LeerMove()
: Move("Leer", 20)
{
}

void LeerMove::_use(Monster *user, Monster *target)
{
    target->setDefense(target->getDefense() - 2);
}
