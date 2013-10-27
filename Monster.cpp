#include "Monster.h"
#include "Move.h"
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
: name(name), health(health), maxHealth(health), attack(attack), defense(defense), accuracy(1.0f), delegate(NULL)
{
    moves[0] = move1;
    moves[1] = move2;
    moves[2] = move3;
    moves[3] = move4;
}

Monster::~Monster()
{
    for (int i = 0; i < 4; i++) 
    {
        delete moves[i];
    }
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

float Monster::getAccuracy() const
{
    return accuracy;
}

void Monster::takeDamage(Monster *attacker, int damage)
{
    int totalDamage = 0;

    if (damage > 0)
    {
        totalDamage = damage + attacker->getAttack() - defense;
    }

    health -= totalDamage;
    delegate->monsterDamaged(this, totalDamage);

    if (health <= 0)
    {
        delegate->monsterDead(this);
    }
}

void Monster::setAttack(int newAttack)
{
    if (newAttack < 0)
    {
        newAttack = 0;
    }

    int diff = newAttack - attack;
    attack = newAttack;
    delegate->monsterAttackChanged(this, diff);
}

void Monster::setDefense(int newDefense)
{
    if (newDefense < 0)
    {
        newDefense = 0;
    }

    int diff = newDefense - defense;
    defense = newDefense;
    delegate->monsterDefenseChanged(this, diff);
}

void Monster::setAccuracy(float newAccuracy)
{
    assert(accuracy >= 0 && accuracy <= 1);

    float diff = newAccuracy - accuracy;
    accuracy = newAccuracy;
    delegate->monsterAccuracyChanged(this, diff);
}

void Monster::setDelegate(MonsterDelegate *delegate)
{
    this->delegate = delegate;
}