#pragma once

#include <iostream>
#include <vector>

#include "Roulette.h"
#include "Player.h"

class Game
{
private:
    Player players[6];
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
