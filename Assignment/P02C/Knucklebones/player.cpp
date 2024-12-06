
#include "player.hpp"

Player::Player(std::string n) : name(n), score(0) {}

std::string Player::getName() const {
    return name;
}

int Player::getScore() const {
    return score;
}

void Player::updateScore(int newScore) {
    score = newScore;
}
