#include <cstdio>
#include <cstdlib>
#include "Game.h"
#include "Monsters.h"

int main(int argc, char **argv)
{
    srand(time(0));
    
    Game game (
        new Squirtle(),
        new Charmander());
    game.run();

    return EXIT_SUCCESS;
}