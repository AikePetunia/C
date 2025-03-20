#include <stdio.h>
#include <ctype.h>

int main () {
    
    char questions[][100] = {
        "1. ¿Qué día hice esto?", 
        "2. ¿Qué serie estoy viendo?", 
        "3. ¿Por qué hago esto?"
    };

    char options[][100] = {
        "A. Un Sábado", "B. Un Viernes", "C. Un Lunes", "D. Un Maxviernes",
        "A. Breaking Bad", "B. One Piece", "C. Mr Robot", "D. The Boys",
        "A. Porq quiero adelantar", "B. Porque me gusta hacer esto", "C. Porque mi gato me dijo hacerlo", "D. Porque quiero hacer cosas"
    };

    char answers[] = {'A', 'D', 'A'};

    int numberOFQuestions = sizeof(questions) / sizeof(questions[0]);

    char guess;
    int score = 0; 

    printf("\n*/*/*/*/*/*/*/*/*\n");
    printf("¡Adivina!\n");
    printf("\n*/*/*/*/*/*/*/*/*\n");

    for (int i = 0; i < numberOFQuestions; i++) 
    {
        printf("%s\n", questions[i]);
        for (int j = (i * 4); j < (i * 4) + 4; j++) 
        {
            printf("%s\n", options[j]);
        }
        
        printf("Adivina: ");
        scanf(" %c", &guess); 
        guess = toupper(guess);

        if (guess == answers[i]) {
            printf("CRACK\n");
            score++;
        } else {
            printf("NO\n");
        }
    }

    printf("\nPuntuacion: %d/%d\n", score, numberOFQuestions);
    
    return 0;
}
