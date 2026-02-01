/**
 * @file TicTacToe.cpp
 * @brief A console-based Tic-Tac-Toe game with Single and Two-player modes.
 * @details Implements a basic AI for single-player mode with Easy and Medium difficulties.
 */

#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

// --- Function Prototypes ---
void printBoard(char board[]);
int getPlayerInput(char board[]);
void executePlayerMove(char turn, char board[]);
void executeCompMove(char board[], int compMove);
bool checkWinCondition(char board[]);
int selectDifficulty();
int getEasyMove(char board[]);
int getMediumMove(char board[]);

/**
 * @brief Displays the current state of the game board.
 * @param board Array representing the grid.
 */
void printBoard(char board[]) {
    cout << "\n";
    cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << endl;
    cout << "-----------------" << endl;
    cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << endl;
    cout << "-----------------" << endl;
    cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << endl;
    cout << "\n";
}

/**
 * @brief Handles user input validation.
 * @param board Current board state to check for occupied spaces.
 * @return Returns valid index (0-8) or -1 if input is invalid.
 */
int getPlayerInput(char board[]) {
    int inputPos = -1;

    cout << "Enter Position (1-9): ";
    cin >> inputPos;

    // Handle non-integer inputs to prevent infinite loops
    if (cin.fail()) {
        cin.clear(); // Clear error flag
        cin.ignore(1000, '\n'); // Discard invalid input
        cout << "Invalid Input (Non-numeric)." << endl;
        return -1;
    }

    // Convert 1-based input to 0-based index
    inputPos--;

    // Check bounds
    if (inputPos < 0 || inputPos > 8) {
        cout << "Invalid Input (Out of bounds)." << endl;
        return -1;
    }

    // Check availability
    if (board[inputPos] != ' ') {
        cout << "Position already occupied!" << endl;
        return -1;
    }

    return inputPos;
}

/**
 * @brief Manages the loop for a player's turn until valid input is received.
 * @param turn The character of the current player ('X' or 'O').
 * @param board The game board.
 */
void executePlayerMove(char turn, char board[]) {
    int pos = -1;
    do {
        pos = getPlayerInput(board);
    } while (pos == -1);
    
    board[pos] = turn;
}

/**
 * @brief Executes the Computer's move.
 * @param board The game board.
 * @param compMove The index where the computer wants to place 'O'.
 */
void executeCompMove(char board[], int compMove) {
    if (compMove >= 0 && compMove < 9) {
        board[compMove] = 'O';
    }
}

/**
 * @brief Checks if a winning condition has been met.
 * @param board The game board.
 * @return true if there is a winner, false otherwise.
 */
bool checkWinCondition(char board[]) {
    // 1. Check Vertical Columns
    for (int i = 0; i < 3; i++) {
        if (board[i] != ' ' && board[i] == board[i + 3] && board[i + 3] == board[i + 6]) {
            return true;
        }
    }

    // 2. Check Horizontal Rows
    for (int i = 0; i <= 6; i += 3) {
        if (board[i] != ' ' && board[i] == board[i + 1] && board[i + 1] == board[i + 2]) {
            return true;
        }
    }

    // 3. Check Diagonals
    // Left-to-Right Diagonal (0, 4, 8)
    if (board[0] != ' ' && board[0] == board[4] && board[4] == board[8]) {
        return true;
    }
    // Right-to-Left Diagonal (2, 4, 6)
    if (board[2] != ' ' && board[2] == board[4] && board[4] == board[6]) {
        return true;
    }

    return false;
}

/**
 * @brief Prompts user to select AI difficulty.
 * @return 1 for Easy, 2 for Medium, 3 for Hard (defaults to 2 on error).
 */
int selectDifficulty() {
    int diff = 0;
    cout << "( 1-Easy, 2-Medium, 3-Hard )" << endl;
    cout << "Enter game difficulty: ";
    cin >> diff;

    if (diff == 1) {
        cout << "Difficulty set to: Easy" << endl;
        return 1;
    } else if (diff == 2) {
        cout << "Difficulty set to: Medium" << endl;
        return 2;
    } else if (diff == 3) {
        cout << "Difficulty set to: Hard (Note: Using Medium logic for now)" << endl;
        return 3;
    } else {
        cout << "Invalid Input. Please try again." << endl;
        return 0; // Return 0 to trigger the loop in main
    }
}

