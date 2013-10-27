#include "Battle.h"
#include "Monster.h"
#include "Move.h"
#include <cassert>

Battle::Battle(Monster *player, Monster *opponent)
: player(player), opponent(opponent), delegate(NULL)
{
    assert(player);
    assert(opponent);
}

Monster *Battle::getPlayer() const
{
    return player;
}

Monster *Battle::getOpponent() const
{
    return opponent;
}

void Battle::start(Turn firstTurn)
{
    currentTurn = firstTurn;
    if (currentTurn == kTurnPlayer)
    {
        delegate->turnStarted(player);
    }
    else 
    {
        delegate->turnStarted(opponent);
    }
}

bool Battle::useMove(int i)
{
    Monster *attacker = NULL;
    Monster *target = NULL;
    if (currentTurn == kTurnPlayer)
    {
        attacker = player;
        target = opponent;
    }
    else 
    {
        attacker = opponent;
        target = player;
    }

    Move *move = attacker->getMove(i);

    if (move == NULL) 
    {
        return false;
    }
    else
    {
        if (move->use(attacker, target))
        {
            delegate->turnEnded(attacker, move);
            return true;
        }
        else 
        {
            return false;
        }
    }
}

void Battle::step()
{
    if (currentTurn == kTurnPlayer)
    {
        currentTurn = kTurnOpponent;
        delegate->turnStarted(opponent);
    }
    else 
    {
        currentTurn = kTurnPlayer;
        delegate->turnStarted(player);
    }
}

void Battle::setDelegate(BattleDelegate *delegate)
{
    this->delegate = delegate;
}
