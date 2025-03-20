#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define TAM 5

#define CELL_MAX (TAM * TAM - 1)


void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < TAM;i++) printf("................");
    printf("\n");

}

void print_board(char board[TAM][TAM])
{
    int cell = 0;

    print_sep(TAM);
    for (int row = 0; row < TAM; ++row) {
        for (int column = 0; column < TAM; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(TAM);
    }
}

char get_winner(char board[TAM][TAM])
{
    char winner = '-';
    int counter = 0;
    /* 8 possible winner movements, otherwise is a tie
       i is column, j is row  */
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            //horizontal
            if (board[i] ) {
                winner = board[i][j];
            }

            //diagonal, doesnt work.
            if (board[i][i] == board[j][j] ) {
                winner = board[i][j];
            }

            /*  old
            //check for Diagonal
            if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
                winner = board[i][0];
            }
            if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
                winner = board[0][i];
            } 
            //check horizontal
            if (board[i][1] == board[j][1] && board[i][2] == board[j][2] && board[i][3] == board[j][3]) {
                winner = board[i][0];
            }

            if(board[0][2] == board[1][1] && board[0][2] == board[2][0] ) {
                winner = board[0][2];
            }   
            */
        }
    }
    return winner;
}

bool has_free_cell(char board[TAM][TAM])
{
    bool free_cell=false;
    
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (board[i][j] == '-') {
                free_cell = true;
            }
        }
    }
    return free_cell;
}

int main(void)
{
    printf("TicTacToe\n");

    char board[TAM][TAM] = {};

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            board[i][j] = '-';
        }
    }

    char turn = 'X';
    char winner = '-';
    int cell = 0;

    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn, CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / TAM;
            int colum = cell % TAM;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
