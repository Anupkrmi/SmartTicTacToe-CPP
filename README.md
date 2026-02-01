# SmartTicTacToe-CPP

SmartTicTacToe-CPP is a command-line Tic-Tac-Toe game implemented in C++ featuring human and AI gameplay modes with multiple difficulty levels.

The project focuses on clean game logic, rule-based artificial intelligence, input validation, and modular program design.

---

## 📌 Overview

This project is a terminal-based Tic-Tac-Toe application developed using standard C++ libraries. It supports both multiplayer and single-player modes, where users can play against an AI with different difficulty levels.

The project was built to practice algorithmic thinking, state management, and decision-making logic in C++.

---

## 🚀 Features

- Two Player Mode (Local Multiplayer)
- Single Player Mode (Human vs Computer)
- AI Difficulty Levels:
  - Easy: Random valid move selection
  - Medium: Rule-based strategy (Win, Block, Center, Corners)
- Input validation and error handling
- Automatic win and draw detection
- Console-based user interface
- Clean and structured codebase

---

## 🛠️ Technologies Used

- Programming Language: C++
- Compiler: GCC / MinGW
- Libraries:
  - `<iostream>` for input/output
  - `<cstdlib>` for random number generation
  - `<ctime>` for random seed initialization

---

## 📂 Project Structure

🎮 How to Play
--

Run the program.

Select game mode:

Single Player

Two Player

If Single Player is selected, choose difficulty.

Players take turns entering positions from 1 to 9.

The first player to align three symbols in a row wins.

If the board fills without a winner, the game ends in a draw.

🧠 AI Implementation
--
Easy Mode

Collects all available empty positions.

Selects a random valid move.

Medium Mode

Checks for immediate winning moves.

Blocks opponent's winning moves.

Prioritizes center position.

Selects available corner positions.

Falls back to random selection.

The AI uses board simulation to evaluate potential moves before making decisions.

📈 Learning Objectives
--

This project was developed to strengthen understanding of:

Procedural programming in C++

Modular function design

Game state representation

Input validation techniques

Rule-based AI logic

Simulation-based decision making

Debugging and testing strategies

🧪 Testing
--

The program has been tested for:

Invalid user inputs

Edge cases in win detection

AI decision correctness

Draw scenarios

Stability across multiple runs

Manual testing was performed by playing multiple rounds in all available modes.

🔮 Future Enhancements
--

Planned improvements include:

Hard difficulty using Minimax algorithm

Improved command-line interface

Enhanced error handling

Code refactoring using OOP principles

Support for configurable board sizes

👤 Author
--

Anup Mishra

Engineering Student
Focused on C++ development and system-level programming

📄 License
--

This project is developed for educational and learning purposes.

You are free to use, modify, and distribute this code for non-commercial applications.

⭐ Acknowledgments
--

This project was built as part of self-directed learning to strengthen core programming concepts and problem-solving skills.
