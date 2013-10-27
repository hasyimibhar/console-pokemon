#include "Game.h"
#include "Move.h"
#include <iostream>
#include <cstdlib>

using namespace std;

const int HEALTHBAR_LENGTH = 20;

Game::Game(Monster *player, Monster *opponent)
: player(player), opponent(opponent), isGameOver(false)
{
    battle = new Battle(player, opponent);
    battle->setDelegate(this);

    player->setDelegate(this);
    opponent->setDelegate(this);
}

Game::~Game()
{
    delete battle;
    delete player;
    delete opponent;
}

void Game::run()
{
    battle->start(kTurnPlayer);
}

void Game::turnStarted(Monster *monster)
{
    int i;

    if (monster == player)
    {
        printOpponent();
        printPlayer();

        cout << "Which move?" << endl;
        cin >> i;
        i -= 1;
        while (
            player->getMove(i) == NULL ||
            player->getMove(i)->getPp() == 0) 
        {
            cout << "Can't use that one!" << endl;
            cin >> i;
            i -= 1;
        }
    }
    else if (monster == opponent)
    {
        i = rand() % 4;
        while (
            opponent->getMove(i) == NULL ||
            opponent->getMove(i)->getPp() == 0) 
        {
            i = rand() % 4;
        }
    }

    Move *move = monster->getMove(i);
    cout << monster->getName() << " used " << move->getName() << "!" << endl;
    battle->useMove(i);
}

void Game::turnEnded(Monster *monster, Move *moveUsed)
{
    if (!isGameOver)
    {
        battle->step();
    }
}

void Game::monsterDamaged(Monster *monster, int damage)
{
    if (damage > 0)
    {
        cout << monster->getName() << " took " << damage << " damage!" << endl;
    }
    else
    {
        cout << "It missed!" << endl;
    }
}

void Game::monsterAttackChanged(Monster *monster, int diff)
{
    if (diff > 0)
    {
        cout << monster->getName() << "'s attack rose by " << diff << "!" << endl;
    }
    else if (diff < 0)
    {
        cout << monster->getName() << "'s attack fell by " << -diff << "!" << endl;
    }
}

void Game::monsterDefenseChanged(Monster *monster, int diff)
{
    if (diff > 0)
    {
        cout << monster->getName() << "'s defense rose by " << diff << "!" << endl;
    }
    else if (diff < 0)
    {
        cout << monster->getName() << "'s defense fell by " << -diff << "!" << endl;
    }
}

void Game::monsterAccuracyChanged(Monster *monster, float diff)
{
    if (diff > 0)
    {
        cout << monster->getName() << "'s accuracy rose by " << diff * 100 << "%!" << endl;
    }
    else if (diff < 0)
    {
        cout << monster->getName() << "'s accuracy fell by " << -diff * 100 << "%!" << endl;
    }
}

void Game::monsterDead(Monster *monster)
{
    cout << monster->getName() << " is knocked out!" << endl;

    isGameOver = true;

    if (monster == player)
    {
        cout << opponent->getName() << " has won the battle!" << endl;
    }
    else 
    {
        cout << player->getName() << " has won the battle!" << endl;
    }
}

void Game::printPlayer()
{
    cout << endl;
    cout << player->getName() << endl;
    cout << "HP [";

    float healthPercentage = (float)player->getHealth() / (float)player->getMaxHealth();
    int healthbarLength = (int)(healthPercentage * (float)HEALTHBAR_LENGTH);

    int i = 0;
    for (;i < healthbarLength; i++)
    {
        cout << "=";
    }

    for (;i < HEALTHBAR_LENGTH; i++)
    {
        cout << " ";
    }

    cout << "]" << endl;
    cout << player->getHealth() << "/" << (float)player->getMaxHealth() << endl;

    cout << endl;
    cout << "Moves:" << endl;

    for (int i = 0; i < 4; i++)
    {
        Move *move = player->getMove(i);
        cout << i + 1 << ". ";

        if (move == NULL)
        {
            cout << "-" << endl;
        }
        else
        {
            cout << move->getName() << "\t\t" << move->getPp() << "/" << move->getMaxPp() << endl;
        }
    }
}

void Game::printOpponent()
{
    cout << endl;
    cout << "\t\t\t\t" << opponent->getName() << endl;
    cout << "\t\t\t\tHP [";

    float healthPercentage = (float)opponent->getHealth() / (float)opponent->getMaxHealth();
    int healthbarLength = (int)(healthPercentage * (float)HEALTHBAR_LENGTH);

    int i = 0;
    for (;i < healthbarLength; i++)
    {
        cout << "=";
    }

    for (;i < HEALTHBAR_LENGTH; i++)
    {
        cout << " ";
    }

    cout << "]" << endl;
    cout << "\t\t\t\t" << opponent->getHealth() << "/" << (float)opponent->getMaxHealth() << endl;
}