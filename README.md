# Roulette Simulator
[Roulette](https://en.wikipedia.org/wiki/Roulette) is a casino game where a player may choose to place a bet on a single number, various groupings of numbers, the color red or black, whether the number is odd or even, or if the numbers are high (19–36) or low (1–18).

Here we simulate a game played by 6 players betting the simple bets (evens, odds, reds, blacks, lows, highs) and following a particular rule for the amount of the bet.

## Table of contents
* [Bet rules](#bet-rules)
* [Technologies](#technologies)
* [Setup](#setup)
* [Args and example](#args-and-example)

## Bet rules

- Minimum bet: `5`.

- Maximum bet: `4.000`.

Each player has a little piece of paper where they write down their bets. When they start, their notebook says:

`1 - 2 - 3 - 4`

To bet, add the numbers at both ends and place a bet (in this case, bet 1 + 4 = 5). If he wins, he writes down what he won at the end of the list (5), while if he loses, cross out the two numbers at both ends (1 and 4). For the next bet, bets again the sum of both ends. Note that what is written down is the profit, not what the bank pays him (his bet plus the profit are included). So:

If he won, he would have: `1 - 2 - 3 - 4 - 5` (the next bet would be 1 + 5 = 6).

If he lost, he would have: `2 - 3` (the next bet would be 2 + 3 = 5).

In the following cases he has to start again and write down 1 - 2 - 3 - 4:
- He runs out of numbers on the list.
- He exceeds the table maximum (the sum is more than 4.000).
- He is left with a number below the minimum (5).

If he ends up with a single number, that is his bet (as long as it does not exceed the maximum allowed).

The `0` (zero) is a special number (is neither even, odd, red, black, low nor high). That means, if zero comes out, with this bets, everyone loses.

## Technologies
Project is created with:
* C++
* Make
* CMake
	
## Setup
To run this project, just build and run:

```
$ git clone https://github.com/mateocervilla/roulette.git
$ cd roulette
$ cmake . && make
$ ./roulette
```
	
## Args and example
The program accepts the following command line arguments:

* `-i <number>` : Number of iterations (10.000 by default)
* `-v` : Verbose mode

```
$ ./roulette -i 50000 -v
```