#include "Game.h"
#include <cstdlib>
#include <ctime>
#include <iostream> // For debug messages

Game::Game(sf::RenderWindow& win) : window(win), player1(), player2(), player1Turn(true), animationRunning(false), frameIndex(0), diceValue(0) {
    srand(static_cast<unsigned>(time(0))); // Random seed
    font.loadFromFile("arial.ttf");
    backgroundTexture.loadFromFile("background.png");
    backgroundSprite.setTexture(backgroundTexture);


    infoText.setFont(font);
    infoText.setCharacterSize(20);
    rollButton.setSize(sf::Vector2f(100, 50)); 
    rollButton.setFillColor(sf::Color::Red);  
    rollButton.setPosition(300, 500);       

    rollButtonText.setFont(font);
    rollButtonText.setString("Roll Dice");
    rollButtonText.setCharacterSize(20);
    rollButtonText.setFillColor(sf::Color::Blue);
    rollButtonText.setPosition(300, 510); // Adjust for proper alignment inside the button


    if (!rollSoundBuffer.loadFromFile("diceroll.wav")) {
        std::cerr << "Error loading diceroll.wav" << std::endl;
        exit(1);
    }
    rollSound.setBuffer(rollSoundBuffer);  

    // Load rolling animation frames (001.png to 024.png)
    for (int i = 1; i <= 24; ++i) {
        sf::Texture texture;
        std::string filename = "images/frame_" + ((i < 10) ? "00" + std::to_string(i) : "0" + std::to_string(i)) + ".png";

        if (!texture.loadFromFile(filename)) {
            std::cerr << "Error loading " << filename << std::endl;
            exit(1);
        }
        animationFrames.push_back(texture);
    }

    // Load final dice faces (1.png to 6.png)
    for (int i = 1; i <= 6; ++i) {
        sf::Texture texture;
        std::string filename = "images/" + std::to_string(i) + ".png";

        if (!texture.loadFromFile(filename)) {
            std::cerr << "Error loading " << filename << std::endl;
            exit(1);
        }
        diceFaces.push_back(texture);
    }

    // Set up the dice sprite
    diceSprite.setPosition(250, 20);
    diceSprite.setScale(1.0f, 1.0f);
}

void Game::rollDice() {
    rollSound.play(); 
    animationRunning = true; // Start the animation
    frameIndex = 0;          // Reset the animation frame index
    animationClock.restart(); // Restart the animation timer

    while (animationRunning) {
        // Update animation frame every 50 ms
        if (animationClock.getElapsedTime().asMilliseconds() > 50) {
            if (frameIndex < animationFrames.size()) {
                // Display the next frame in the animation
                diceSprite.setTexture(animationFrames[frameIndex]);
                frameIndex++;
                animationClock.restart();
            } else {
                // Animation finished, select a random dice face
                std::mt19937 rng(static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count()));
                std::uniform_int_distribution<int> dist(0, 5);
                diceValue = dist(rng) + 1;
                diceSprite.setTexture(diceFaces[diceValue - 1]);
                animationRunning = false;
            }

            // Draw the updated animation
            window.clear();
            drawGrid(player1, 50, 200); 
            drawGrid(player2, 450, 200); 
            drawText(player1Turn ? "Turn:Player 1" : "Turn:Player 2", 60, 20, sf::Color::Green);
            drawText("Player 1 Score: " + std::to_string(player1.calculateScore()), 50, 550, sf::Color::White);
            drawText("Player 2 Score: " + std::to_string(player2.calculateScore()), 450, 550, sf::Color::White);
            window.draw(diceSprite); // Draw the dice sprite
            window.display();
        }
    }

    std::cout << "Dice Rolled: " << diceValue << std::endl; // Debug message
}



void Game::handleInput() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        // Check if the roll button was clicked
        if (rollButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            rollDice();
            return;
        }

        
        int offsetX = player1Turn ? 50 : 450;  // Current player's grid start
        int column = -1;
        int row = -1;

        
        if (mousePos.x >= offsetX && mousePos.x < offsetX + 3 * 70 &&
            mousePos.y >= 200 && mousePos.y < 200 + 3 * 70) {
            column = (mousePos.x - offsetX) / 70; 
            row = (mousePos.y - 200) / 70;       
            std::cout << "Mouse clicked at: " << mousePos.x << ", " << mousePos.y << std::endl;
            std::cout << "Column: " << column << ", Row: " << row << std::endl;
            updateGrid(player1Turn ? player1 : player2, column, row); 
            std::cout << "Invalid click location!" << std::endl;
        }

    }
}


