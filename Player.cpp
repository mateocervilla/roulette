#include "Player.h"

Player::Player()
: balance(0)
, nextBet(0)
, lastBet(0)
{
    // Initial bet list
    this->clearBets();
    // Generate next bet
    this->genNextBet();
}

void Player::wonGame()
{
    // Increase balance 
    this->balance += this->nextBet;

    // Add bet to the end of the list
    this->bets.push_back(this->nextBet);
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

    if (betsSize < 3 || (betsSize == 3 && this->bets.at(1) < MIN_BET)) {
        this->clearBets();
    }
    else {
        // Erase first and last bets
        this->bets.erase(this->bets.begin());
        this->bets.pop_back();
    }
}

bool Player::play(const std::int16_t& value)
{
    bool playerWon = this->betType(value);

    if (playerWon) {
        this->wonGame();
    }
    else {
        this->lostGame();
    }

    // Generate next bet
    this->genNextBet();

    return playerWon;
}

const std::string& Player::getBetName() const
{
    return this->betName;
}

const std::int32_t& Player::getBalance() const
{
    return this->balance;
}

const std::int16_t& Player::getLastBet() const
{
    return this->lastBet;
}

void Player::clearBets()
{
    this->bets.clear();
    this->bets = {1,2,3,4};
}

void Player::setBetType(bool(*betType)(const std::int16_t&), const std::string& name)
{
    this->betType = betType;
    this->betName = name;
}

void Player::genNextBet()
{
    this->lastBet = this->nextBet;
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
