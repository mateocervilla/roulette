#pragma once

#include <iostream>

#include "Roulette.h"
#include "Player.h"

#define PLAYERS_NUMBER 6
#define DEFAULT_IT 10000

class Game
{
private:
    Player players[PLAYERS_NUMBER];
    std::uint32_t gameIterations;
    bool gameVerbosity;

    void initPlayers();

public:
    Game();
    Game(std::uint32_t iterations, bool verbosity);
    void setIterations(std::uint32_t iterations);
    void setVerbosity(bool verbosity);
    void start();
};
