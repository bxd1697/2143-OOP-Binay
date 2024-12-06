
# Knucklebones Game

This is an enhanced terminal-based implementation of the Knucklebones game using `ncurses`. The game now includes a visually distinct grid, clearer dice displays, and improved gameplay feedback.

## Features
- **Visual Grid:** A proper 3x3 grid for both players is now displayed with separators.
- **Dynamic Dice Animation:** shows rolling dice kind of behavior like spinning random digit and generating random digit from 0-6.
- **Score Calculation:** Automatically updates and displays scores for both players.
- **Interactive Gameplay:** Players take turns rolling dice and placing them strategically.
- **Dice placement:** It asks to choose  a column(0-2) to place dice but places at the last row of the chosen column.  

## Gameplay Rules
1. **Objective:** The goal is to score more points than your opponent by placing dice in a 3x3 grid.
2. **Dice Placement:** Players take turns rolling dice and placing them in a column on their grid.
3. **Scoring Rules:**
   - Matching numbers in a column multiply their values.
   - Matching an opponent's dice in the same column removes the opponent's dice.
4. **End Game:** The game ends when all 9 spaces in both grids are filled. The player with the highest score wins.

## Installation

### Prerequisites
- Ensure you have the `ncurses` library installed:
  ```bash
  sudo apt-get install libncurses5-dev libncursesw5-dev
  ```

### Build Instructions
1. Clone or download the project files.
2. Compile the project using the following command:
   ```bash
   g++ -std=c++11 -o knucklebones main.cpp dice_class.cpp grid_class.cpp player_class.cpp game_class.cpp -lncurses
   ```

### Run the Game
```bash
./knucklebones
```

## Controls
- **Column Selection:** During your turn, press `1`, `2`, or `3` to place your dice in the desired column.
- **Game Progress:** The UI will display the active player's turn and their grid.

## Improvements in This Version
- Redesigned grid with visible row and column separators.
- Player grids are now more distinguishable.
- Real-time feedback for actions such as invalid column selections or full columns.

## Notes
This project is designed for educational purposes to demonstrate `ncurses` usage and C++ programming skills.

## Authors
- Developed using `ncurses` and C++ by OpenAI's Assistant.


## Areas for Improvement
While the current implementation works well, there are areas that can be enhanced further:

1. **Improved Dice Visuals**: Instead of displaying just numbers, add ASCII art or graphical representations of dice rolls.
2. **Dynamic Resizing**: Make the UI adapt to different terminal sizes.
3. **AI Opponent**: Add a single-player mode with an AI opponent to make the game more versatile.
4. **Save/Load Game**: Implement functionality to save the game state and reload it later.
5. **Sound Effects**: Use terminal-based audio or text effects to make the game more engaging.
6. **Enhanced Input Handling**: Handle invalid inputs more gracefully and provide more feedback to the player.

These additions would make the game more interactive, visually appealing, and user-friendly.

