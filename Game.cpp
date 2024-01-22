#include "Game.h"

Game::Game()
{
    this->gameIterations = 10000;
    
    // Set each bet type for each player
    // this->players[0].setBetType([](const int16_t& value){return value != 0 && value % 2 == 0;});
    this->players[0].setBetType(Roulette::isEven);
    this->players[1].setBetType(Roulette::isOdd);
    this->players[2].setBetType(Roulette::isRed);
    this->players[3].setBetType(Roulette::isBlack);
    this->players[4].setBetType(Roulette::isMinor);
    this->players[5].setBetType(Roulette::isMayor);
}

void Game::start()
{
    for(int i = 0; i < this->gameIterations; i++) {
        int16_t result = Roulette::play();

        std::cout << "Winning number: " << result
                  << " - colour: " << Roulette::colourNames[Roulette::numberColours[result]]
                  << std::endl;

        int j = 1;
        for( auto& player : this->players ) {
            std::cout << "Player " << j << " bets " << player.getNextBet() << " and ";
            if(player.play(result))
                std::cout << "WON";
            else
                std::cout << "LOST";
            j++;
            std::cout << ", Current balance: " << player.getBalance() << std::endl;
        }
        std::cout << std::endl;
    }

    std::cout << "Total balances: " << this->players[0].getBalance() + this->players[1].getBalance() + this->players[2].getBalance() +
        this->players[3].getBalance() + this->players[4].getBalance() + this->players[5].getBalance() << std::endl;


    std::cout << "Max Bets:" << std::endl;
    for( auto& player : this->players ) {
        std::cout << player.getMaxBet() << std::endl;
    }
}