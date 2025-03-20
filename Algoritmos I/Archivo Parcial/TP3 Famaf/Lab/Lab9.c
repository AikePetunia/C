#include <stdio.h>

int main() {
    int i, s; 
    printf("Ingrese un valor para i:\n");
    scanf("%d", &i);
    printf("ingrese un valor para s: \n ");
    scanf("%d", &s);
    int numbers[] = {2, 10, 10, -1};
    i, s == 0;

    do {
    s, i == s + numbers[i], i + 1; 
    } while ( i < 4 );
    
    int j, c;
    printf("Ingrese un valor para i:\n");
    scanf("%d", &j);
    printf("ingrese un valor para s: \n ");
    scanf("%d", &c);
    j, c == 0;
    int numbers2[] = {12, -9, 10, -1};

    do {

        if (numbers2[j] > 0)
        {
            c++;
        }
        
        if (numbers2[j] <= 0) {
            break;
        }
        
        j = j + 1;
    } while (j < 4);
    return 0;
}

//Me genera duda si cuando da los estados de o1, o2, y asi hay que hacer un printf