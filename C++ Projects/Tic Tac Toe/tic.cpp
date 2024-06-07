#include <iostream>
#include <vector>

// Function prototypes
void printBoard(const std::vector<std::vector<char>>& board);
bool makeMove(std::vector<std::vector<char>>& board, int row, int col, char player);
bool checkWin(const std::vector<std::vector<char>>& board, char player);
bool isBoardFull(const std::vector<std::vector<char>>& board);


// Function to print the current state of the Tic Tac Toe board
void printBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "  0 1 2" << std::endl;
    for (int i = 0; i < board.size(); ++i) {
        std::cout << i << " ";
        for (int j = 0; j < board[i].size(); ++j) {
            std::cout << board[i][j];
            if (j < board[i].size() - 1) {
                std::cout << "|";
            }
        }
        std::cout << std::endl;
        if (i < board.size() - 1) {
            std::cout << "  -----" << std::endl;
        }
    }
    std::cout << std::endl;
}

// Function to make a move on the Tic Tac Toe board
bool makeMove(std::vector<std::vector<char>>& board, int row, int col, char player) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    } else {
        return false;
    }
}

// Function to check if a player has won
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check if the board is full (a tie)
bool isBoardFull(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false; // There's an empty cell, the board is not full
            }
        }
    }
    return true; // All cells are filled, it's a tie
}


int main() {
    const int boardSize = 3;
    std::vector<std::vector<char>> board(boardSize, std::vector<char>(boardSize, ' '));

    char currentPlayer = 'X';
    int row, col;

    do {
        // Print the current state of the board
        printBoard(board);

        // Get the player's move
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        // Check if the move is valid
        if (row >= 0 && row < boardSize && col >= 0 && col < boardSize && board[row][col] == ' ') {
            // Make the move
            makeMove(board, row, col, currentPlayer);

            // Check for a win
            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                break;
            }

            // Check for a tie
            if (isBoardFull(board)) {
                printBoard(board);
                std::cout << "It's a tie!" << std::endl;
                break;
            }

            // Switch to the other player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            std::cout << "Invalid move. Try again." << std::endl;
        }

    } while (true);

    return 0;
}

