#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

#include <string>

class Move;
class Monster;

class MonsterDelegate
{
public:
    virtual ~MonsterDelegate() {}

    virtual void monsterDamaged(Monster *monster, int damage) = 0;
    virtual void monsterAttackChanged(Monster *monster, int diff) = 0;
    virtual void monsterDefenseChanged(Monster *monster, int diff) = 0;
    virtual void monsterAccuracyChanged(Monster *monster, float diff) = 0;
    virtual void monsterDead(Monster *monster) = 0;
};

class Monster
{
public:
    Monster(
        std::string name,
        int health,
        int attack,
        int defense,
        Move *move1,
        Move *move2,
        Move *move3,
        Move *move4);
    ~Monster();

    std::string getName() const;
    int getHealth() const;
    int getMaxHealth() const;
    Move *getMove(int i) const;
    int getAttack() const;
    int getDefense() const;
    float getAccuracy() const;

    void takeDamage(Monster *attacker, int damage);
    void setAttack(int newAttack);
    void setDefense(int newDefense);
    void setAccuracy(float newAccuracy);
    void setDelegate(MonsterDelegate *delegate);

private:
    std::string name;
    int health;
    int maxHealth;
    int attack;
    int defense;
    float accuracy;
    Move *moves[4];
    MonsterDelegate *delegate;
};

#endif