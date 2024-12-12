#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include <SFML/Audio.hpp>



class Game {
private:
    sf::RenderWindow& window;
    sf::RectangleShape rollButton;
    sf::Text rollButtonText;
    sf::Font font;
    sf::Text infoText; // For displaying game information
    Player player1, player2;
    bool player1Turn;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::SoundBuffer rollSoundBuffer;
    sf::Sound rollSound;

    std::vector<sf::Texture> animationFrames;
    std::vector<sf::Texture> diceFaces;
    sf::Sprite diceSprite;
    int diceValue;
    bool animationRunning;
    int frameIndex;
    sf::Clock animationClock;

    void handleInput();
    void updateGrid(Player& player, int column, int row);
    void drawGrid(const Player& player, int offsetX, int offsetY);
    void drawText(const std::string& text, int x, int y, sf::Color color);

public:
    Game(sf::RenderWindow& win);
    void rollDice();
    void run();
    void draw();
    bool isGameOver() const;
};

#endif
