#include "Monster.h"
#include <cassert>

Monster::Monster(
    std::string name,
    int health,
    int attack,
    int defense,
    Move *move1,
    Move *move2,
    Move *move3,
    Move *move4)
: name(name), health(health), maxHealth(maxHealth), attack(attack), defense(defense), accuracy(1.0f)
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

int Monster::getAttack() const
{
    return attack;
}

int Monster::getDefense() const
{
    return defense;
}

void Monster::takeDamage(Monster *attacker, int damage)
{
    health -= damage + attacker->getAttack();

    if (health <= 0)
    {
        // Do something!
    }
}

void Monster::setAccuracy(float accuracy)
{
    assert(accuracy >= 0 && accuracy <= 1);
    this->accuracy = accuracy;
}