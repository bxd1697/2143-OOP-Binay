
# Knucklebones Game

Knucklebones is a two-player strategy game where each player takes turns rolling dice and placing them on a 3x3 grid to maximize their score. This digital implementation of the game is built using **C++** and **SFML** for rendering and interaction.

## Features
- **Two-Player Mode**: Players take turns rolling dice and placing them on their respective grids.
- **Dynamic Scoring**: Scores are calculated based on the dice placement, with multiplication bonuses for matching values in the same column.
- **Simple Interface**: A user-friendly graphical interface using SFML.

## How to Play
1. **Roll the Dice**: Each player can roll the dice using the "Roll Dice" button.
2. **Place the Dice**: The player places the dice in any column of their grid.
3. **Scoring**: Scores are updated dynamically based on the dice placement.
4. **Game Over**: The game ends when all cells in both grids are filled, and the player with the highest score wins.

## Installation

### Prerequisites
- **C++17** or higher
- **SFML Library** (graphics, window, system, and audio modules)

### Steps
1. Clone the repository:
   ```bash
   git clone <repository_url>
   cd Knucklebones
   ```
2. Install SFML:
   ```bash
   brew install sfml
   ```
3. Build the project:
   ```bash
   make
   ```
4. Run the game:
   ```bash
   ./Knucklebones
   ```

## Known Issues
1. **Infinite Dice Rolls**: Players can roll the dice multiple times without placing the dice on the grid.
2. **Background Image Issue**: The background image doesn't display properly due to potential file path or loading issues.
3. **Opponent Score Cancellation**: If a player places a dice value that matches their opponent's dice in the same grid position, the opponent’s score is not reduced or canceled as per the rules.

## How to Contribute
Feel free to fork this repository and submit pull requests to address the known issues or add new features.
