
#include "game.hpp"
#include <ncurses.h>
#include <iostream>

Game::Game() : players{Player("Player 1"), Player("Player 2")}, currentPlayerIndex(0) {}

void Game::switchPlayer() {
    currentPlayerIndex = (currentPlayerIndex + 1) % 2;
}

void Game::displayUI() {
    clear();
    mvprintw(0, 10, "Knucklebones Game");
    mvprintw(2, 2, "%s: %d", players[0].getName().c_str(), players[0].getScore());
    mvprintw(2, 40, "%s: %d", players[1].getName().c_str(), players[1].getScore());
    grids[0].draw(4, 2);
    grids[1].draw(4, 40);
    mvprintw(10, 2, "Press 'r' to roll, 'q' to quit.");
    refresh();
}

void Game::start() {
    while (true) {
        displayUI();
        mvprintw(1, 2, "%s's turn", players[currentPlayerIndex].getName().c_str());
        refresh();

        int ch = getch();
        if (ch == 'q') {
            break;
        } else if (ch == 'r') {
            int roll = dice.roll();
            mvprintw(12, 2, "Rolled: %d", roll);
            refresh();
            getch();

            mvprintw(13, 2, "Enter column (0-2): ");
            refresh();
            int col = getch() - '0';

            if (col >= 0 && col < 3 && grids[currentPlayerIndex].addDice(col, roll)) {
                // Check for removal in opponent's grid
                int opponentIndex = (currentPlayerIndex + 1) % 2;
                grids[opponentIndex].removeMatchingDice(col, roll);

                // Update score
                players[currentPlayerIndex].updateScore(grids[currentPlayerIndex].calculateScore());
                switchPlayer();
            } else {
                mvprintw(14, 2, "Invalid move. Try again.");
                refresh();
                getch();
            }

            if (grids[0].isFull() && grids[1].isFull()) {
                clear();
                mvprintw(0, 10, "Game Over!");
                mvprintw(2, 2, "%s: %d", players[0].getName().c_str(), players[0].getScore());
                mvprintw(3, 2, "%s: %d", players[1].getName().c_str(), players[1].getScore());

                if (players[0].getScore() > players[1].getScore()) {
                    mvprintw(5, 2, "Winner: %s", players[0].getName().c_str());
                } else {
                    mvprintw(5, 2, "Winner: %s", players[1].getName().c_str());
                }
                refresh();
                getch();
                break;
            }
        }
    }
}
