#include "Game.h"

Game::Game(std::uint32_t iterations, bool verbosity = 0)
: gameIterations(iterations)
, gameVerbosity(verbosity)
{
    initPlayers();
}

Game::Game()
: Game(DEFAULT_IT)
{
}

void Game::initPlayers() {
    // Set each bet type for each player

    // Lambda function example
    // this->players[0].setBetType([](const int16_t& value){return value != 0 && value % 2 == 0;}, "Evens");
    this->players[0].setBetType(Roulette::isRed, "Reds");
    this->players[1].setBetType(Roulette::isBlack, "Blacks");
    this->players[2].setBetType(Roulette::isHigh, "Highs");
    this->players[3].setBetType(Roulette::isLow, "Lows");
    this->players[4].setBetType(Roulette::isEven, "Evens");
    this->players[5].setBetType(Roulette::isOdd, "Odds");
}

void Game::setIterations(std::uint32_t iterations)
{
    if (iterations == 0) {
        std::cout << "Warning: 0 is invalid for iterations, using " << DEFAULT_IT << " instead" << std::endl;
        this->gameIterations = DEFAULT_IT;
    }
    else {
        this->gameIterations = iterations;
    }
}

void Game::setVerbosity(bool verbosity)
{
    this->gameVerbosity = verbosity;
}

void Game::start()
{
    const Roulette roulette;

    for(int i = 0; i < this->gameIterations; i++) {
        // Play the roulette and get a number
        int16_t result = roulette.play();

        if (gameVerbosity) std::cout << "Winning number: " << result << " - colour: " 
                << roulette.getColourByNumber(result) << std::endl;

        int j = 0;
        for( auto& player : this->players ) {
            bool playerWon = false;
            
            // Player checks if he won
            playerWon = player.play(result);

            if (gameVerbosity) 
                std::cout << "Player " << (char)(j + 'A') << " bets " << player.getLastBet() << " to " << player.getBetName()
                << " and " << (playerWon ? "WON" : "LOST") << ", Current balance: " << player.getBalance() << std::endl;

            j++;
        }
        if (gameVerbosity) std::cout << std::endl;
    }

    std::cout << "Final balances:" << std::endl;
    int32_t totalBalance = 0;
    for(int i = 0; i < PLAYERS_NUMBER; i++) {
        int32_t balance = this->players[i].getBalance();
        std::cout << "Player " << (char)(i + 'A') << " balance: " << balance << std::endl;
        totalBalance += balance;
    }

    std::cout << std::endl;
    std::cout << "Total balance: " << totalBalance << std::endl;
}
