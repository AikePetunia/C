    #include <stdio.h>
    #include <stdbool.h>
    #include <assert.h>
    #define N 5

    bool todos_pares(int a[], int tam, int pos1, int pos2) {
        int i = 0;
        while (pos1 <= pos2 && pos1 < N) { 
            if (a[i] % 2 != 0) {      
                return false;
            }
        i = i + 1;
        }
    }

    int pedirEntero(void) {
        int x;
        scanf("%d", &x);
        assert(x > 0 && "Debe ingresar posiciones enteras positivas");
        return x;
    }

    int main (void) {
        int pos1, pos2;
        int a[N];
        int i = 0;
        printf("Ingrese la primera posicion. Debe ser mas chica que pos2: ");
        pos1 = pedirEntero();
        printf("Ingrese la segunda posicion. Debe ser mas chica que pos2: ");
        pos2 = pedirEntero();
        
        printf("Ingrese los elementos del arreglo de tamaño 5 \n");
        while (i < N) {
            printf("Elemento %d: ", i + 1);
            scanf("%d", &a[i]);
            i = i + 1;
        }

        int respuesta = todos_pares(a, N, pos1, pos2);
        if (respuesta == false) {
            printf("todos los elementos entre las posiciones son impares");
        } else {
            printf("Hay elementos entre las posiciones son pares");
        }
        //programa q entre una posicion una y otra sean numeros pares.
        return 0;
    }