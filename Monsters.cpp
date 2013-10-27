#include "Monsters.h"
#include "Moves.h"

Charmander::Charmander()
: Monster(
    "CHARMANDER",
    25,
    4,
    3,
    new PunchMove(),
    new GrowlMove(),
    new HowlMove(),
    NULL)
{
}

Squirtle::Squirtle()
: Monster(
    "SQUIRTLE",
    22,
    3,
    5,
    new TackleMove(),
    new HardenMove(),
    new SandAttackMove(),
    new LeerMove())
{
}