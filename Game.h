#pragma once

#include <iostream>
#include <vector>

#include "Roulette.h"
#include "Player.h"

#define PLAYERS_NUMBER 6

class Game
{
private:
    Player players[PLAYERS_NUMBER];
    std::uint32_t gameIterations;
    std::uint8_t gameVerbosity;

    void initPlayers();

public:
    Game();
    Game(const std::uint32_t& iterations);
    void setIterations(const std::uint32_t& iterations);
    void setVerbosity(const std::uint8_t& verbosity);
    void start();
};
