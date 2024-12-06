
#include "dice.hpp"

Dice::Dice() {
    std::srand(std::time(nullptr));
}

int Dice::roll() {
    return std::rand() % 6 + 1;
}
