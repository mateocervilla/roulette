#include "Roulette.h"

#define MAX_VAL 36

std::int16_t Roulette::play()
{
    int result = rand() % MAX_VAL;
    return result;
}

// Types of roulette bets
bool Roulette::isMinor(const std::int16_t& value)
{
    return (value > 0 && value <= 18);
}

bool Roulette::isMayor(const std::int16_t& value)
{
    return (value > 18 && value <= 36);
}

bool Roulette::isRed(const std::int16_t& value)
{
    return Roulette::numberColours[value] == RED;
}

bool Roulette::isBlack(const std::int16_t& value)
{
    return Roulette::numberColours[value] == BLACK;
}

bool Roulette::isEven(const std::int16_t& value)
{
    return (value != 0 && value % 2 == 0);
}

bool Roulette::isOdd(const std::int16_t& value)
{
    return (value % 2 != 0);
}