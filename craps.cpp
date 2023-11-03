/* Markus Susko
11/3/2023
Craps Program
Casino Game Simulation 
*/

#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

// Function prototypes
int dieRoll();
void printDiceRoll(int die1, int die2);
bool playCraps();

int main() {
    // Seed the random number generator with the current time
    //Generate random seed
    srand(time(nullptr));

    int totalRolls = 0;
    int wins = 0;
    int losses = 0;

    // Simulate multiple games of craps
    for (int i = 0; i < 10; i++) { // You can change the number of games
        totalRolls++;

        std::cout << "Game " << totalRolls << ":\n";
        bool result = playCraps();

        if (result) {
            std::cout << "You win!\n";
            wins++;
        } else {
            std::cout << "You lose.\n";
            losses++;
        }

        std::cout << "-----------------------------------\n";
    }

    std::cout << "Statistics after " << totalRolls << " games:\n";
    std::cout << "Wins: " << wins << "\n";
    std::cout << "Losses: " << losses << "\n";

    return 0;
}

// Function to roll a 6-sided die and return the result
int dieRoll() {
    return (std::rand() % 6) + 1;
}

// Function to print the values of two dice and their sum
void printDiceRoll(int die1, int die2) {
    std::cout << "Die 1: " << die1 << "\n";
    std::cout << "Die 2: " << die2 << "\n";
    std::cout << "Sum: " << die1 + die2 << "\n";
}

// Function to play a game of craps
bool playCraps() {
    int firstRoll = dieRoll() + dieRoll();
    printDiceRoll(firstRoll, 0);

    if (firstRoll == 7 || firstRoll == 11) {
        return true; // Natural, you win
    } else if (firstRoll == 2 || firstRoll == 3 || firstRoll == 12) {
        return false; // Craps, you lose
    } else {
        std::cout << "Point is " << firstRoll << "\n";
        while (true) {
            int nextRoll = dieRoll() + dieRoll();
            printDiceRoll(nextRoll, 0);
            if (nextRoll == firstRoll) {
                return true; // You rolled the point, you win
            } else if (nextRoll == 7) {
                return false; // You rolled a 7, you lose
            }
        }
    }
}