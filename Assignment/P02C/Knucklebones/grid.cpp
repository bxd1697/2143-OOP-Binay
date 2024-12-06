
#include "grid.hpp"

Grid::Grid() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            grid[i][j] = 0;
        }
    }
}

bool Grid::addDice(int col, int value) {
    for (int row = 2; row >= 0; --row) {
        if (grid[row][col] == 0) {
            grid[row][col] = value;
            return true;
        }
    }
    return false;
}

void Grid::removeMatchingDice(int col, int value) {
    for (int row = 0; row < 3; ++row) {
        if (grid[row][col] == value) {
            grid[row][col] = 0;
            break;
        }
    }
}

int Grid::calculateScore() const {
    int score = 0;
    for (int col = 0; col < 3; ++col) {
        int multiplier = 1;
        for (int row = 0; row < 3; ++row) {
            if (grid[row][col] > 0) {
                multiplier *= grid[row][col];
            }
        }
        score += multiplier;
    }
    return score;
}

bool Grid::isFull() const {
    for (int col = 0; col < 3; ++col) {
        if (grid[0][col] == 0) {
            return false;
        }
    }
    return true;
}

void Grid::draw(int startY, int startX) const {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            int value = grid[row][col];
            if (value > 0) {
                mvprintw(startY + row, startX + col * 4, "%d", value);
            } else {
                mvprintw(startY + row, startX + col * 4, ".");
            }
        }
    }
}
