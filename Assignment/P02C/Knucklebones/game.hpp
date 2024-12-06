
#pragma once
#include "player.hpp"
#include "grid.hpp"
#include "dice.hpp"

class Game {
private:
    Player players[2];
    Grid grids[2];
    Dice dice;
    int currentPlayerIndex;

    void displayUI();
    void switchPlayer();

public:
    Game();
    void start();
};
