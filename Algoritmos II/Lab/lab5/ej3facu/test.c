#include <stdio.h>
#include "list.h"

int main(void) {
    list l = empty();
    printf("Lista vacía: %s\n", is_empty(l) ? "sí" : "no");

    // Agregar elementos al inicio
    l = addl(3, l);
    l = addl(2, l);
    l = addl(1, l);
    printf("Lista después de addl: ");
    print_list(l);

    // Agregar elemento al final
    l = addr(l, 4);
    printf("Lista después de addr: ");
    print_list(l);

    // head y tail
    printf("Head: %d\n", head(l));
    list t = tail(l);
    printf("Tail head: %d\n", head(t));

    // Copiar lista
    list l2 = copy_list(l);
    printf("Copia de la lista: ");
    print_list(l2);

    // Concatenar listas
    list l3 = empty();
    l3 = addl(8, l3);
    l3 = addl(7, l3);
    l3 = addl(6, l3);
    list lcat = concat(l, l3);
    printf("Lista concatenada: ");
    print_list(lcat);

    // take y drop
    list l_take = take(lcat, 4);
    printf("Take 4: ");
    print_list(l_take);

    list l_drop = drop(lcat, 3);
    printf("Drop 3: ");
    print_list(l_drop);

    // Liberar memoria
    destroy(lcat);    // lcat contiene todos los nodos de l y l3
    destroy(l2);      // l2 es una copia profunda
    destroy(l_take);  // l_take es una copia profunda
    // No destruir l, l3, l_drop ni t, porque sus nodos ya están en lcat o l_take

    return 0;
}