#include "Player.h"

Player::Player()
{
    this->bets.reserve(4);
    // Initial bet list
    this->bets = {1,2,3,4};
    // Generate next bet
    this->genNextBet();
}

Player::Player(bool(*betType)(const std::int16_t&))
{
    this->betType = betType;
    Player();
}

void Player::wonGame()
{
    // Increase balance 
    this->balance += this->nextBet;

    // Save highest bet (just for data)
    this->maxBet = this->nextBet > this->maxBet ? this->nextBet : this->maxBet;

    // Add bet to the end of the list
    this->bets.push_back(this->nextBet);

    // Generate next bet
    this->genNextBet();
}

void Player::lostGame()
{
    // Decrease balance 
    this->balance -= this->nextBet;

    int betsSize = this->bets.size();

    // If there are only two bets left and lost, it must restart

    // Also, after losing, the only possibilities to have a bet less than five (minimum bet) are:
    // - Bet with two elements: 1 + 2 = 3  or 1 + 3 = 4: Not possible because after a first loss, the 1 is removed.
    // - Bet with one element: 3 or 4: Only possible after losing with 3 elements left. 
    //     Not possible with 1 or 2 because after a first loss, the 1 is removed.

    if (betsSize < 3 || (betsSize == 3 && this->bets.at(1) < 5)) {
        this->clearBets();
    }
    else {
        // Erase first and last bets
        this->bets.erase(this->bets.begin());
        this->bets.pop_back();
    }

    // Generate next bet
    this->genNextBet();
}

bool Player::play(const std::int16_t& value)
{
    if (this->betType(value)) {
        this->wonGame();
        return 1;
    }
    else {
        this->lostGame();
        return 0;
    }
}

const std::int32_t& Player::getBalance() const
{
    return this->balance;
}

const std::int16_t& Player::getMaxBet() const
{
    return this->maxBet;
}

const std::int16_t& Player::getNextBet() const
{
    return this->nextBet;
}

void Player::clearBets()
{
    this->bets.clear();
    this->bets = {1,2,3,4};
}

void Player::setBetType(bool(*betType)(const std::int16_t&))
{
    this->betType = betType;
}

void Player::genNextBet()
{
    // If there is only one element left, that's the bet
    if (this->bets.size() == 1) {
        this->nextBet = this->bets.front();
    }
    else {
        // Sum the first and the last elements
        this->nextBet = this->bets.front() + this->bets.back();
        // If the sum is higher than the maximum bet, it must restart
        if(this->nextBet > MAX_BET) {
            this->clearBets();
            this->nextBet = this->bets.front() + this->bets.back();
        }
    }
}