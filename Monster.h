#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

#include <string>

class Move;

class Monster
{
public:
    Monster(
        std::string name,
        int health,

        Move *move1,
        Move *move2,
        Move *move3,
        Move *move4);

    std::string getName() const;
    int getHealth() const;
    int getMaxHealth() const;

    Move *getMove(int i) const;

private:
    std::string name;
    int health;
    int maxHealth;

    Move *moves[4];
};

#endif