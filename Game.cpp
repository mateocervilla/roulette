#include "Game.h"
#include "Roulette.h"
#include "Player.h"

Game::Game()
{

}

void Game::start()
{
    // players[0].setBetType([](const int16_t& value){return value != 0 && value % 2 == 0;});
    players[0].setBetType(Roulette::isEven);
    players[1].setBetType(Roulette::isOdd);
    players[2].setBetType(Roulette::isRed);
    players[3].setBetType(Roulette::isBlack);
    players[4].setBetType(Roulette::isMinor);
    players[5].setBetType(Roulette::isMayor);

    for(int i = 0; i < 10000; i++) {
        int16_t result = Roulette::play();

        std::cout << "Winning number: " << result
                  << " - colour: " << Roulette::colour_names[Roulette::colours[result]]
                  << std::endl;

        int j = 1;
        for( auto& player : players ) {
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

    std::cout << "Total balances: " << players[0].getBalance() + players[1].getBalance() + players[2].getBalance() +
        players[3].getBalance() + players[4].getBalance() + players[5].getBalance() << std::endl;


    std::cout << "Max Bets:" << std::endl;
    for( auto& player : players ) {
        std::cout << player.getMaxBet() << std::endl;
    }

}