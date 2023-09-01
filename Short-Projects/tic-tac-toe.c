#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to draw the Tic Tac Toe board
void drawBoard(char* board){
    for(int i = 0; i < 9; ++i){
        if(i % 3 == 0 && i != 0){
            printf("===== ===== =====\n");
        }
        if(i == 1 || i == 4 || i == 7){
            printf("     |     |   \n  %c  |  %c  |  %c\n     |     |   \n", board[i], board[i+1], board[i+2]);
        }
    }
}

// Function to display a congratulations message for the winner
void congrats(int turn, char *board){
    if(turn == 1){
        printf("Congrats, Player 1 has won the game!\n");
    }
    else{
        printf("Congrats, Player 2 has won the game!\n");
    }
    drawBoard(board);
}

// Function to check for a win along a horizontal or vertical line
int checkLineWin(char *board, int draw){
    for(int i = 1; i < 4; ++i){
        if(board[i] == 'X' && board[i + 3] == 'X' && board[i + 6] == 'X'){
            return 15; // Indicates a win
        }
        else if(board[i] == 'O' && board[i + 3] == 'O' && board[i + 6] == 'O'){
            return 15; // Indicates a win
        }
    }
    
    for(int i = 1; i < 8; i += 3){
        if(board[i] == 'X' && board[i+1] == 'X' && board[i+2] == 'X'){
            return 15; // Indicates a win
        }
        else if(board[i] == 'O' && board[i+1] == 'O' && board[i+2] == 'O'){
            return 15; // Indicates a win
        }
    }
    return draw; // Return the draw counter if no win is detected
}

// Function to check for a win along a diagonal line
int checkDiagWin(char *board, int draw){
    if(board[1] == 'X' && board[5] == 'X' && board[9] == 'X'){
        return 15; // Indicates a win
    }
    else if(board[1] == 'O' && board[5] == 'O' && board[9] == 'O'){
        return 15; // Indicates a win
    }
    
    if(board[3] == 'X' && board[5] == 'X' && board[7] == 'X'){
        return 15; // Indicates a win
    }
    
    if(board[3] == 'O' && board[5] == 'O' && board[7] == 'O'){
        return 15; // Indicates a win
    }
    return draw; // Return the draw counter if no win is detected
}

// Function to check if a given position on the board is available
int checkPosition(char *board, int index, char input){
    int check = board[index] - '0';
    int check2 = input - '0';
    
    if(check == check2){
        return 1; // Position is available
    }
    return 0; // Position is not available
}

// Function to mark the board based on player's input
int markBoard(char *board, int turn){
    char input;
    scanf(" %c", &input);
    
    if(turn == 0){
        printf("Player 1, please input your position.\n");
        int index = input - '0';
        int check = checkPosition(board, index, input);
        
        if(check == 1){
            board[index] = 'X'; // Mark the board with 'X'
        }
        else{
            printf("Please provide a valid position.\n");
            markBoard(board, turn);
        }
        
        return 1; // Return the turn to switch players
    }
    else{
        printf("Player 2, please input your position.\n");
        int index = input - '0';
        int check = checkPosition(board, index, input);

        if(check == 1){
            board[index] = 'O'; // Mark the board with 'O'
        }
        else{
            printf("Please provide a valid position.\n");
            markBoard(board, turn);
        }
        
        return 0; // Return the turn to switch players
    }
    return 0;
}

// Function to initiate the game and control the game loop
void initiateGame(char *board, int draw, int turn){
    printf("Welcome to my TIC TAC TOE game.\n");
    printf("The winner is decided if either player connects their symbols (vertically, diagonally, or horizontally)\n");
    printf("Player 1: O   Player 2: X\n\n");
    
    int winCondition = 15, drawLimit = 10;
    drawBoard(board); // Display the initial empty board
    turn = markBoard(board, turn); // Start marking the board
    while(draw < drawLimit){
        drawBoard(board); // Display the current state of the board
        turn = markBoard(board, turn); // Mark the board for the current player
        int checkWin = checkDiagWin(board, draw); // Check diagonal win
        
        if(checkWin != winCondition){
            checkWin = checkLineWin(board, draw); // Check horizontal and vertical wins
            
            if(checkWin != winCondition){
                continue; // Continue the game loop if no player has won yet
            }
            else{
                congrats(turn, board); // Display the winner if there's a win
                break; // Exit the game loop
            }
        }
        else{
            congrats(turn, board); // Display the winner if there's a win
            break; // Exit the game loop
        }
        draw++; // Increment draw counter
    }
    if(draw == drawLimit){
        printf("This game ended in a draw!\n"); // Display draw message
        drawBoard(board); // Draw final board
    }
}

int main(){
    char board[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int draw = 0, turn = 0;
    initiateGame(board, draw, turn); // Start the game
    return 0; // Exit the program
}
