#include<bits/stdc++.h>
using namespace std;

// this will print the current state of the board.
void printBoard(const vector<vector<char>>& board){     std::cout<<std::endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<< board[0][0] << "  |  "<< board[0][1] << "  |  " << board[0][2] <<endl;
    cout<<"_____|_____|_____" <<endl;
    cout<<"     |     |     " <<endl;
    cout<<"  "<< board[1][0] << "  |  "<< board[1][1] <<"  |  " << board[1][2] <<endl;
    cout<<"_____|_____|_____" <<endl;
    cout<<"     |     |     " <<endl;
    cout<<"  "<< board[2][0] << "  |  " << board[2][1] <<"  |  " << board[2][2] <<endl;
    cout<<"     |     |     " <<endl<<endl;
}

// Function to make a move on the Tic Tac Toe board.
bool makeMove(vector<vector<char>>& board, int row, int col, char player){
    if(board[row][col] == ' '){
        board[row][col] = player;
        return true;
    }
    return false;
}

// Function to check if a player has won.
bool checkWin(const vector<vector<char>>& board, char player){
    // check rows, cols and diagonals;
    for(int i = 0; i < 3; i++){
        if((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
        (board[0][i] == player && board[1][i] == player && board[2][i] == player)){
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
    (board[2][0] == player && board[1][1] == player && board[0][2] == player)) {
        return true;
    }
    return false;
}

// Function which checks either board is full ?
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

int main(){
    const int boardSize = 3;
    std::vector<std::vector<char>> board(boardSize, vector<char>(boardSize, ' '));

    char currentPlayer = 'X';
    int row, col;

    cout<<"\n===============================";
    cout<<"\n\tTic Tac Toe";
    cout<<"\n===============================\n";

    do{
        // print the current state of board.
        printBoard(board);

        // getting the playes move.
        cout << "player "<< currentPlayer <<" Enter your move(rows and cols): ";
        cin >> row >> col;

        if(row >= 0 && row < boardSize && col >= 0 && col < boardSize && board[row][col] == ' '){
            // make the move.
            makeMove(board, row, col, currentPlayer);

            //check for a win
            if(checkWin(board, currentPlayer)){
                std::cout<<std::endl;
                printBoard(board);
                cout << "Player: " << currentPlayer << " wins! " <<std::endl;
                break;
            }

            // check for draw;
            if(isBoardFull(board)){
                std:: cout<< std:: endl;
                cout<< "It's a DRAW!"<<endl;
                break;
            }

            // switch the other player!
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }else{
            std::cout<<"INVALID MOVE !, TRY AGAIN !"<< std::endl;
        }

    }while(true);

    return 0;
}