void Game::updateGrid(Player& player, int column, int row) {
    if (diceValue == 0) {
        std::cout << "You need to roll the dice first!" << std::endl;
        
        std::cout << "Dice Value: " << diceValue << std::endl;
        return;
    }


    if (player.getGridValue(row, column) != 0) {
        std::cout << "This box is already occupied!" << std::endl;
        std::cout << "You need to roll the dice first!" << std::endl;
        return;
    }

    // Update the grid with the rolled dice value
    player.setGridValue(row, column, diceValue);
    std::cout << "Placed dice " << diceValue << " in column " << column + 1
              << ", row " << row + 1 << std::endl;

    // Reset dice value after placing
    diceValue = 0;

    // Switch turns
    player1Turn = !player1Turn;
}


void Game::draw() {
    // Draw grids for both players
    drawGrid(player1, 50, 200);  // Player 1 grid
    drawGrid(player2, 450, 200); // Player 2 grid

    // Draw the roll button
    window.draw(rollButton);
    window.draw(rollButtonText);

    // Draw the dice sprite
    window.draw(diceSprite);

    // Display turn and scores
    drawText(player1Turn ? "Turn:Player 1" : "Turn:Player 2", 50, 20, sf::Color::Yellow);
    drawText("Player 1 Score: " + std::to_string(player1.calculateScore()), 50, 550, sf::Color::Green);
    drawText("Player 2 Score: " + std::to_string(player2.calculateScore()), 450, 550, sf::Color::Green);

    // Draw dice value if rolled
    if (diceValue > 0) {
        drawText("Rolled: " + std::to_string(diceValue), 350, 600, sf::Color::White);
    }
}


void Game::drawGrid(const Player& player, int offsetX, int offsetY) {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            int value = player.getGridValue(row, col);

            // Draw grid cell
            sf::RectangleShape cell(sf::Vector2f(60, 60)); // Cell size
            cell.setPosition(offsetX + col * 70, offsetY + row * 70);
            cell.setFillColor(sf::Color::Blue);
            cell.setOutlineColor(sf::Color::White);
            cell.setOutlineThickness(2); // Outline for visibility
            window.draw(cell);

            // Draw dice value
            if (value != 0) {
                sf::Text text;
                text.setFont(font);
                text.setString(std::to_string(value));
                text.setCharacterSize(20);
                text.setFillColor(sf::Color::Black);
                text.setPosition(offsetX + col * 70 + 20, offsetY + row * 70 + 15);
                window.draw(text);
            }
        }
    }
}



void Game::drawText(const std::string& text, int x, int y, sf::Color color) {
    infoText.setString(text);
    infoText.setFillColor(color);
    infoText.setPosition(x, y);
    window.draw(infoText);
}



void Game::run() {
    handleInput();

    // Check for game over
    if (isGameOver()) {
        drawText("Game Over!", 300, 250, sf::Color::Red);
        if (player1.calculateScore() > player2.calculateScore()) {
            drawText("Player 1 Wins!", 300, 300, sf::Color::Yellow);
        } else if (player1.calculateScore() < player2.calculateScore()) {
            drawText("Player 2 Wins!", 300, 300, sf::Color::Yellow);
        } else {
            drawText("It's a Tie!", 300, 300, sf::Color::Yellow);
        }
        return; // Stop further input processing
    }

    // Display current game information
    drawText(player1Turn ? "Turn:Player 1" : "Turn:Player 2", 50, 20, sf::Color::Yellow);
    drawText("Player 1 Score: " + std::to_string(player1.calculateScore()), 50, 550, sf::Color::Green);
    drawText("Player 2 Score: " + std::to_string(player2.calculateScore()), 450, 550, sf::Color::Green);


    // Draw the dice sprite and its value
    window.draw(diceSprite);
    if (diceValue > 0) { // Show rolled dice value at the bottom
        drawText("Rolled: " + std::to_string(diceValue), 350, 600, sf::Color::White);
    }

    // Draw grids
    drawGrid(player1, 50, 200); // Player 1 grid
    drawGrid(player2, 450, 200); // Player 2 grid
}

bool Game::isGameOver() const {
    return player1.isGridFull() && player2.isGridFull();
}
