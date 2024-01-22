#pragma once

#include <iostream>
#include <vector>

#include "Roulette.h"
#include "Player.h"

class Game
{
private:
    Player players[6];
    std::int32_t gameIterations;

public:
    Game();
    void start();
};
