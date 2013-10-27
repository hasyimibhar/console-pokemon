#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

#include <string>

class Move;

class Monster
{
public:
    Monster(
        std::string name,
        Move *move1,
        Move *move2,
        Move *move3,
        Move *move4);

    std::string getName() const;
    int getHealth() const;
};

#endif