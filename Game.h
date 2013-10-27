#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Battle.h"
#include "Monster.h"

class Game : public BattleDelegate, public MonsterDelegate
{
public:
    Game(Monster *player, Monster *opponent);
    ~Game();

    void run();

    void turnStarted(Monster *monster);
    void turnEnded(Monster *monster, Move *moveUsed);

    void monsterDamaged(Monster *monster, int damage);
    void monsterAttackChanged(Monster *monster, int diff);
    void monsterDefenseChanged(Monster *monster, int diff);
    void monsterAccuracyChanged(Monster *monster, float diff);
    void monsterDead(Monster *monster);

private:
    Monster *player;
    Monster *opponent;
    Battle *battle;
    bool isGameOver;

    void printPlayer();
    void printOpponent();
};

#endif