/**
 * @brief Easy AI: Selects a random empty spot.
 */
int getEasyMove(char board[]) {
    int freePos[9];
    int count = 0;

    // Find all empty spots
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            freePos[count] = i;
            count++;
        }
    }

    if (count == 0) return -1; // Board is full

    int r = rand() % count;
    return freePos[r];
}

/**
 * @brief Medium AI Strategy:
 * 1. Win if possible.
 * 2. Block opponent if they are about to win.
 * 3. Take Center.
 * 4. Take Corners.
 * 5. Random move.
 */
int getMediumMove(char board[]) {
    bool canWin;

    // Step 1: Attack - Check if Computer can win immediately
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            board[i] = 'O'; // Temporarily place O
            canWin = checkWinCondition(board);
            board[i] = ' '; // Reset spot
            if (canWin) {
                return i;
            }
        }
    }

    // Step 2: Defense - Check if Player is about to win and block
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            board[i] = 'X'; // Temporarily simulate Player X
            canWin = checkWinCondition(board);
            board[i] = ' '; // Reset spot
            if (canWin) {
                return i;
            }
        }
    }

    // Step 3: Take Center
    if (board[4] == ' ') return 4;

    // Step 4: Take Corners (0, 2, 6, 8)
    int corners[] = {0, 2, 6, 8};
    for(int i : corners) {
        if(board[i] == ' ') return i;
    }

    // Step 5: Random Move
    return getEasyMove(board);
}

int main() {
    srand(time(0)); // Seed random number generator

    char board[9];
    bool gameWon = false;
    int level = 0;
    int gameMode = 0;
    int compMoveIndex = -1;

    // Initialize board
    for (int i = 0; i < 9; i++) {
        board[i] = ' ';
    }

    cout << "=======================" << endl;
    cout << "   Tic-Tac-Toe Game" << endl;
    cout << "=======================" << endl;

    // Game Mode Selection
    while (gameMode != 1 && gameMode != 2) {
        cout << "1 - Single Player vs Computer\n2 - Two Players" << endl;
        cout << "Enter mode: ";
        cin >> gameMode;
        
        if (cin.fail()) {
            cin.clear(); cin.ignore(1000, '\n');
            gameMode = 0; // Reset to force loop
        }
        
        if (gameMode != 1 && gameMode != 2) {
            cout << "Invalid Input." << endl;
        }
    }

    printBoard(board);

    // If Single Player, get difficulty
    if (gameMode == 1) {
        while (level == 0) {
            level = selectDifficulty();
        }
    }

    // Main Game Loop (Max 9 moves)
    char currentTurn;
    for (int moveCount = 0; moveCount < 9; moveCount++) {
        
        // Determine whose turn it is
        if (moveCount % 2 == 0) {
            currentTurn = 'X'; // Player 1
        } else {
            currentTurn = 'O'; // Player 2 or Computer
        }

        // --- Player X Logic (Always Human) ---
        if (currentTurn == 'X') {
            cout << "Player X's turn:" << endl;
            executePlayerMove(currentTurn, board);
        }
        // --- Player O Logic ---
        else {
            if (gameMode == 2) {
                // Two Player Mode: Human plays O
                cout << "Player O's turn:" << endl;
                executePlayerMove(currentTurn, board);
            } else {
                // Single Player Mode: Computer plays O
                cout << "Computer's Turn..." << endl;
                
                if (level == 1) {
                    compMoveIndex = getEasyMove(board);
                } else {
                    // Medium AI covers Medium and Hard (since Hard wasn't implemented)
                    compMoveIndex = getMediumMove(board);
                }
                
                executeCompMove(board, compMoveIndex);
            }
        }

        printBoard(board);
        gameWon = checkWinCondition(board);

        if (gameWon) {
            if (gameMode == 1 && currentTurn == 'O') {
                cout << "Computer Wins!" << endl;
            } else {
                cout << "Player " << currentTurn << " Wins!" << endl;
            }
            break; // Exit loop
        }
    }

    if (!gameWon) {
        cout << "It's a Draw!" << endl;
    }

    // Pause before closing (optional)
    cout << "Press Enter to exit...";
    cin.ignore(); cin.get();

    return 0;
}
