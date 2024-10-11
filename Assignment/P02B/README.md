
# Knucklebones Game Class Design

## 1. Dice Class:
- **Data**:
    - sides: Number of sides on the die (usually 6).
    - current_value: The value of the die after a roll.
- **Actions**:
    - roll(): Rolls the die and assigns a value to current_value.
    - get_value(): Returns the current value of the die.
- **Relationships**:
    - The Dice class will be used by the Player class (Composition: A player HAS-A set of dice).

## 2. Player Class:
- **Data**:
    - name: Player's name.
    - score: Player's current score.
    - grid: A 3x3 array representing the player's grid.
    - dice_set: An array of Dice objects the player can roll.
    - player_stats: Player's statistics (e.g., wins, losses).
- **Actions**:
    - roll_dice(): Rolls a die and places it on the grid.
    - place_die(column, die): Places a die in a specified column.
    - get_score(): Retrieves the player's current score.
    - update_score(): Updates the score based on the current grid and scoring rules.
- **Relationships**:
    - A Player HAS-A Dice set (Composition).
    - A Player IS-A participant in the game.

## 3. Board Class:
- **Data**:
    - grid: 3x3 grid where dice are placed.
    - dice: Dice present in each column of the grid.
- **Actions**:
    - place_die(column, die): Places a die in a column.
    - clear_die(column, die_value): Clears matching dice from the grid based on opponent's placement.
- **Relationships**:
    - The Board class will be used by the Game to manage the game state (Composition).

## 4. Game Class:
- **Data**:
    - players: A list of Player objects (2 players).
    - rules: General game rules.
    - current_round: Keeps track of the current round.
- **Actions**:
    - start_game(): Initializes the game and prepares for play.
    - end_game(): Ends the game when all grids are filled.
    - get_winner(): Calculates and returns the player with the highest score.
- **Relationships**:
    - The Game class controls the Player actions and manages the overall game flow (Composition: Game HAS-A set of Players).

## 5. Knucklebones Class (Inherits from Game):
- **Data**:
    - board: A specific Board for the Knucklebones game.
    - knucklebones_rules: Rules specific to the Knucklebones game.
- **Actions**:
    - start_round(): Begins a round of Knucklebones.
    - end_round(): Ends the current round.
    - calculate_winner(): Calculates the winner based on Knucklebones-specific scoring.
- **Relationships**:
    - Knucklebones IS-A Game, meaning it inherits basic game functionality but modifies it with specific rules for Knucklebones.

---

## Keywords:
- **Necessary**:
    - score
    - winner
    - player stats
    - first name
    - dice
    
- **Possible**:
    - high score
    - leaderboard
    - userid
    - streak
    
- **Wishful**:
    - messaging
    - chat
    - coins
    - teams
    - team stats
    - levels

---

## Inheritance vs Composition:
- **Inheritance**: 
    - Knucklebones IS-A Game because it shares the basic structure of a game but has specific rules and features. This relationship uses inheritance to avoid duplicating game management logic.
    
- **Composition**:
    - Player HAS-A Dice, meaning each player interacts with dice objects.
    - The Game HAS-A set of Players and uses them to manage the game’s flow and scoring system.
    - The Knucklebones HAS-A Board to manage the placement and interaction of dice.
