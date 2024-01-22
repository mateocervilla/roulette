#include "Roulette.h"

#define MAX_VAL 36
#define LOW_VAL 18

std::int16_t Roulette::play()
{
    int result = rand() % MAX_VAL;
    return result;
}

const std::string& Roulette::getNumberColour(std::uint8_t value) const
{
    return this->colourNames[Roulette::numberColours[value]];
}

// Types of roulette bets
bool Roulette::isLow(const std::int16_t& value)
{
    return (value > 0 && value <= LOW_VAL);
}

bool Roulette::isHigh(const std::int16_t& value)
{
    return (value > LOW_VAL && value <= MAX_VAL);
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
