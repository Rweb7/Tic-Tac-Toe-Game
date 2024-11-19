// Programming Assignment 1 - Tic-Tac-Toe Game
// Author: Ryan Webster
// A simple game of Tic-Tac-Toe designed for one player to play against a computer-controlled player.

#include <stdio.h>    // For input and output functions.
#include <stdlib.h>  // For general utility functions, including memory allocation, random numbers, etc.
#include <ctype.h>  // For character testing and conversion.
#include <time.h>  // For manipulating date and time information.

// Global Variables
char board[3][3];            // 3x3 character array representing the Tic-Tac-Toe board.
const char PLAYER = 'X';    // Represents the symbol for the human player.
const char COMPUTER = 'O'; // Represents the symbol for the computer player.
char winner;              // Will hold the winning symbol ('X' for player or 'O' for computer) or a space (' ').
char playerName;         // Will hold user input when prompted to enter their name.


void resetBoard() // Function initializes the board by setting all its cells to an empty space.

{
    for(int i=0; i<3; i++) // Nested loop. iterates over the rows

    {
        for(int j=0; j<3; j++) // Nested loop. iterates over the columns.

        {
            board[i][j] = ' '; // Setting each cell of the board to a space.
        }
    }
}

void printBoard() // Function prints the current state of the board to the console.

{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2] );
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2] );
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2] );
    printf("\n)");
}

int checkFreeSpaces() // Function counts and returns the number of free spaces left on the board.

{
  int freeSpaces = 9; // Set to 9, the maximum number of cells.

    for(int i = 0; i < 3; i++) // Iterates through each cell; if a cell is not empty.

    {
        for(int j = 0; j < 3; j++) // Iterates through each cell; if a cell is not empty.

        {
          if(board[i][j] != ' ')

          {
              freeSpaces--; // If not empty, it decrements 'freeSpaces'.
          }
        }
    }

    return freeSpaces; // Returns the count of free cells.
}

void playerMove() // Function allows the human player to input their move.

{
    int x;
    int y;

    do

    {
        printf("Enter row coordinate between 1 to 3: "); // Asks the player for row and column coordinates.
        scanf("%d", &x); // Saves user input.
        x--; // Adjusts the coordinates to match array indexing (subtracting 1).

        printf("Enter column coordinate between 1 to 3: "); // Asks the player for row and column coordinates.
        scanf("%d", &y); // Saves user input.
        y--; // Adjusts the coordinates to match array indexing (subtracting 1).

        if(board[x][y] != ' ') // If the selected cell is already occupied, it prints an error message and repeats the prompt.

        {
            printf("Invalid move!\n");
        }

        else

        {
            board[x][y] = PLAYER; // If the cell is empty, it updates the cell with the player's symbol.
            break;
        }
    }

    while(board[x][y] != ' ');
}

void computerMove() // Function makes a random move for the computer.

{
  srand(time(0)); // It seeds the random number generator with the current time.
    int x;
    int y;

    if(checkFreeSpaces() > 0) // If there are any free spaces then...

    {
       do

       {
           x = rand() % 3;  // It generates random row and column coordinates until it finds an empty cell.
           y = rand() % 3; // Generates a random row/column index (0, 1, or 2).
       }

        while(board[x][y] != ' ');

        board[x][y] = COMPUTER; // It then places the computer’s symbol in that cell.
    }

    else

    {
        printWinner(' '); // If no free spaces are left, it prints a draw message by calling 'printWinner' with a space.
    }
}

char checkWinner() // Function checks all rows, columns, and diagonals to see if there is a winner.

{
  for(int i = 0; i < 3; i++) // It checks each row to see if all three cells are the same.

  {
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2])

    {
      return board[i][0];
    }
  }
    for(int i = 0; i < 3; i++) // It checks each column to see if all three cells are the same.

        {
            if(board[0][i] == board[1][i] && board[0][i] == board[2][i])

            {
                return board[0][i];
            }
        }
            if(board[0][0] == board[1][1] && board[0][0] == board[2][2]) // Check diagonals.

       {
           return board[0][0];
       }

          if(board[0][2] == board[1][1] && board[0][2] == board[2][0]) // Check diagonals.

      {
         return board[0][2];
      }

    return ' ';
}

void printWinner(char winner) // Function prints the result of the game based on the winner symbol.

{
   if (winner == PLAYER) // It checks the winner variable.

   {
     printf("You win!\n");
   }

    else if (winner == COMPUTER) // It checks the winner variable.

    {
      printf("Computer win!\n");
    }

    else

    {
      printf("It's a draw!\n");
    }
}

int main()  // Where the functionality of the game done.

{

    printf("Welcome! Let's play a game!\n\n "); // Initial welcome message.
    char playerName[20]; // Array to hold 20 individual characters.
    printf("First tell me.. What is your name?");
    scanf("%99s", playerName); // Saves user input.
    printf("Hello %s! Let's get started!\n\n", playerName);

    char winner = ' ';
    resetBoard();


    while(winner == ' ' && checkFreeSpaces() != 0)

    {
        printBoard();

        playerMove(); // Takes the player's move and checks for a winner.
        winner = checkWinner();
        if(winner != ' ' || checkFreeSpaces() == 0) // If no winner is found and spaces are still available, lets the computer move and checks for a winner again.

        {
          break;
        }

        computerMove(); // Takes the computer's move and checks for a winner.
        winner = checkWinner();
        if(winner != ' ' || checkFreeSpaces() == 0)

        {
            break;
        }
    }

    printBoard();
    printWinner(winner); // Once the loop exits, it prints the final board and announces the winner.

    return 0; // Returns 0 to indicate the program ended successfully.
}


