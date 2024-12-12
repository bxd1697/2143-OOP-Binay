//#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Knucklebones Game");
    Game game(window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::R) {
                    game.rollDice(); // Trigger dice rolling
                }
            }
        }



        window.clear();   // Clear the window
        game.run();       // Update game state
        game.draw();      // Render game elements
        window.display(); // Display updated frame
    }

    return 0;
}
