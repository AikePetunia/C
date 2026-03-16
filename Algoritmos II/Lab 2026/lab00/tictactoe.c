#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */
#include <assert.h>  /* assert() */

#define TAM 5
#define CELL_MAX (TAM * TAM - 1)


/*
Run:
gcc -Wall -Wextra -pedantic -std=c99 ./tictactoe.c -o  tictactoe

Debug:
gcc -g -O0 -Wall -Wextra -std=c11 tictactoe.c -o tictactoe
gdb ./tictactoe

break get_winner
run
next
print i
print j
print winner
print board[0][0]
continue

*/
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
        // HORIZONTALES 
        char referenceH = board[i][0]; // punto de partida, sin el punto de partida es vacio, no habría patron. "un ancla" (00, 10, 20, 30)
        bool followsPatternH = referenceH != '-'; // guarda el punto de partida
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

        // VERTICALES
        char referenceV = board[0][i]; // punto de partida, sin el punto de partida es vacio, no habría patron. "un ancla". (00, 01, 02, 03)
        bool followsPatternV = referenceV != '-'; // guarda el punto de partida
        j = 0;  // se reinicia, si no sigue con el num de analisis en horizontal xD

        while (j < TAM && followsPatternV) {
            if (board[j][i] != referenceV) {
                followsPatternV = false;
            }
            j++;
        }

        if (followsPatternV) {
            winner = referenceV;
        }
       
         /* 
         cruzadas:
        los anclajes son los extremos. Como re pingo consigo los extremos.
        por tam?
        ej, TAM = 3
        primer corner [0][0] conj0
        segundo corner [0][TAM-1] conj0
        tercer corner [TAM-1][0] conj1
        cuarto corner [TAM-1][TAM-1] conj1
        Deberia de ver si alguno de estas esquinas conectan.
        Como tambien conectan, deberia de ver si en medio del cruce, estan los caracteres de las esquinas
         */
        char refCross1 = board[0][0];
        bool referenceCross1 = refCross1 != '-';
        int k = 0;

        while (k < TAM && referenceCross1) {
            if (board[k][k] != refCross1) {
                referenceCross1 = false;
            }
            k++;
        }

           if (referenceCross1 ) {
            winner = referenceCross1 ;
        }

        char refCross2 = board[0][TAM - 1];
        bool referenceCross2 = refCross2 != '-';
        k = 0;
        while (k < TAM && referenceCross2) {
            if (board[k][TAM - 1 - k] != refCross2) {
                referenceCross2 = false;
            }
            k++;
        }

        if ( referenceCross2) {
            winner = referenceCross2;
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
