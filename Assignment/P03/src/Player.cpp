#include <iostream>
#include "Player.h"
#include <cmath> // Include for std::pow

Player::Player() : grid(3, std::vector<int>(3, 0)) {}

int Player::placeDice(int column, int diceValue, Player& opponent) {
    if (column < 0 || column > 2) {
        std::cerr << "Invalid column." << std::endl;
        return -1;
    }

    // Place the die in the first available spot in the column (from bottom to top)
    for (int row = 2; row >= 0; --row) {
        if (grid[row][column] == 0) {
            grid[row][column] = diceValue;

            // Check the opponent's column for matching dice
            for (int oppRow = 0; oppRow < 3; ++oppRow) {
                if (opponent.getGridValue(oppRow, column) == diceValue) {
                    // Remove the matching die
                    opponent.setGridValue(oppRow, column, 0);
                    std::cout << "Removed opponent's dice of value " << diceValue
                              << " from row " << oppRow + 1 << ", column " << column + 1 << std::endl;
                }
            }

            return row; // Return the row where the die was placed
        }
    }

    // If the column is full, return an error
    std::cerr << "Column is full." << std::endl;
    return -1;
}

int Player::removeOpponentDice(int row, int column, int diceValue)
{
    return 0;
}

int Player::getGridValue(int row, int col) const {
    if (row < 0 || row >= 3 || col < 0 || col >= 3) return -1; 
    return grid[row][col];
}

void Player::setGridValue(int row, int col, int value) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3) {
        grid[row][col] = value;
    }
}


bool Player::isColumnFull(int column) const {
    return grid[0][column] != 0;
}

bool Player::isGridFull() const {
    for (int col = 0; col < 3; ++col) {
        if (!isColumnFull(col)) return false;
    }
    return true;
}


int Player::calculateScore() const {
    int score = 0;
    for (int col = 0; col < 3; ++col) {
        std::unordered_map<int, int> diceCount;
        for (int row = 0; row < 3; ++row) {
            int value = grid[row][col];
            if (value != 0) {
                diceCount[value]++;
            }
        }
        for (const auto& pair : diceCount) {
            score += std::pow(pair.first, pair.second); 
        }
    }
    return score;
}