#include <iostream>
#include <vector>
#include <string>
#include <emscripten/bind.h>

using namespace emscripten;

class RPSGame
{
public:
    RPSGame() {} // Constructor

    // Returns available moves
    std::vector<std::string> getMoves()
    {
        return {"rock", "paper", "scissors"};
    }

    // Plays the game given a player move
    std::string play(std::string playerMove)
    {
        std::vector<std::string> moves = getMoves();
        std::string aiMove = moves[rand() % 3];

        if (playerMove == aiMove)
        {
            return "Tie! Both chose " + aiMove;
        }
        if ((playerMove == "rock" && aiMove == "scissors") ||
            (playerMove == "scissors" && aiMove == "paper") ||
            (playerMove == "paper" && aiMove == "rock"))
        {
            return "You win! " + playerMove + " beats " + aiMove;
        }
        return "You lose! " + aiMove + " beats " + playerMove;
    }
};

// Bindings
EMSCRIPTEN_BINDINGS(my_module) {
    emscripten::register_vector<std::string>("vector<string>");
    emscripten::class_<RPSGame>("RPSGame")
        .constructor<>()
        .function("getMoves", &RPSGame::getMoves)
        .function("play", &RPSGame::play);
}
