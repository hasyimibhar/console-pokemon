#ifndef BATTLE_H_INCLUDED
#define BATTLE_H_INCLUDED

class Monster;
class Move;

enum Turn
{
    kTurnPlayer,
    kTurnOpponent
};

class BattleDelegate
{
public:
    virtual ~BattleDelegate() {}

    virtual void turnStarted(Monster *monster) = 0;
    virtual void turnEnded(Monster *monster, Move *moveUsed) = 0;
};

class Battle
{
public:
    Battle(Monster *player, Monster *opponent);

    Monster *getPlayer() const;
    Monster *getOpponent() const;

    void start(Turn firstTurn);
    bool useMove(int i);
    void step();
    void setDelegate(BattleDelegate *delegate);

private:
    Monster *player;
    Monster *opponent;
    Turn currentTurn;
    BattleDelegate *delegate;
};

#endif