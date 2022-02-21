#include "Game.hpp"

class Game;

int main(void)
{
    Billy::Game *GameAnimation = new Billy::Game();

    GameAnimation->Run();

    return EXIT_SUCCESS;
}
