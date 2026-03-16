#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define TAM 5

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

char get_winner(char board[TAM][TAM]) {
    char winner = '-';
        
    // i is row, j is column  

            /*
                Diagonal (\ /)
                si hago board[i][j], esta checkeando pos:
                0 0
                1 1
                2 2
                3 3
                4 4 
                n n

                Si es horizontal ( --- )
                0 0     1 0      
                0 1     1 1 
                0 2     1 2 
                0 3     1 3 
                0 4     1 4 
                0 5     1 5
                0 n     1 n

                Si es verticual ( | )
            
                0 0     0 1 
                1 0     1 1 
                2 0     2 1 
                3 0     3 1
                4 0     4 1 
                n 0     n 1 

                Deberia de checkear que se igual a una posicion anterior, o usar alguna posicion de referencia para comparar, la nueva, con la que se debe usar/incrementar.

            */
    // creamos variables para ir almacenando valores ganadores, para luego hacer un ternary operator para verificar si es ganador o no, para al final devolver al menos uno.
    bool verticalWinner = true;
    bool horizontalWinner = true;

    bool diagonalWinnerLR = true;
    bool diagonalWinnerRL = true;
    
    for (int i = 0; i < TAM; i++) {
        // horizontal, vertical, como se incrementa una posicion o la otra, necesito otro bucle
        for (int j = 0; j < TAM; j++) {
            if (board[i][0] == '-' || board[0][i] == '-') { // Horizontal o verticual
                if (verticalWinner && board[i][j] != board[i][0]) verticalWinner = false;
                horizontalWinner ? (board[i][j] != board[0][i]) : false;
            } 
        }
        
        // diagonal, se aumenta el mismo valor y lito, tiene dos sentidos, de izquierda para derecha, o de derecha a izquierda (ode arriba a abajo y de abajo a arriba, whatever)
            /*  
                Las esquinas son:
                board[0][0] (Arriba, izq)
                board[TAM-1][0] (abajo, izq )
                board[0][TAM-1] (arriba, der)
                board[TAM-1][TAM-1] (abajo, der)
            */
            if (board[0][0] != board[TAM-1][0] ) {
                if (board[i][i] == board[0][0]) {
                    winner = board[0][0];
                }
            }

            if (board[0][TAM-1] != board[TAM-1][TAM-1]) {
                if (board[TAM-1-i][i] == board[i][TAM-1-i]) {
                    winner = board[TAM-1][0];
                }
            }
    }
    return winner;

    //bue, nm ose
}


bool has_free_cell(char board[TAM][TAM]){
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

    char board[TAM][TAM];

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
