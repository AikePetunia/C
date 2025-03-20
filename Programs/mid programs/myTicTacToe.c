#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

//variables globales
char gameBoard[3][3];
char PLAYER;
char COMPUTER;

//declaro que usare a lo largo del programa, despues pienso como deberia de funcionar
void playerCharacter();
void resetBoard ();
void printBoard ();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main () {
    printf("tic tac toe\n");
    playerCharacter();
    char winner = ' ';
    char playAgain;

    do {
    winner = ' ';
    playAgain = ' ';
    resetBoard();

    while (winner == ' ' && checkFreeSpaces() != 0) {
        printBoard();

        playerMove();

        winner = checkWinner();

        if (winner != ' ' || checkFreeSpaces() == 0) {
            break;
        }

        computerMove();
        winner = checkWinner();

        if (winner != ' ' || checkFreeSpaces() == 0) {
            break;
        }
    }

    printBoard();
    printWinner(winner);

    do {
        printf("Play again? (y/n): ");
        scanf(" %c", &playAgain);
        playAgain = tolower(playAgain);
    } while (playAgain != 'y' && playAgain != 'n');

} while (playAgain == 'y');

    
    return 0;
}

void playerCharacter() {
    char inputP;
    char inputC;
    printf("Choose your character: ");
    scanf(" %c", &inputP);
    PLAYER = inputP;
    
    do {
        printf("Choose character for computer (must be different from %c): ", PLAYER);
        scanf(" %c", &inputC);
    } while (inputP == inputC);

    COMPUTER = inputC;
}

void resetBoard () 
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            gameBoard[i][j] = ' ';
         }
    }
}
void printBoard () 
{
    printf(" %c  | %c  | %c", gameBoard[0][0], gameBoard[0][1], gameBoard[0][2]); //row 0, column 0, y asi
    printf("\n----|----|---- \n");
    printf(" %c  | %c  | %c", gameBoard[1][0], gameBoard[1][1], gameBoard[1][2]);
    printf("\n----|----|---- \n");
    printf(" %c  | %c  | %c", gameBoard[2][0], gameBoard[2][1], gameBoard[2][2]); 
    printf("\n");
}
int checkFreeSpaces() 
{
    int freeSpaces = 9;
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if(gameBoard[i][j] != ' ') {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}
void playerMove() 
{
    int y;
    int x;

    do {
        printf("Enter row #(1-3): ");
        scanf("%d", &x);
        x--;

        printf("Enter column #(1-3): ");
        scanf("%d", &y);
        y--;

        if (x < 0 || x > 2 || y < 0 || y > 2 || gameBoard[x][y] != ' ' || isdigit(gameBoard[x][y])) {
            printf("Invalid move. Try again.\n");
        } else {
            gameBoard[x][y] = PLAYER;
            break;
        }
    } while (1);
}
void computerMove() 
{
    //Es movimiento random xD
    srand(time(0));
    int x;
    int y;

    if(checkFreeSpaces() > 0 ) 
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (gameBoard[x][y] != ' ');
        
        gameBoard[x][y] = COMPUTER;
    }   else {
        printWinner(' ');
    }
}
char checkWinner() 
{
    //vemos columnas, posibles wins.
    //veo horizontales & verticales

    for(int i = 0; i < 3; i++) {
        if(gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][0] == gameBoard[i][2] )   
        {
            return gameBoard[i][0];
        }   
    }

    for(int i = 0; i < 3; i++) {
        if(gameBoard[0][i] == gameBoard[1][i] && gameBoard[0][i] == gameBoard[2][i] )   
        {
            return gameBoard[0][i];
        }   
    }

    //ver diagonales (posibles wins)

    for(int i = 0; i < 3; i++) {
        if(gameBoard[0][i] == gameBoard[1][1] && gameBoard[0][i] == gameBoard[2][2] )   
        {
            return gameBoard[0][0];
        }   
    }

    for(int i = 0; i < 3; i++) {
        if(gameBoard[0][2] == gameBoard[1][1] && gameBoard[0][2] == gameBoard[2][0] )   
        {
            return gameBoard[0][2];
        }   
    }

    return ' ';
}
void printWinner(char winner) 
{
    if(winner == PLAYER) {
        printf("Player wins \n");
    }   else if (winner == COMPUTER) {
        printf("Computer wins \n");
    }   else {
        printf(" Draw \n");
    }
}