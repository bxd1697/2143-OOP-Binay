
#pragma once
#include <string>

class Player {
private:
    std::string name;
    int score;

public:
    Player(std::string n);
    std::string getName() const;
    int getScore() const;
    void updateScore(int newScore);
};
