#include <iostream>
#include <emscripten.h>
#include <cstdlib>
#include <ctime>

extern "C" {

// Choices array
const char* choices[] = {"Rock", "Paper", "Scissors"};

// Store choices for access in JavaScript
int lastPlayerChoice = -1;
int lastComputerChoice = -1;

// Generate computer's choice
EMSCRIPTEN_KEEPALIVE
int getComputerChoice() {
    lastComputerChoice = std::rand() % 3;
    return lastComputerChoice;
}

// Store the player's choice
EMSCRIPTEN_KEEPALIVE
void setPlayerChoice(int choice) {
    lastPlayerChoice = choice;
}

// Get the player's choice
EMSCRIPTEN_KEEPALIVE
int getPlayerChoice() {
    return lastPlayerChoice;
}

// Play the game and return the result
EMSCRIPTEN_KEEPALIVE
const char* playGame() {
    if (lastPlayerChoice == -1 || lastComputerChoice == -1) {
        return "Error: Choices not set!";
    }

    if (lastPlayerChoice == lastComputerChoice) {
        return "It's a tie!";
    }
    if ((lastPlayerChoice == 0 && lastComputerChoice == 2) ||
        (lastPlayerChoice == 1 && lastComputerChoice == 0) ||
        (lastPlayerChoice == 2 && lastComputerChoice == 1)) {
        return "You win!";
    }
    return "You lose!";
}

}

int main() {
    std::srand(std::time(0)); // Seed RNG
    return 0;
}
