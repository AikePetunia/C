#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define TAM 3

#define CELL_MAX (TAM * TAM - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
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
    int i = 0;
    while (i < TAM){
        char referenceH = board[i][0]; // punto de partida, sin el punto de partida es vacio, no habría patron. "un ancla"
        bool followsPatternH = referenceH != '-'; // sin patron, esto falla y quedará fallado.
        int j = 0;
        

        while (j < TAM && followsPatternH) {
            if (board[i][j] != referenceH) {
                followsPatternH = false;
            }
            j++;
        }
        
        if (followsPatternH) {
            winner = referenceH;
        }

        char referenceV = board[0][i]; // punto de partida, sin el punto de partida es vacio, no habría patron. "un ancla"
        bool followsPatternV = referenceV != '-';  // sin patron, esto falla y quedará fallado.

        while (j < TAM && followsPatternV) {
            if (board[i][j] != referenceV) {
                printf("doesn't follow patter V");
                printf("%c", board[i][j]);
                followsPatternV = false;
            }
            j++;
        }

        if (followsPatternV) {
            winner = referenceV;
        }
       
        i++;
    }

    return winner;
}

bool has_free_cell(char board[TAM][TAM])
{
    bool free_cell=false;
    int i = 0;
    while (i < TAM) {
        int j = 0;
        while (j < TAM)
        {
            if (board[i][j] == '-') {
                free_cell = true;
            }
            j++;
        }
        i++;
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
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
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
