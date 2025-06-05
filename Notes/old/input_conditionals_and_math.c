#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {

    /* Arreglos, Arrays
    Los arreglos (arrays en inglés) permiten almacenar vectores y matrices. 
    Los arreglos unidimensionales sirven para representar vectores 
    Los arreglos bidimensionales para matrices de dos dimensiones.

    Cuándo se utilizan:
    Es un tipo abstracto de datos que es adecuado para situaciones en las que el acceso a los datos se realice de forma aleatoria e impredecible.
    En caso contrario, cuando los elementos pueden estar ordenados y se va a utilizar acceso secuencial sería más adecuado utilizar una lista.
    Se pueden representar matrices n-dimensionales.

    Declaracion de arreglos:

    Para declarar un arreglo en el lenguaje "C" se utiliza la siguiente instrucción:

    int a[5];

    NOTA: esta instrucción declara un arreglo de 5 elementos con índices de 0 a 4 .

    Para inicializarlos:

    Para inicializar o asignarle valor al segundo elemento del arreglo definido previamente se utiliza la siguiente instrucción:

    a[1] = 10;

    Lectura:

    Para leer el segundo elemento del arreglo definido previamente se utiliza la siguiente instrucción:

    x = a[1];

    */
    
    //User inputs 

    char name[25]; //se limita por cuestion de overflow 
    int age1; 

    printf("como te llamas?\n");
    //scanf("%saike\n", &name);
    
    //fgets(name, 25, stdin);                 //<- Asi se evitan los espacio blancos en inputs, pero te lo agrega al final, para evitarlo mira abajo
    //name[strlen(name)-1] = '\0';            // asi se evita
    
    printf("edad?\n");
    //scanf("%d\n", &age);

    printf("\nHola %s, como va?", name);
    printf("\nTienes %d años de edad", age1);


    // Mas matematicas 

    // con #include <math.h> se desbloquean cosas como:

    double A = sqrt(25);                // raiz cuadrada
    double B = pow (3, 4);             //Potencias, primero el num, despues la potencia
    int C = round (3.15);               //redondea el numero 
    int D = ceil (3.14);                 //redondea el numero pa arriba
    int E = floor (3.99);               //redondea el numero pa abajo
    double F = fabs (-41);                 // Valor absoluto
    double G = log(3);                      //logaritmos
    double H = sin (45);                    //seno
    double I = cos (45);                    //cos
    double J = tan (45);                    //tangente

    printf("\n%lf", A);


    //Ejercicio: calcular la circunferencia de un circulo

    const double pi = 3.14159;
    double radius;
    double circumference;
    double area;

    printf("\n Entra el radio del circulo");
   // scanf("%lf", &radius);

    circumference = 2 * pi * radius;
    area = pi * radius * radius;

    printf("circumference: %lf \ny su Area: %lf", circumference, area);


    // el maldito IF

    int age;
    printf("\nwhat's your age\n");
    scanf("%d", &age);

    if (age > 18) {
        printf("si estas permitido en ver este contenido");
    }
    else if (age == 18) {
        printf ("Estas de suerte, justo tenes 18");
    }
    else if (age <= 0) {
        printf ("no has nacido crack");
    }
    else {
        printf("Estas joven aun");
    }

    //el padre del if: switch statments

    int nota;
    printf("\n pone la nota:");
    scanf("%d\n", &nota);   //almacena el dato en la nota

    switch (nota) {
        case 1 : 
            printf("estas flojo");
            break;
        case 2 : 
            printf("estas flojo");
            break;
        case 8 :
            printf("muy bien");
            break;                              //el break va para que no se pase al default. "no habra descansos de ejecucion"
        case 10 :
            printf ("excelente!!");
            break;
        default:
            print("tengo 4 notas xD");
    }


    
    return 0;
}