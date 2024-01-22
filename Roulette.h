#pragma once

#include <iostream>

namespace Roulette
{
    enum colours {
        ZERO, RED, BLACK
    };
    
    static constexpr std::int8_t numberColours[37]{
        ZERO, RED, BLACK, RED, BLACK, RED, BLACK, RED, BLACK, RED, BLACK,
        BLACK, RED, BLACK, RED, BLACK, RED, BLACK, RED, RED, BLACK, RED,
        BLACK, RED, BLACK, RED, BLACK, RED, BLACK, BLACK, RED, BLACK, RED,
        BLACK, RED, BLACK, RED
    };

    static std::string colourNames[3]{
        "None", "Red", "Black"
    };

    std::int16_t play();

    bool isMinor(const std::int16_t& value);
    bool isMayor(const std::int16_t& value);
    bool isRed(const std::int16_t& value);
    bool isBlack(const std::int16_t& value);
    bool isEven(const std::int16_t& value);
    bool isOdd(const std::int16_t& value);
};
