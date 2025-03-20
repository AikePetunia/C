#include <stdio.h>

/*
    a[] tiene su tam, que tiene elemento de tipo:
    struct producto_t --> (Precio, Peso en kilos) <-- INT'S
    Este struct, devuelve el precio a pagar, y el total de kg de a[]
*/

struct producto_t {
    int precio;
    int peso_en_kilos;
};

struct total_t {
    int precio_total;
    int peso_total;
};

struct total_t calcular_montos(struct producto_t a[], int tam) {    
    struct total_t resultados;
    resultados.precio_total = 0;
    resultados.peso_total = 0;
    for (int i = 0; i < tam; i++) {
        resultados.precio_total += a[i].precio;
        resultados.peso_total += a[i].peso_en_kilos;
    }
    return resultados;
};

int main(void) {
    const int N = 5;
    struct producto_t productos[N];
    int tam = 5;
    int a[N];

    printf("Ingrese los datos de sus productos. Primero el precio, y luego el peso: \n");
    for (int k = 0; k < N; k++) {
        printf("Precio de elemento %d: ", k + 1);
        scanf("%d", &productos[k].precio);  

        printf("Peso de elemento %d: ", k + 1);
        scanf("%d", &productos[k].peso_en_kilos); 
    } //Se guardan en tuplas
    
    printf("\nProductos ingresados:\n");
    for (int k = 0; k < N; k++) {
        printf("Producto %d -> Precio: %d, Peso: %d\n", k + 1, productos[k].precio, productos[k].peso_en_kilos);
    }

    struct total_t resultados = calcular_montos(productos, tam);

    printf("El total de precio es %d, el total de kilos es %d", resultados.precio_total, resultados.peso_total);
    /*
    El usuario debe ingresar elementos de:
    struct producto_t --> (Precio, Peso en kilos) <-- INT'S
    De un tamaño predeterminado N (CONST (raro))
    Puedo crear una funcion, opcinalmente, "pedirArreglo();" <- ni ahí
    Debo printear la funcion Calcular montos.
    */
    return 0;
}

