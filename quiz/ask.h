#ifndef ASK_H
#define ASK_H

#include <stdio.h>
#include <string.h>

typedef struct {
    char domanda[256];
    char opzioni[4][128];
    char rispostaCorretta;
} Domanda;

void caricaDomande(Domanda *domande, int *numeroDomande, int livello);

#endif // ASK_H
