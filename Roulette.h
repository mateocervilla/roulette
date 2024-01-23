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

    std::int16_t play();

    const std::string& getColourByNumber(const std::uint8_t& value) const;

    static bool isLow(const std::int16_t& value);
    static bool isHigh(const std::int16_t& value);
    static bool isRed(const std::int16_t& value);
    static bool isBlack(const std::int16_t& value);
    static bool isEven(const std::int16_t& value);
    static bool isOdd(const std::int16_t& value);
};
