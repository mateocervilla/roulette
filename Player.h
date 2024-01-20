#pragma once

#include <iostream>
#include <vector>

#include "Roulette.h"

#define MAX_BET 4000

class Player
{
private:

    std::vector<std::int16_t> bets;

    bool(*betType)(const std::int16_t&);

    std::int32_t balance = 0;
    std::int16_t nextBet = 0;

    void wonGame();
    void lostGame();
    void clearBets();
    void genNextBet();

    std::int16_t maxBet = 0;

public:

    Player();
    Player(bool(*betType)(const std::int16_t&));

    bool play(const std::int16_t& value);

    const std::int32_t& getBalance() const;
    const std::int16_t& getMaxBet() const;
    const std::int16_t& getNextBet() const;

    void setBetType(bool(*betType)(const std::int16_t&));

};

