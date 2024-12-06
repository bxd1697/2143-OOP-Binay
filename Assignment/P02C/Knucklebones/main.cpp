
#include <iostream>
#include <ncurses.h>
#include "game.hpp"

int main() {
    initscr();
    start_color();
    noecho();
    cbreak();
    curs_set(0);

    // Start the Knucklebones game
    Game game;
    game.start();

    endwin();
    return 0;
}
