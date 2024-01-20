#pragma once

#include <iostream>
#include <vector>

#include "Roulette.h"
#include "Player.h"

class Game
{
private:
    Player players[6];


public:
    Game();
    void start();
};

