
#pragma once
#include <ncurses.h>

class Grid {
private:
    int grid[3][3];

public:
    Grid();
    bool addDice(int col, int value);
    void removeMatchingDice(int col, int value);
    int calculateScore() const;
    bool isFull() const;
    void draw(int startY, int startX) const;
};
