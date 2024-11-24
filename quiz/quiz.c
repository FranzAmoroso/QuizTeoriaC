#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ask.h"



// Funzione per iniziare il quiz
void iniziaQuiz(Domanda *domande, int numeroDomande);

// Funzione per visualizzare i risultati
void visualizzaRisultati(int punteggio, int numeroDomande);


int main() {
    int scelta, punteggio = 0, numeroDomande = 0;
    int livello = 1;
    Domanda domande[50]; // Supporto per massimo 50 domande

    // Caricare le domande (placeholder per la funzione di caricamento)
    caricaDomande(domande, &numeroDomande, livello);

    do {
        printf("\n--- QUIZ DI SIMULAZIONE ---\t\t\033[31mUsername: A.Franz\033[0m\n");
        printf("1. Inizia il quiz\t\t\t\033[34mCapitolo scelto: %d\033[0m\n", livello);
        printf("2. Cambia livello di difficoltà\t\t\033[36mLivello di Difficoltà impostato: %d\033[0m\n", livello);
        printf("3. Visualizza risultati\n");
        printf("4. Esci\n");
        printf("Scegli un'opzione: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                punteggio = 0; // Resetta il punteggio
                iniziaQuiz(domande, numeroDomande);
                break;
            case 2:
                printf("Scegli il livello (1 - 6): ");
                scanf("%d", &livello);
                while (livello != 1 && livello != 2 && livello != 3 && livello != 4 && livello != 5 && livello != 6){
                    printf("\033[31mScegli il livello da 1 a 6\033[0m:: ");
                    scanf("%d", &livello);
                }
                caricaDomande(domande, &numeroDomande, livello);
                break;
            case 3:
                visualizzaRisultati(punteggio, numeroDomande);
                break;
            case 4:
                printf("Grazie per aver partecipato al quiz. Alla prossima!\n");
                break;
            default:
                printf("Opzione non valida. Riprova.\n");
                break;
        }
    } while (scelta != 4);

    return 0;
}

// Implementazione placeholder
void iniziaQuiz(Domanda *domande, int numeroDomande) {
    char risposta;
    int punteggio = 0;

    printf("\n--- INIZIO DEL QUIZ ---\n");

    for (int i = 0; i < numeroDomande; i++) {
        printf("\nDomanda %d: %s\n", i + 1, domande[i].domanda);
        printf("a) %s\n", domande[i].opzioni[0]);
        printf("b) %s\n", domande[i].opzioni[1]);
        printf("c) %s\n", domande[i].opzioni[2]);
        printf("d) %s\n", domande[i].opzioni[3]);
        printf("Risposta: ");
        scanf(" %c", &risposta);

        // Verifica della risposta
        if (risposta == domande[i].rispostaCorretta) {
            printf("Corretto!\n");
            punteggio++;
        } else {
            printf("Risposta sbagliata! La risposta corretta era '%c'.\n", domande[i].rispostaCorretta);
        }
    }

    printf("\nHai completato il quiz! Il tuo punteggio è: %d/%d\n", punteggio, numeroDomande);
}

void visualizzaRisultati(int punteggio, int numeroDomande) {
    printf("Hai ottenuto %d/%d punti!\n", punteggio, numeroDomande);
}




