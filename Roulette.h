#pragma once

#include <iostream>

class Roulette
{
private:

    enum colours {
        ZERO, RED, BLACK
    };

    static constexpr std::uint8_t numberColours[37]{
        ZERO, RED, BLACK, RED, BLACK, RED, BLACK, RED, BLACK, RED, BLACK,
        BLACK, RED, BLACK, RED, BLACK, RED, BLACK, RED, RED, BLACK, RED,
        BLACK, RED, BLACK, RED, BLACK, RED, BLACK, BLACK, RED, BLACK, RED,
        BLACK, RED, BLACK, RED
    };

    const std::string colourNames[3]{
        "None", "Red", "Black"
    };

public:

    std::int16_t play() const;

    const std::string& getColourByNumber(std::uint8_t value) const;

    static bool isLow(std::int16_t value);
    static bool isHigh(std::int16_t value);
    static bool isRed(std::int16_t value);
    static bool isBlack(std::int16_t value);
    static bool isEven(std::int16_t value);
    static bool isOdd(std::int16_t value);
};
