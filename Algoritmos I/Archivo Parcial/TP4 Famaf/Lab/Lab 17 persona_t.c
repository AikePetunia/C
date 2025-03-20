#include <stdio.h>

typedef struct _persona {
    char *nombre;
    int edad;
    float altura;
    float peso;
} persona_t;

float peso_promedio(unsigned int longitud, persona_t arr[]) { //La longitud es la cantidad de personas/arreglos
    float suma = 0; //Debo sumar el peso de las personas
    for (int i = 0; i < longitud; i++) {
        suma += arr[i].peso;
    }
    return suma / longitud;
};
persona_t persona_de_mayor_edad(unsigned int longitud, persona_t arr[]) {
    persona_t mayor = arr[0];   //empiezo a reccorrer el arreglo
    for (int i = 1; i < longitud; i++) {
        if (arr[i].edad > mayor.edad) {
            mayor = arr[i];
        }
    }
    return mayor;
};
persona_t persona_de_menor_altura(unsigned int longitud, persona_t arr[]) {
    persona_t menor = arr[0]; //empiezo a reccorrer el arreglo
    for (int i = 1; i < longitud; i++) {
        if (arr[i].altura < menor.altura) {
            menor = arr[i];
        }
    }
    return menor;
};

int main(void) {
    persona_t p1 = {.nombre="Paola", .edad=21, .altura=1.85, .peso=75};
    persona_t p2 = {.nombre="Luis", .edad=54, .altura=1.75, .peso=69};
    persona_t p3 = {.nombre="Julio", .edad=40, .altura=1.70, .peso=80};

    unsigned int longitud = 3;
    persona_t arr[] = {p1, p2, p3};

    printf("El peso promedio es %f\n", peso_promedio(longitud, arr));
    persona_t p = persona_de_mayor_edad(longitud, arr);

    printf("El nombre de la persona con mayor edad es %s\n", p.nombre);

    p = persona_de_menor_altura(longitud, arr);
    printf("El nombre de la persona con menor altura es %s\n", p.nombre);
    return 0;
}
// sols: https://github.com/Lautron/FOSS-FAMAF/tree/master/a%C3%B1o1/ayed1/Laboratorio/proyecto4