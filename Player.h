#pragma once

#include <iostream>
#include <vector>

#define MAX_BET 4000
#define MIN_BET 5

class Player
{
private:

    std::vector<std::int16_t> bets;

    bool(*betType)(std::int16_t);

    std::string betName;
    std::int32_t balance;
    std::int16_t nextBet;
    std::int16_t lastBet;

    void wonGame();
    void lostGame();
    void clearBets();
    void genNextBet();

public:

    Player();

    bool play(std::int16_t value);

    const std::string& getBetName() const;
    std::int32_t getBalance() const;
    std::int16_t getLastBet() const;

    void setBetType(bool(*betType)(std::int16_t), const std::string& name);
};
