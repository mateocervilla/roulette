#include "Game.h"

#define DEFAULT_IT 10000


Game::Game(const std::uint32_t& iterations)
: gameIterations(iterations)
{
    initPlayers();
}

Game::Game()
: Game(DEFAULT_IT)
{
}

void Game::setIterations(const std::uint32_t& iterations)
{
    this->gameIterations = iterations;
}

void Game::setVerbosity(const std::uint8_t& verbosity)
{
    this->gameVerbosity = verbosity;
}

void Game::initPlayers() {
    // Set each bet type for each player

    // Lambda function example
    // this->players[0].setBetType([](const int16_t& value){return value != 0 && value % 2 == 0;});
    this->players[0].setBetType(Roulette::isEven);
    this->players[0].setBetName("Evens");
    this->players[1].setBetType(Roulette::isOdd);
    this->players[1].setBetName("Odds");
    this->players[2].setBetType(Roulette::isRed);
    this->players[2].setBetName("Reds");
    this->players[3].setBetType(Roulette::isBlack);
    this->players[3].setBetName("Blacks");
    this->players[4].setBetType(Roulette::isMinor);
    this->players[4].setBetName("Minors");
    this->players[5].setBetType(Roulette::isMayor);
    this->players[5].setBetName("Mayors");
}

void Game::start()
{
    for(int i = 0; i < this->gameIterations; i++) {
        int16_t result = Roulette::play();

        if (gameVerbosity) 
            std::cout << "Winning number: " << result
                  << " - colour: " << Roulette::colourNames[Roulette::numberColours[result]]
                  << std::endl;

        int j = 1;
        for( auto& player : this->players ) {
            bool playerWon = false;
            if(player.play(result))
                playerWon = true;

            if (gameVerbosity) 
                std::cout << "Player " << j << " bets " << player.getLastBet() << " to " << player.getBetName()
                << " and " << (playerWon ? "WON" : "LOST") << ", Current balance: " << player.getBalance() << std::endl;

            j++;
        }
        if (gameVerbosity) std::cout << std::endl;
    }


    std::cout << "Final balances:" << std::endl;
    for(int i = 0; i < 6; i++) {
        std::cout << "Player " << i << " balance: " << this->players[i].getBalance() << std::endl;
    }
}
