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
    Game(const std::uint32_t& iterations, const bool& verbosity);
    void setIterations(const std::uint32_t& iterations);
    void setVerbosity(const bool& verbosity);
    void start();
};
