#include "Monster.h"
#include <cassert>

Monster::Monster(
    std::string name,
    int health,
    Move *move1,
    Move *move2,
    Move *move3,
    Move *move4)
: name(name), health(health), maxHealth(maxHealth)
{
    moves[0] = move1;
    moves[1] = move2;
    moves[2] = move3;
    moves[3] = move4;
}

std::string Monster::getName() const
{
    return name;
}

int Monster::getHealth() const
{
    return health;
}

int Monster::getMaxHealth() const
{
    return maxHealth;
}

Move *Monster::getMove(int i) const 
{
    assert(i >= 0 && i < 4);
    return moves[i];
}