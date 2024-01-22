#pragma once

#include <iostream>
#include <vector>

#define MAX_BET 4000
#define MIN_BET 5

class Player
{
private:

    std::vector<std::int16_t> bets;

    bool(*betType)(const std::int16_t&);

    std::string betName;
    std::int32_t balance;
    std::int16_t nextBet;
    std::int16_t lastBet;
    std::int16_t maxBet;

    void wonGame();
    void lostGame();
    void clearBets();
    void genNextBet();

public:

    Player();

    bool play(const std::int16_t& value);

    const std::string& getBetName() const;
    const std::int32_t& getBalance() const;
    const std::int16_t& getMaxBet() const;
    const std::int16_t& getLastBet() const;

    void setBetType(bool(*betType)(const std::int16_t&), const std::string& name);
};
