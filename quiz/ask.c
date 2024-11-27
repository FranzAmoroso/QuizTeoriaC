#include "ask.h"
#include <stdlib.h>

// Funzione per mescolare le risposte della domanda
void mischiaRisposte(Domanda *domanda) {
    char mappaturaRisposte[] = {'a', 'b', 'c', 'd'};
    int posizioneCorretta;

    // Trova l'indice della risposta corretta
    for (int i = 0; i < 4; i++) {
        if (domanda->rispostaCorretta == mappaturaRisposte[i]) {
            posizioneCorretta = i;
            break;
        }
    }

    // Mescola le risposte
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;

        // Scambia le opzioni
        char temp[128];
        strcpy(temp, domanda->opzioni[i]);
        strcpy(domanda->opzioni[i], domanda->opzioni[j]);
        strcpy(domanda->opzioni[j], temp);

        // Aggiorna la posizione della risposta corretta
        if (i == posizioneCorretta) {
            posizioneCorretta = j;
        } else if (j == posizioneCorretta) {
            posizioneCorretta = i;
        }
    }

    // Imposta la nuova risposta corretta
    domanda->rispostaCorretta = mappaturaRisposte[posizioneCorretta];
}

// Funzione per mescolare l'ordine delle domande
void mischiaDomande(Domanda *domande, int numeroDomande) {
    for (int i = 0; i < numeroDomande; i++) {
        int j = rand() % numeroDomande;
        Domanda temp = domande[i];
        domande[i] = domande[j];
        domande[j] = temp;
    }
}

void caricaDomande(Domanda *domande, int *numeroDomande, int livello) {
    switch (livello)
    {
    case 1:
        *numeroDomande = 9;

        strcpy(domande[0].domanda, "Qual è la funzione di un `switch` in C?");
        strcpy(domande[0].opzioni[0], "Permette di scegliere un blocco di codice tra più alternative");
        strcpy(domande[0].opzioni[1], "Esegue un ciclo ripetitivo");
        strcpy(domande[0].opzioni[2], "Dichiara una variabile");
        strcpy(domande[0].opzioni[3], "Termina un ciclo");
        domande[0].rispostaCorretta = 'a';

        strcpy(domande[1].domanda, "Come si dichiara una variabile costante in C?");
        strcpy(domande[1].opzioni[0], "const tipo nome;");
        strcpy(domande[1].opzioni[1], "const nome tipo;");
        strcpy(domande[1].opzioni[2], "tipo const nome;");
        strcpy(domande[1].opzioni[3], "nome const tipo;");
        domande[1].rispostaCorretta = 'a';

        strcpy(domande[2].domanda, "Qual è la funzione di un `break` in un ciclo?");
        strcpy(domande[2].opzioni[0], "Termina il ciclo");
        strcpy(domande[2].opzioni[1], "Ignora il ciclo");
        strcpy(domande[2].opzioni[2], "Ripete il ciclo");
        strcpy(domande[2].opzioni[3], "Inizia un nuovo ciclo");
        domande[2].rispostaCorretta = 'a';

        strcpy(domande[3].domanda, "Qual è la funzione di un `continue` in un ciclo?");
        strcpy(domande[3].opzioni[0], "Salta l'iterazione corrente e continua con la successiva");
        strcpy(domande[3].opzioni[1], "Termina il ciclo");
        strcpy(domande[3].opzioni[2], "Ignora il ciclo");
        strcpy(domande[3].opzioni[3], "Inizia un nuovo ciclo");
        domande[3].rispostaCorretta = 'a';

        strcpy(domande[4].domanda, "Come si dichiarano e si inizializzano più variabili in una stessa dichiarazione in C?");
        strcpy(domande[4].opzioni[0], "int a = 5, b = 10;");
        strcpy(domande[4].opzioni[1], "int a, b = 10;");
        strcpy(domande[4].opzioni[2], "a, b int = 5;");
        strcpy(domande[4].opzioni[3], "int a = 5 b = 10;");
        domande[4].rispostaCorretta = 'a';

        strcpy(domande[5].domanda, "Cosa rappresenta l'operatore `%` in C?");
        strcpy(domande[5].opzioni[0], "Il resto della divisione");
        strcpy(domande[5].opzioni[1], "La divisione");
        strcpy(domande[5].opzioni[2], "La moltiplicazione");
        strcpy(domande[5].opzioni[3], "L'addizione");
        domande[5].rispostaCorretta = 'a';

        strcpy(domande[6].domanda, "Qual è l'operatore utilizzato per il confronto di uguaglianza in C?");
        strcpy(domande[6].opzioni[0], "==");
        strcpy(domande[6].opzioni[1], "=");
        strcpy(domande[6].opzioni[2], "!=");
        strcpy(domande[6].opzioni[3], ">");
        domande[6].rispostaCorretta = 'a';

        strcpy(domande[7].domanda, "Cosa si intende per overflow in C?");
        strcpy(domande[7].opzioni[0], "Quando il valore di una variabile supera il suo massimo valore rappresentabile");
        strcpy(domande[7].opzioni[1], "Quando una variabile è nulla");
        strcpy(domande[7].opzioni[2], "Quando una variabile è di tipo errato");
        strcpy(domande[7].opzioni[3], "Quando una variabile ha un valore inferiore al minimo rappresentabile");
        domande[7].rispostaCorretta = 'a';

        strcpy(domande[8].domanda, "Cosa si intende per underflow in C?");
        strcpy(domande[8].opzioni[0], "Quando il valore di una variabile è inferiore al suo minimo rappresentabile");
        strcpy(domande[8].opzioni[1], "Quando una variabile supera il suo massimo valore rappresentabile");
        strcpy(domande[8].opzioni[2], "Quando una variabile è nulla");
        strcpy(domande[8].opzioni[3], "Quando una variabile è di tipo errato");
        domande[8].rispostaCorretta = 'a';

        strcpy(domande[26].domanda, "Quale funzione in C permette di leggere una stringa da input?");
        strcpy(domande[26].opzioni[0], "scanf()");
        strcpy(domande[26].opzioni[1], "gets()");
        strcpy(domande[26].opzioni[2], "fgets()");
        strcpy(domande[26].opzioni[3], "read()");
        domande[26].rispostaCorretta = 'c';
        break;

    case 2:
        *numeroDomande = 35;

        strcpy(domande[0].domanda, "Qual è il risultato della funzione ceil(-9.8) in C?");
        strcpy(domande[0].opzioni[0], "-9.0");
        strcpy(domande[0].opzioni[1], "9.0");
        strcpy(domande[0].opzioni[2], "-10.0");
        strcpy(domande[0].opzioni[3], "10.0");
        domande[0].rispostaCorretta = 'a';

        strcpy(domande[1].domanda, "Qual è il risultato della funzione floor(9.2) in C?");
        strcpy(domande[1].opzioni[0], "10.0");
        strcpy(domande[1].opzioni[1], "9.0");
        strcpy(domande[1].opzioni[2], "0.0");
        strcpy(domande[1].opzioni[3], "8.0");
        domande[1].rispostaCorretta = 'b';

        strcpy(domande[2].domanda, "Qual è il risultato della funzione pow(2, 7) in C?");
        strcpy(domande[2].opzioni[0], "16.0");
        strcpy(domande[2].opzioni[1], "64.0");
        strcpy(domande[2].opzioni[2], "128.0");
        strcpy(domande[2].opzioni[3], "256.0");
        domande[2].rispostaCorretta = 'c';

        strcpy(domande[3].domanda, "Qual è il risultato della funzione fmod(13.657, 2.333) in C?");
        strcpy(domande[3].opzioni[0], "13.657");
        strcpy(domande[3].opzioni[1], "1.992");
        strcpy(domande[3].opzioni[2], "10.0");
        strcpy(domande[3].opzioni[3], "2.333");
        domande[3].rispostaCorretta = 'b';

        strcpy(domande[4].domanda, "Qual è il risultato della funzione sin(0.0) in C?");
        strcpy(domande[4].opzioni[0], "1.0");
        strcpy(domande[4].opzioni[1], "0.0");
        strcpy(domande[4].opzioni[2], "-1.0");
        strcpy(domande[4].opzioni[3], "2.0");
        domande[4].rispostaCorretta = 'b';

        strcpy(domande[5].domanda, "Qual è il risultato della funzione cos(0.0) in C?");
        strcpy(domande[5].opzioni[0], "0.0");
        strcpy(domande[5].opzioni[1], "1.0");
        strcpy(domande[5].opzioni[2], "-1.0");
        strcpy(domande[5].opzioni[3], "2.0");
        domande[5].rispostaCorretta = 'b';

        strcpy(domande[6].domanda, "Qual è il risultato della funzione tan(0.0) in C?");
        strcpy(domande[6].opzioni[0], "0.0");
        strcpy(domande[6].opzioni[1], "1.0");
        strcpy(domande[6].opzioni[2], "-1.0");
        strcpy(domande[6].opzioni[3], "2.0");
        domande[6].rispostaCorretta = 'a';

        strcpy(domande[7].domanda, "Quale specificatore di formato è utilizzato per stampare un valore di tipo long double in C con printf?");
        strcpy(domande[7].opzioni[0], "%f");
        strcpy(domande[7].opzioni[1], "%lf");
        strcpy(domande[7].opzioni[2], "%Lf");
        strcpy(domande[7].opzioni[3], "%ld");
        domande[7].rispostaCorretta = 'c';

        strcpy(domande[8].domanda, "Quale specificatore di formato è utilizzato per leggere un valore di tipo float con scanf?");
        strcpy(domande[8].opzioni[0], "%f");
        strcpy(domande[8].opzioni[1], "%lf");
        strcpy(domande[8].opzioni[2], "%Lf");
        strcpy(domande[8].opzioni[3], "%d");
        domande[8].rispostaCorretta = 'a';

        strcpy(domande[9].domanda, "Quale specificatore di formato è utilizzato per leggere un valore di tipo double con scanf?");
        strcpy(domande[9].opzioni[0], "%f");
        strcpy(domande[9].opzioni[1], "%lf");
        strcpy(domande[9].opzioni[2], "%Lf");
        strcpy(domande[9].opzioni[3], "%u");
        domande[9].rispostaCorretta = 'b';

        strcpy(domande[10].domanda, "Quale specificatore di formato è utilizzato per stampare un valore di tipo unsigned long long int con printf?");
        strcpy(domande[10].opzioni[0], "%llu");
        strcpy(domande[10].opzioni[1], "%ld");
        strcpy(domande[10].opzioni[2], "%lu");
        strcpy(domande[10].opzioni[3], "%lld");
        domande[10].rispostaCorretta = 'a';

        strcpy(domande[11].domanda, "Quale specificatore di formato è utilizzato per stampare un valore di tipo long long int con printf?");
        strcpy(domande[11].opzioni[0], "%llu");
        strcpy(domande[11].opzioni[1], "%ld");
        strcpy(domande[11].opzioni[2], "%lu");
        strcpy(domande[11].opzioni[3], "%lld");
        domande[11].rispostaCorretta = 'd';

        strcpy(domande[12].domanda, "Quale specificatore di formato è utilizzato per stampare un valore di tipo unsigned int con printf?");
        strcpy(domande[12].opzioni[0], "%u");
        strcpy(domande[12].opzioni[1], "%d");
        strcpy(domande[12].opzioni[2], "%ld");
        strcpy(domande[12].opzioni[3], "%f");
        domande[12].rispostaCorretta = 'a';

        strcpy(domande[13].domanda, "Quale specificatore di formato è utilizzato per leggere un valore di tipo int con scanf?");
        strcpy(domande[13].opzioni[0], "%d");
        strcpy(domande[13].opzioni[1], "%u");
        strcpy(domande[13].opzioni[2], "%f");
        strcpy(domande[13].opzioni[3], "%c");
        domande[13].rispostaCorretta = 'a';

        strcpy(domande[14].domanda, "Quale specificatore di formato è utilizzato per leggere un valore di tipo short con scanf?");
        strcpy(domande[14].opzioni[0], "%d");
        strcpy(domande[14].opzioni[1], "%hd");
        strcpy(domande[14].opzioni[2], "%hu");
        strcpy(domande[14].opzioni[3], "%ld");
        domande[14].rispostaCorretta = 'b';

        strcpy(domande[15].domanda, "Quale specificatore di formato è utilizzato per stampare un valore di tipo char con printf?");
        strcpy(domande[15].opzioni[0], "%c");
        strcpy(domande[15].opzioni[1], "%s");
        strcpy(domande[15].opzioni[2], "%d");
        strcpy(domande[15].opzioni[3], "%u");
        domande[15].rispostaCorretta = 'a';

        strcpy(domande[16].domanda, "Quale specificatore di formato è utilizzato per stampare un valore di tipo unsigned short con printf?");
        strcpy(domande[16].opzioni[0], "%hu");
        strcpy(domande[16].opzioni[1], "%hd");
        strcpy(domande[16].opzioni[2], "%u");
        strcpy(domande[16].opzioni[3], "%d");
        domande[16].rispostaCorretta = 'a';

        strcpy(domande[17].domanda, "Quale specificatore di formato è utilizzato per leggere un valore di tipo unsigned long int con scanf?");
        strcpy(domande[17].opzioni[0], "%u");
        strcpy(domande[17].opzioni[1], "%lu");
        strcpy(domande[17].opzioni[2], "%lld");
        strcpy(domande[17].opzioni[3], "%llu");
        domande[17].rispostaCorretta = 'b';

        strcpy(domande[18].domanda, "Quale specificatore di formato è utilizzato per stampare un valore di tipo long int con printf?");
        strcpy(domande[18].opzioni[0], "%ld");
        strcpy(domande[18].opzioni[1], "%lu");
        strcpy(domande[18].opzioni[2], "%lld");
        strcpy(domande[18].opzioni[3], "%u");
        domande[18].rispostaCorretta = 'a';

        strcpy(domande[19].domanda, "Quale specificatore di formato è utilizzato per stampare un valore di tipo double con printf?");
        strcpy(domande[19].opzioni[0], "%f");
        strcpy(domande[19].opzioni[1], "%lf");
        strcpy(domande[19].opzioni[2], "%Lf");
        strcpy(domande[19].opzioni[3], "%d");
        domande[19].rispostaCorretta = 'b';

        strcpy(domande[19].domanda, "Quale specificatore di formato è utilizzato per stampare un valore di tipo float con printf?");
        strcpy(domande[19].opzioni[0], "%f");
        strcpy(domande[19].opzioni[1], "%lf");
        strcpy(domande[19].opzioni[2], "%Lf");
        strcpy(domande[19].opzioni[3], "%d");
        domande[19].rispostaCorretta = 'a';

        strcpy(domande[20].domanda, "Quale specificatore di formato è utilizzato per stampare un valore di tipo long long int in formato esadecimale con printf?");
        strcpy(domande[20].opzioni[0], "%x");
        strcpy(domande[20].opzioni[1], "%llu");
        strcpy(domande[20].opzioni[2], "%lld");
        strcpy(domande[20].opzioni[3], "%lX");
        domande[20].rispostaCorretta = 'c';

        strcpy(domande[21].domanda, "Quale header file contiene informazioni per aggiungere istruzioni di diagnostica per il debugging?");
        strcpy(domande[21].opzioni[0], "<assert.h>");
        strcpy(domande[21].opzioni[1], "<ctype.h>");
        strcpy(domande[21].opzioni[2], "<errno.h>");
        strcpy(domande[21].opzioni[3], "<limits.h>");
        domande[21].rispostaCorretta = 'a';

        strcpy(domande[22].domanda, "Quale header file fornisce funzioni per convertire lettere minuscole in lettere maiuscole e viceversa?");
        strcpy(domande[22].opzioni[0], "<assert.h>");
        strcpy(domande[22].opzioni[1], "<ctype.h>");
        strcpy(domande[22].opzioni[2], "<locale.h>");
        strcpy(domande[22].opzioni[3], "<stdio.h>");
        domande[22].rispostaCorretta = 'b';

        strcpy(domande[23].domanda, "Quale header file definisce le macro per segnalare condizioni di errore?");
        strcpy(domande[23].opzioni[0], "<assert.h>");
        strcpy(domande[23].opzioni[1], "<errno.h>");
        strcpy(domande[23].opzioni[2], "<math.h>");
        strcpy(domande[23].opzioni[3], "<time.h>");
        domande[23].rispostaCorretta = 'b';

        strcpy(domande[24].domanda, "Quale header file contiene i limiti per i valori in virgola mobile del sistema?");
        strcpy(domande[24].opzioni[0], "<limits.h>");
        strcpy(domande[24].opzioni[1], "<math.h>");
        strcpy(domande[24].opzioni[2], "<float.h>");
        strcpy(domande[24].opzioni[3], "<stdlib.h>");
        domande[24].rispostaCorretta = 'c';

        strcpy(domande[25].domanda, "Quale header file fornisce i limiti per i valori interi del sistema?");
        strcpy(domande[25].opzioni[0], "<limits.h>");
        strcpy(domande[25].opzioni[1], "<errno.h>");
        strcpy(domande[25].opzioni[2], "<math.h>");
        strcpy(domande[25].opzioni[3], "<stdio.h>");
        domande[25].rispostaCorretta = 'a';

        strcpy(domande[26].domanda, "Quale header file consente di modificare il programma per l’ambiente locale nel quale viene eseguito?");
        strcpy(domande[26].opzioni[0], "<math.h>");
        strcpy(domande[26].opzioni[1], "<locale.h>");
        strcpy(domande[26].opzioni[2], "<setjmp.h>");
        strcpy(domande[26].opzioni[3], "<string.h>");
        domande[26].rispostaCorretta = 'b';

        strcpy(domande[27].domanda, "Quale header file fornisce i prototipi di funzione per le funzioni della libreria matematica?");
        strcpy(domande[27].opzioni[0], "<math.h>");
        strcpy(domande[27].opzioni[1], "<stdlib.h>");
        strcpy(domande[27].opzioni[2], "<stdio.h>");
        strcpy(domande[27].opzioni[3], "<ctype.h>");
        domande[27].rispostaCorretta = 'a';

        strcpy(domande[28].domanda, "Quale header file contiene i prototipi di funzione per gestire situazioni che possono insorgere durante l’esecuzione di un programma?");
        strcpy(domande[28].opzioni[0], "<signal.h>");
        strcpy(domande[28].opzioni[1], "<stdlib.h>");
        strcpy(domande[28].opzioni[2], "<assert.h>");
        strcpy(domande[28].opzioni[3], "<stdio.h>");
        domande[28].rispostaCorretta = 'a';

        strcpy(domande[29].domanda, "Quale header file contiene le macro per trattare liste di argomenti per una funzione, il cui numero e i cui tipi non sono noti a priori?");
        strcpy(domande[29].opzioni[0], "<stdarg.h>");
        strcpy(domande[29].opzioni[1], "<errno.h>");
        strcpy(domande[29].opzioni[2], "<stdlib.h>");
        strcpy(domande[29].opzioni[3], "<stdio.h>");
        domande[29].rispostaCorretta = 'a';

        strcpy(domande[30].domanda, "Quale header file contiene le definizioni di tipo comunemente usate dal C per effettuare calcoli?");
        strcpy(domande[30].opzioni[0], "<stddef.h>");
        strcpy(domande[30].opzioni[1], "<stdlib.h>");
        strcpy(domande[30].opzioni[2], "<signal.h>");
        strcpy(domande[30].opzioni[3], "<stdio.h>");
        domande[30].rispostaCorretta = 'a';

        strcpy(domande[31].domanda, "Quale header file contiene i prototipi di funzione per le funzioni della Libreria Standard di input/output?");
        strcpy(domande[31].opzioni[0], "<stdio.h>");
        strcpy(domande[31].opzioni[1], "<math.h>");
        strcpy(domande[31].opzioni[2], "<ctype.h>");
        strcpy(domande[31].opzioni[3], "<stdlib.h>");
        domande[31].rispostaCorretta = 'a';

        strcpy(domande[32].domanda, "Quale header file contiene i prototipi di funzione per convertire numeri in testo e testo in numeri?");
        strcpy(domande[32].opzioni[0], "<stdlib.h>");
        strcpy(domande[32].opzioni[1], "<stdio.h>");
        strcpy(domande[32].opzioni[2], "<string.h>");
        strcpy(domande[32].opzioni[3], "<ctype.h>");
        domande[32].rispostaCorretta = 'a';

        strcpy(domande[33].domanda, "Quale header file contiene i prototipi di funzione per le funzioni di elaborazione di stringhe?");
        strcpy(domande[33].opzioni[0], "<string.h>");
        strcpy(domande[33].opzioni[1], "<stdio.h>");
        strcpy(domande[33].opzioni[2], "<stdlib.h>");
        strcpy(domande[33].opzioni[3], "<signal.h>");
        domande[33].rispostaCorretta = 'a';

        strcpy(domande[34].domanda, "Quale header file contiene i prototipi di funzione e i tipi per manipolare il tempo e le date?");
        strcpy(domande[34].opzioni[0], "<time.h>");
        strcpy(domande[34].opzioni[1], "<stdio.h>");
        strcpy(domande[34].opzioni[2], "<math.h>");
        strcpy(domande[34].opzioni[3], "<stdlib.h>");
        domande[34].rispostaCorretta = 'a';
        break;
    
    case 3:
        *numeroDomande = 17; // Numero corretto di domande

        // Domanda 1
        strcpy(domande[0].domanda, "Una procedura per risolvere un problema in termini di azioni da eseguire e dell’ordine in cui tali azioni vanno eseguite è chiamata __________");
        strcpy(domande[0].opzioni[0], "Algoritmo");
        strcpy(domande[0].opzioni[1], "Funzioni");
        strcpy(domande[0].opzioni[2], "Cicli");
        strcpy(domande[0].opzioni[3], "Costanti");
        domande[0].rispostaCorretta = 'a';

        // Domanda 2
        strcpy(domande[1].domanda, "Specificare l’ordine in cui le istruzioni vanno eseguite nel programma di un computer si dice__");
        strcpy(domande[1].opzioni[0], "Itelazione");
        strcpy(domande[1].opzioni[1], "Controllo del programma");
        strcpy(domande[1].opzioni[2], "Algoritmo");
        strcpy(domande[1].opzioni[3], "Processo");
        domande[1].rispostaCorretta = 'b';

        // Domanda 3
        strcpy(domande[2].domanda, "Lo pseudocodice consiste solamente in istruzioni di?");
        strcpy(domande[2].opzioni[0], "Azione e Decisione");
        strcpy(domande[2].opzioni[1], "Carta e Penna");
        strcpy(domande[2].opzioni[2], "Dirette e Indirette");
        strcpy(domande[2].opzioni[3], "Aiuto");
        domande[2].rispostaCorretta = 'a';

        // Domanda 4
        strcpy(domande[3].domanda, "In cosa consiste lo pseudocodice?");
        strcpy(domande[3].opzioni[0], "Una descrizione passo-passo");
        strcpy(domande[3].opzioni[1], "Un programma eseguibile");
        strcpy(domande[3].opzioni[2], "Uno strumento grafico");
        strcpy(domande[3].opzioni[3], "Aiutare il programmatore a pensare");
        domande[3].rispostaCorretta = 'd';

        // Domanda 5
        strcpy(domande[4].domanda, "In un diagramma di flusso di un algoritmo, qual è la forma dei simboli di decisione?");
        strcpy(domande[4].opzioni[0], "Rombo");
        strcpy(domande[4].opzioni[1], "Rettangolo");
        strcpy(domande[4].opzioni[2], "Cerchio");
        strcpy(domande[4].opzioni[3], "Parallelogramma");
        domande[4].rispostaCorretta = 'a';

        // Domanda 6
        strcpy(domande[5].domanda, "In un diagramma di flusso di un algoritmo, qual è la forma dei simboli di azione?");
        strcpy(domande[5].opzioni[0], "Parallelogramma");
        strcpy(domande[5].opzioni[1], "Rombo");
        strcpy(domande[5].opzioni[2], "Cerchio");
        strcpy(domande[5].opzioni[3], "Rettangolo");
        domande[5].rispostaCorretta = 'd';

        // Domanda 7
        strcpy(domande[6].domanda, "In un diagramma di flusso di un algoritmo, qual è la forma dei simboli di connettori?");
        strcpy(domande[6].opzioni[0], "Cerchio");
        strcpy(domande[6].opzioni[1], "Rettangolo arrotondato");
        strcpy(domande[6].opzioni[2], "cerchietto");
        strcpy(domande[6].opzioni[3], "Parallelogramma");
        domande[6].rispostaCorretta = 'c';

        // Domanda 8
        strcpy(domande[7].domanda, "Tutti i programmi si possono scrivere in termini dei tre tipi di istruzioni di controllo:__________, __________ e __________.");
        strcpy(domande[7].opzioni[0], "Iterazione, selezione e sequenza.");
        strcpy(domande[7].opzioni[1], "Sequenza, selezione, iterazione.");
        strcpy(domande[7].opzioni[2], "Selezione, iterazione e sequenza.");
        strcpy(domande[7].opzioni[3], "Sequenza, iterazione e selezione.");
        domande[7].rispostaCorretta = 'b';

        // Domanda 9
        strcpy(domande[8].domanda, "L’istruzione di selezione __________ è usata per eseguire un’azione quando una condizione è vera e un’altra azione quando la condizione è falsa.");
        strcpy(domande[8].opzioni[0], "if...else");
        strcpy(domande[8].opzioni[1], "while");
        strcpy(domande[8].opzioni[2], "for");
        strcpy(domande[8].opzioni[3], "switch");
        domande[8].rispostaCorretta = 'a';

        // Domanda 10
        strcpy(domande[9].domanda, "Varie istruzioni raggruppate insieme tra parentesi graffe ({ e }) sono chiamate __________.");
        strcpy(domande[9].opzioni[0], "Strutture");
        strcpy(domande[9].opzioni[1], "Funzioni");
        strcpy(domande[9].opzioni[2], "Array");
        strcpy(domande[9].opzioni[3], "Istruzione composta o blocco");
        domande[9].rispostaCorretta = 'd';

        // Domanda 11
        strcpy(domande[10].domanda, "L’istruzione di iterazione __________ specifica che un’istruzione o un gruppo di istruzioni vanno eseguiti ripetutamente finché una qualche condizione rimane vera.");
        strcpy(domande[10].opzioni[0], "while");
        strcpy(domande[10].opzioni[1], "for");
        strcpy(domande[10].opzioni[2], "if...else");
        strcpy(domande[10].opzioni[3], "switch");
        domande[10].rispostaCorretta = 'a';

        // Domanda 12
        strcpy(domande[11].domanda, "L’iterazione di un insieme di istruzioni un numero specifico di volte è chiamata iterazione __________.");
        strcpy(domande[11].opzioni[0], "while");
        strcpy(domande[11].opzioni[1], "for");
        strcpy(domande[11].opzioni[2], "Controllata da contatore o definita");
        strcpy(domande[11].opzioni[3], "if...else");
        domande[11].rispostaCorretta = 'c';

        // Domanda 13
        strcpy(domande[12].domanda, "Quando non si sa in anticipo quante volte sarà ripetuto un insieme di istruzioni si può usare un valore __________ per terminare l’iterazione.");
        strcpy(domande[12].opzioni[0], "Continue");
        strcpy(domande[12].opzioni[1], "Break");
        strcpy(domande[12].opzioni[2], "Sentinella");
        strcpy(domande[12].opzioni[3], "Exit");
        domande[12].rispostaCorretta = 'c';
        
        // Domanda 14
        strcpy(domande[13].domanda, "L’esperienza ha dimostrato che la parte più difficile della risoluzione di un problema su un computer è quella di produrre un programma in C funzionante.");
        strcpy(domande[13].opzioni[0], "Vero");
        strcpy(domande[13].opzioni[1], "Falso");
        domande[13].rispostaCorretta = 'b';

        // Domanda 15
        strcpy(domande[14].domanda, "Un valore sentinella deve essere un valore che non può venire confuso con un valore legittimo dei dati.");
        strcpy(domande[14].opzioni[0], "Vero");
        strcpy(domande[14].opzioni[1], "Falso");
        domande[14].rispostaCorretta = 'a';

        // Domanda 16
        strcpy(domande[15].domanda, "Le linee di flusso indicano le azioni da eseguire.");
        strcpy(domande[15].opzioni[0], "Vero");
        strcpy(domande[15].opzioni[1], "Falso");
        domande[15].rispostaCorretta = 'a';

        // Domanda 17
        strcpy(domande[16].domanda, "Le condizioni scritte dentro i simboli di decisione contengono sempre operatori aritmetici (ossia, +, –, *, / e %).");
        strcpy(domande[16].opzioni[0], "Vero");
        strcpy(domande[16].opzioni[1], "Falso");
        domande[16].rispostaCorretta = 'b';
        break;
    
    case 4:
        *numeroDomande = 11; // Numero corretto di domande

        // Domanda 1
        strcpy(domande[0].domanda, "L’iterazione controllata da contatore è nota anche come iterazione __________ perché si sa in anticipo quante volte il ciclo sarà eseguito.");
        strcpy(domande[0].opzioni[0], "Sentinella");
        strcpy(domande[0].opzioni[1], "Definita");
        strcpy(domande[0].opzioni[2], "Indefinita");
        strcpy(domande[0].opzioni[3], "Ciclica");
        domande[0].rispostaCorretta = 'b';

        // Domanda 2
        strcpy(domande[1].domanda, "L’iterazione controllata da sentinella è nota anche come iterazione __________ perché non si sa in anticipo quante volte sarà eseguito il ciclo.");
        strcpy(domande[1].opzioni[0], "Finita");
        strcpy(domande[1].opzioni[1], "Definita");
        strcpy(domande[1].opzioni[2], "Ciclica");
        strcpy(domande[1].opzioni[3], "Indefinita");
        domande[1].rispostaCorretta = 'd';

        // Domanda 3
        strcpy(domande[2].domanda, "Nell’iterazione controllata da contatore si usa una __________ per contare il numero di volte in cui si deve ripetere un gruppo di istruzioni.");
        strcpy(domande[2].opzioni[0], "Funzione");
        strcpy(domande[2].opzioni[1], "Costante");
        strcpy(domande[2].opzioni[2], "Sentinella");
        strcpy(domande[2].opzioni[3], "Variabile");
        domande[3].rispostaCorretta = 'd';

        // Domanda 4
        strcpy(domande[3].domanda, "L’istruzione __________ , quando è eseguita in un’istruzione di iterazione, fa sì che sia eseguita immediatamente la successiva iterazione del ciclo.");
        strcpy(domande[3].opzioni[0], "Continue");
        strcpy(domande[3].opzioni[1], "Break");
        strcpy(domande[3].opzioni[2], "Exit");
        strcpy(domande[3].opzioni[3], "Return");
        domande[3].rispostaCorretta = 'a';

        // Domanda 5
        strcpy(domande[4].domanda, "L’istruzione __________ , quando è eseguita in un’istruzione di iterazione o in uno switch, provoca un’uscita immediata dall’istruzione.");
        strcpy(domande[4].opzioni[0], "Break");
        strcpy(domande[4].opzioni[1], "Continue");
        strcpy(domande[4].opzioni[2], "Return");
        strcpy(domande[4].opzioni[3], "Exit");
        domande[4].rispostaCorretta = 'a';

        // Domanda 6
        strcpy(domande[5].domanda, "L’__________ è usata per testare una particolare variabile o espressione in relazione a ognuno dei valori costanti interi che può assumere.");
        strcpy(domande[5].opzioni[0], "For");
        strcpy(domande[5].opzioni[1], "If");
        strcpy(domande[5].opzioni[2], "Switch");
        strcpy(domande[5].opzioni[3], "While");
        domande[5].rispostaCorretta = 'a';

        // Domanda 7 (vero/falso)
        strcpy(domande[6].domanda, "Il caso default è necessario nell’istruzione di selezione switch.");
        strcpy(domande[6].opzioni[0], "Vero");
        strcpy(domande[6].opzioni[1], "Falso");
        domande[6].rispostaCorretta = 'b';

        // Domanda 8 (vero/falso)
        strcpy(domande[7].domanda, "L’istruzione break è necessaria nel caso default di un’istruzione di selezione switch.");
        strcpy(domande[7].opzioni[0], "Vero");
        strcpy(domande[7].opzioni[1], "Falso");
        domande[7].rispostaCorretta = 'b';

        // Domanda 9 (vero/falso)
        strcpy(domande[8].domanda, "L’espressione (x > y && a < b) è vera se x > y è vera o se a < b è vera.");
        strcpy(domande[8].opzioni[0], "Vero");
        strcpy(domande[8].opzioni[1], "Falso");
        domande[8].rispostaCorretta = 'b';

        // Domanda 10 (vero/falso)
        strcpy(domande[9].domanda, "Un’espressione contenente l’operatore || è vera se uno o ambedue gli operandi sono veri.");
        strcpy(domande[9].opzioni[0], "Vero");
        strcpy(domande[9].opzioni[1], "Falso");
        domande[9].rispostaCorretta = 'a';

        // Domanda 11
        strcpy(domande[10].domanda, "Nell’affinamento graduale top-down ogni affinamento è una rappresentazione completa dell’algoritmo.");
        strcpy(domande[10].opzioni[0], "Vero");
        strcpy(domande[10].opzioni[1], "Falso");
        domande[10].rispostaCorretta = 'a';
        break;
    
    case 5:
        *numeroDomande = 32; // Numero di domande per il livello 5
        // Domande per il livello 5 

        strcpy(domande[0].domanda, "Per modularizzare i programmi si utilizzano __________.");
        strcpy(domande[0].opzioni[0], "funzioni");
        strcpy(domande[0].opzioni[1], "variabili");
        strcpy(domande[0].opzioni[2], "puntatori");
        strcpy(domande[0].opzioni[3], "strutture");
        domande[0].rispostaCorretta = 'a';

        strcpy(domande[1].domanda, "Una funzione è invocata con una __________.");
        strcpy(domande[1].opzioni[0], "chiamata");
        strcpy(domande[1].opzioni[1], "definizione");
        strcpy(domande[1].opzioni[2], "dichiarazione");
        strcpy(domande[1].opzioni[3], "espressione");
        domande[1].rispostaCorretta = 'a';

        strcpy(domande[2].domanda, "Una variabile che è conosciuta solo all’interno della funzione in cui è definita è chiamata __________.");
        strcpy(domande[2].opzioni[0], "locale");
        strcpy(domande[2].opzioni[1], "globale");
        strcpy(domande[2].opzioni[2], "statica");
        strcpy(domande[2].opzioni[3], "costante");
        domande[2].rispostaCorretta = 'a';

        strcpy(domande[3].domanda, "L’istruzione __________ in una funzione chiamata si usa per restituire il valore di un’espressione alla funzione chiamante.");
        strcpy(domande[3].opzioni[0], "return");
        strcpy(domande[3].opzioni[1], "break");
        strcpy(domande[3].opzioni[2], "continue");
        strcpy(domande[3].opzioni[3], "exit");
        domande[3].rispostaCorretta = 'a';

        strcpy(domande[4].domanda, "La parola chiave __________ si usa nell’intestazione di una funzione per indicare che una funzione non restituisce un valore o che una funzione non contiene parametri.");
        strcpy(domande[4].opzioni[0], "void");
        strcpy(domande[4].opzioni[1], "int");
        strcpy(domande[4].opzioni[2], "char");
        strcpy(domande[4].opzioni[3], "float");
        domande[4].rispostaCorretta = 'a';

        strcpy(domande[5].domanda, "Cosa rappresenta il valore di ritorno di `main()` in C?");
        strcpy(domande[5].opzioni[0], "Il codice di uscita del programma");
        strcpy(domande[5].opzioni[1], "Il risultato dell'esecuzione del programma");
        strcpy(domande[5].opzioni[2], "La quantità di memoria utilizzata");
        strcpy(domande[5].opzioni[3], "Il tempo di esecuzione del programma");
        domande[5].rispostaCorretta = 'a';

        strcpy(domande[6].domanda, "Il __________ di un identificatore è la porzione di programma in cui si può usare l’identificatore.");
        strcpy(domande[6].opzioni[0], "campo d’azione");
        strcpy(domande[6].opzioni[1], "tipo");
        strcpy(domande[6].opzioni[2], "valore");
        strcpy(domande[6].opzioni[3], "nome");
        domande[6].rispostaCorretta = 'a';

        strcpy(domande[7].domanda, "I tre modi di restituire il controllo da una funzione chiamata a una chiamante sono __________, __________ e __________.");
        strcpy(domande[7].opzioni[0], "return, exit, break");
        strcpy(domande[7].opzioni[1], "return, continue, goto");
        strcpy(domande[7].opzioni[2], "break, exit, continue");
        strcpy(domande[7].opzioni[3], "return, break, goto");
        domande[7].rispostaCorretta = 'a';

        strcpy(domande[8].domanda, "Un __________ consente al compilatore di controllare il numero, i tipi e l’ordine degli argomenti passati a una funzione.");
        strcpy(domande[8].opzioni[0], "prototipo");
        strcpy(domande[8].opzioni[1], "parametro");
        strcpy(domande[8].opzioni[2], "identificatore");
        strcpy(domande[8].opzioni[3], "costrutto");
        domande[8].rispostaCorretta = 'a';

        strcpy(domande[9].domanda, "La funzione __________ si usa per produrre numeri casuali.");
        strcpy(domande[9].opzioni[0], "rand()");
        strcpy(domande[9].opzioni[1], "srand()");
        strcpy(domande[9].opzioni[2], "random()");
        strcpy(domande[9].opzioni[3], "randnum()");
        domande[9].rispostaCorretta = 'a';

        strcpy(domande[10].domanda, "La funzione __________ si usa per impostare il seme per i numeri casuali in modo da rendere casuale il programma.");
        strcpy(domande[10].opzioni[0], "srand()");
        strcpy(domande[10].opzioni[1], "rand()");
        strcpy(domande[10].opzioni[2], "seed()");
        strcpy(domande[10].opzioni[3], "randomize()");
        domande[10].rispostaCorretta = 'a';

        strcpy(domande[11].domanda, "Gli specificatori della classe di memoria sono __________, __________, __________ e __________.");
        strcpy(domande[11].opzioni[0], "auto, static, extern, register");
        strcpy(domande[11].opzioni[1], "int, char, float, double");
        strcpy(domande[11].opzioni[2], "extern, const, volatile, inline");
        strcpy(domande[11].opzioni[3], "static, extern, mutable, auto");
        domande[11].rispostaCorretta = 'a';

        strcpy(domande[12].domanda, "Si assume che le variabili dichiarate in un blocco o nella lista dei parametri di una funzione siano della classe di memoria __________, a meno che non sia specificato diversamente.");
        strcpy(domande[12].opzioni[0], "auto");
        strcpy(domande[12].opzioni[1], "register");
        strcpy(domande[12].opzioni[2], "static");
        strcpy(domande[12].opzioni[3], "extern");
        domande[12].rispostaCorretta = 'a';

        strcpy(domande[13].domanda, "Una variabile non-static definita al di fuori di un blocco o di una funzione è una variabile __________.");
        strcpy(domande[13].opzioni[0], "globale");
        strcpy(domande[13].opzioni[1], "locale");
        strcpy(domande[13].opzioni[2], "static");
        strcpy(domande[13].opzioni[3], "const");
        domande[13].rispostaCorretta = 'a';

        strcpy(domande[14].domanda, "Perché una variabile locale in una funzione mantenga il suo valore tra le chiamate alla funzione deve essere dichiarata con lo specificatore della classe di memoria __________.");
        strcpy(domande[14].opzioni[0], "static");
        strcpy(domande[14].opzioni[1], "register");
        strcpy(domande[14].opzioni[2], "extern");
        strcpy(domande[14].opzioni[3], "volatile");
        domande[14].rispostaCorretta = 'a';

        strcpy(domande[15].domanda, "Le quattro possibili estensioni del campo d’azione di un identificatore sono __________, __________, __________ e __________.");
        strcpy(domande[15].opzioni[0], "funzione, file, blocco, prototipo");
        strcpy(domande[15].opzioni[1], "file, funzione, libreria, oggetto");
        strcpy(domande[15].opzioni[2], "funzione, file, global, locale");
        strcpy(domande[15].opzioni[3], "static, extern, register, auto");
        domande[15].rispostaCorretta = 'a';

        strcpy(domande[16].domanda, "Una funzione che chiama se stessa direttamente o indirettamente è una funzione ____________.");
        strcpy(domande[16].opzioni[0], "ricorsiva");
        strcpy(domande[16].opzioni[1], "iterativa");
        strcpy(domande[16].opzioni[2], "dinamica");
        strcpy(domande[16].opzioni[3], "stabile");
        domande[16].rispostaCorretta = 'a';

        strcpy(domande[17].domanda, "Una funzione ricorsiva ha tipicamente due componenti: una che fornisce una modalità perché la ricorsione termini verificando un caso __________ e una che esprime il problema come una chiamata ricorsiva per un problema leggermente più semplice della chiamata originaria.");
        strcpy(domande[17].opzioni[0], "base");
        strcpy(domande[17].opzioni[1], "complesso");
        strcpy(domande[17].opzioni[2], "ciclica");
        strcpy(domande[17].opzioni[3], "invertito");
        domande[17].rispostaCorretta = 'a';

        strcpy(domande[18].domanda, "Qual è il risultato della funzione sqrt(900.0) in C?");
        strcpy(domande[18].opzioni[0], "30.0");
        strcpy(domande[18].opzioni[1], "900.0");
        strcpy(domande[18].opzioni[2], "3.0");
        strcpy(domande[18].opzioni[3], "0.0");
        domande[18].rispostaCorretta = 'a';

        strcpy(domande[19].domanda, "Qual è il risultato della funzione cbrt(-8.0) in C?");
        strcpy(domande[19].opzioni[0], "8.0");
        strcpy(domande[19].opzioni[1], "-2.0");
        strcpy(domande[19].opzioni[2], "0.0");
        strcpy(domande[19].opzioni[3], "2.0");
        domande[19].rispostaCorretta = 'b';

        strcpy(domande[20].domanda, "Qual è il risultato della funzione exp(1.0) in C?");
        strcpy(domande[20].opzioni[0], "1.0");
        strcpy(domande[20].opzioni[1], "2.718282");
        strcpy(domande[20].opzioni[2], "7.389056");
        strcpy(domande[20].opzioni[3], "0.0");
        domande[20].rispostaCorretta = 'b';

        strcpy(domande[21].domanda, "Qual è il risultato della funzione log(2.718282) in C?");
        strcpy(domande[21].opzioni[0], "0.0");
        strcpy(domande[21].opzioni[1], "2.718282");
        strcpy(domande[21].opzioni[2], "1.0");
        strcpy(domande[21].opzioni[3], "7.389056");
        domande[21].rispostaCorretta = 'c';

        strcpy(domande[22].domanda, "Qual è il risultato della funzione log10(100.0) in C?");
        strcpy(domande[22].opzioni[0], "0.0");
        strcpy(domande[22].opzioni[1], "1.0");
        strcpy(domande[22].opzioni[2], "2.0");
        strcpy(domande[22].opzioni[3], "10.0");
        domande[22].rispostaCorretta = 'c';

        strcpy(domande[23].domanda, "Qual è il risultato della funzione fabs(-13.5) in C?");
        strcpy(domande[23].opzioni[0], "13.5");
        strcpy(domande[23].opzioni[1], "-13.5");
        strcpy(domande[23].opzioni[2], "0.0");
        strcpy(domande[23].opzioni[3], "1.0");
        domande[23].rispostaCorretta = 'a';

        strcpy(domande[24].domanda, "Come si dichiara una struttura in C?");
        strcpy(domande[24].opzioni[0], "struct nome { ... };");
        strcpy(domande[24].opzioni[1], "struct { ... } nome;");
        strcpy(domande[24].opzioni[2], "nome struct { ... };");
        strcpy(domande[24].opzioni[3], "struct(nome) { ... };");
        domande[24].rispostaCorretta = 'a';

        strcpy(domande[25].domanda, "Come si passano gli argomenti a una funzione in C?");
        strcpy(domande[25].opzioni[0], "Per valore o per riferimento");
        strcpy(domande[25].opzioni[1], "Solo per valore");
        strcpy(domande[25].opzioni[2], "Solo per riferimento");
        strcpy(domande[25].opzioni[3], "Non è possibile passare argomenti");
        domande[25].rispostaCorretta = 'a';

        strcpy(domande[26].domanda, "Cosa fa la funzione `sizeof()` in C?");
        strcpy(domande[26].opzioni[0], "Restituisce la dimensione di un tipo o di una variabile");
        strcpy(domande[26].opzioni[1], "Alloca memoria dinamica");
        strcpy(domande[26].opzioni[2], "Inizializza una variabile");
        strcpy(domande[26].opzioni[3], "Restituisce la lunghezza di una stringa");
        domande[26].rispostaCorretta = 'a';

        strcpy(domande[27].domanda, "Cosa restituisce la funzione `atoi()` in C?");
        strcpy(domande[27].opzioni[0], "Converte una stringa in un intero");
        strcpy(domande[27].opzioni[1], "Converte una stringa in un float");
        strcpy(domande[27].opzioni[2], "Converte un intero in una stringa");
        strcpy(domande[27].opzioni[3], "Converte un intero in un carattere");
        domande[27].rispostaCorretta = 'a';


        strcpy(domande[28].domanda, "Cosa fa la funzione `exit()` in C?");
        strcpy(domande[28].opzioni[0], "Termina il programma");
        strcpy(domande[28].opzioni[1], "Esce da un ciclo");
        strcpy(domande[28].opzioni[2], "Restituisce un valore");
        strcpy(domande[28].opzioni[3], "Non fa nulla");
        domande[28].rispostaCorretta = 'a';

        strcpy(domande[29].domanda, "Come si crea una funzione ricorsiva in C?");
        strcpy(domande[29].opzioni[0], "Una funzione che chiama se stessa");
        strcpy(domande[29].opzioni[1], "Una funzione che chiama una funzione diversa");
        strcpy(domande[29].opzioni[2], "Una funzione che non ritorna mai");
        strcpy(domande[29].opzioni[3], "Una funzione che restituisce sempre lo stesso valore");
        domande[29].rispostaCorretta = 'a';

        strcpy(domande[30].domanda, "Come si dichiara una variabile globale in C?");
        strcpy(domande[30].opzioni[0], "Fuori da tutte le funzioni");
        strcpy(domande[30].opzioni[1], "Dentro la funzione main()");
        strcpy(domande[30].opzioni[2], "Dentro una funzione");
        strcpy(domande[30].opzioni[3], "Dentro una struttura");
        domande[30].rispostaCorretta = 'a';

        strcpy(domande[31].domanda, "Come si usa una variabile locale in C?");
        strcpy(domande[31].opzioni[0], "Dentro la funzione in cui è dichiarata");
        strcpy(domande[31].opzioni[1], "Ovunque nel programma");
        strcpy(domande[31].opzioni[2], "Dentro la funzione main()");
        strcpy(domande[31].opzioni[3], "Fuori dalla funzione main()");
        domande[31].rispostaCorretta = 'a';
        break;


        case 6:
            *numeroDomande = 40;

            strcpy(domande[0].domanda, "Qual è l'indice del primo elemento di un array in C?");
            strcpy(domande[0].opzioni[0], "0");
            strcpy(domande[0].opzioni[1], "1");
            strcpy(domande[0].opzioni[2], "Dipende dal tipo dell'array");
            strcpy(domande[0].opzioni[3], "Dipende dall'implementazione del compilatore");
            domande[0].rispostaCorretta = 'a';

            strcpy(domande[1].domanda, "Qual è la dimensione in byte di un array int di 10 elementi su una macchina dove sizeof(int) è 4?");
            strcpy(domande[1].opzioni[0], "10");
            strcpy(domande[1].opzioni[1], "40");
            strcpy(domande[1].opzioni[2], "44");
            strcpy(domande[1].opzioni[3], "Dipende dalla piattaforma");
            domande[1].rispostaCorretta = 'b';

            strcpy(domande[2].domanda, "Cosa succede se si accede a un elemento di un array utilizzando un indice fuori dai limiti?");
            strcpy(domande[2].opzioni[0], "Genera un errore di compilazione");
            strcpy(domande[2].opzioni[1], "Genera un errore di runtime");
            strcpy(domande[2].opzioni[2], "Comportamento indefinito");
            strcpy(domande[2].opzioni[3], "Restituisce 0");
            domande[2].rispostaCorretta = 'c';

            strcpy(domande[3].domanda, "Come si passa un array come argomento a una funzione?");
            strcpy(domande[3].opzioni[0], "Passando una copia dell'array");
            strcpy(domande[3].opzioni[1], "Passando il puntatore al primo elemento dell'array");
            strcpy(domande[3].opzioni[2], "Passando la dimensione dell'array");
            strcpy(domande[3].opzioni[3], "Non è possibile passare un array a una funzione");
            domande[3].rispostaCorretta = 'b';

            strcpy(domande[4].domanda, "Come si calcola la dimensione di un array statico in C?");
            strcpy(domande[4].opzioni[0], "sizeof(array)");
            strcpy(domande[4].opzioni[1], "sizeof(array) / sizeof(array[0])");
            strcpy(domande[4].opzioni[2], "sizeof(array[0]) * sizeof(array)");
            strcpy(domande[4].opzioni[3], "Non è possibile calcolarla");
            domande[4].rispostaCorretta = 'b';

            strcpy(domande[5].domanda, "Qual è il valore iniziale di un array non inizializzato in C?");
            strcpy(domande[5].opzioni[0], "0 per tutti gli elementi");
            strcpy(domande[5].opzioni[1], "Indefinito");
            strcpy(domande[5].opzioni[2], "Dipende dal tipo dell'array");
            strcpy(domande[5].opzioni[3], "Dipende dal compilatore");
            domande[5].rispostaCorretta = 'b';

            strcpy(domande[6].domanda, "Cosa rappresenta l'indirizzo dell'array quando viene passato a una funzione?");
            strcpy(domande[6].opzioni[0], "L'indirizzo del primo elemento");
            strcpy(domande[6].opzioni[1], "La dimensione dell'array");
            strcpy(domande[6].opzioni[2], "L'indirizzo del puntatore all'array");
            strcpy(domande[6].opzioni[3], "L'intero array come copia");
            domande[6].rispostaCorretta = 'a';

            strcpy(domande[7].domanda, "Qual è il risultato di sommare un intero a un puntatore a un array?");
            strcpy(domande[7].opzioni[0], "Incrementa l'indirizzo del puntatore di un numero di byte pari alla somma");
            strcpy(domande[7].opzioni[1], "Incrementa l'indirizzo del puntatore di un numero di elementi pari alla somma");
            strcpy(domande[7].opzioni[2], "Sposta il puntatore alla fine dell'array");
            strcpy(domande[7].opzioni[3], "Non è permesso in C");
            domande[7].rispostaCorretta = 'b';

            strcpy(domande[8].domanda, "Quale dichiarazione è corretta per un array bidimensionale?");
            strcpy(domande[8].opzioni[0], "int array[][];");
            strcpy(domande[8].opzioni[1], "int array[10][];");
            strcpy(domande[8].opzioni[2], "int array[][10];");
            strcpy(domande[8].opzioni[3], "int array[10][10];");
            domande[8].rispostaCorretta = 'd';

            strcpy(domande[9].domanda, "Come si accede al valore nella seconda riga e terza colonna di un array bidimensionale int[5][5]?");
            strcpy(domande[9].opzioni[0], "int[2][3]");
            strcpy(domande[9].opzioni[1], "int[1][2]");
            strcpy(domande[9].opzioni[2], "array[1][2]");
            strcpy(domande[9].opzioni[3], "array[2][3]");
            domande[9].rispostaCorretta = 'c';

            strcpy(domande[10].domanda, "Cosa accade se l'inizializzazione di un array contiene meno valori rispetto alla sua dimensione?");
            strcpy(domande[10].opzioni[0], "I valori mancanti vengono impostati a 0");
            strcpy(domande[10].opzioni[1], "I valori mancanti rimangono indefiniti");
            strcpy(domande[10].opzioni[2], "Non è possibile compilare il programma");
            strcpy(domande[10].opzioni[3], "Il compilatore genera un warning ma imposta valori casuali");
            domande[10].rispostaCorretta = 'a';

            strcpy(domande[10].domanda, "Cosa accade se si accede a un indice di un array che è fuori dai limiti definiti?");
            strcpy(domande[10].opzioni[0], "Si verifica un comportamento indefinito.");
            strcpy(domande[10].opzioni[1], "Viene lanciata un'eccezione.");
            strcpy(domande[10].opzioni[2], "Il programma termina immediatamente.");
            strcpy(domande[10].opzioni[3], "Viene restituito un valore predefinito di 0.");
            domande[10].rispostaCorretta = 'a';

            strcpy(domande[11].domanda, "Qual è il significato del parametro formale `int arr[]` in una funzione?");
            strcpy(domande[11].opzioni[0], "È un puntatore al primo elemento dell'array passato.");
            strcpy(domande[11].opzioni[1], "È una copia dell'array passato.");
            strcpy(domande[11].opzioni[2], "È un array bidimensionale.");
            strcpy(domande[11].opzioni[3], "È una costante immutabile.");
            domande[11].rispostaCorretta = 'a';

            strcpy(domande[12].domanda, "Qual è la differenza tra `int arr[10]` e `int *arr`?");
            strcpy(domande[12].opzioni[0], "Il primo è un array, il secondo è un puntatore.");
            strcpy(domande[12].opzioni[1], "Entrambi sono puntatori al primo elemento.");
            strcpy(domande[12].opzioni[2], "Il primo è un puntatore, il secondo è un array.");
            strcpy(domande[12].opzioni[3], "Non c'è differenza tra i due.");
            domande[12].rispostaCorretta = 'a';

            strcpy(domande[13].domanda, "Cosa restituisce la funzione `sizeof` quando viene applicata a un array?");
            strcpy(domande[13].opzioni[0], "La dimensione totale in byte dell'array.");
            strcpy(domande[13].opzioni[1], "Il numero di elementi dell'array.");
            strcpy(domande[13].opzioni[2], "La dimensione in byte del primo elemento.");
            strcpy(domande[13].opzioni[3], "Il puntatore al primo elemento dell'array.");
            domande[13].rispostaCorretta = 'a';

            strcpy(domande[14].domanda, "Qual è il valore di un array non inizializzato dichiarato come `int arr[5]`?");
            strcpy(domande[14].opzioni[0], "Valori casuali non definiti.");
            strcpy(domande[14].opzioni[1], "Tutti i valori sono inizializzati a 0.");
            strcpy(domande[14].opzioni[2], "Tutti i valori sono inizializzati a -1.");
            strcpy(domande[14].opzioni[3], "Il programma non compila.");
            domande[14].rispostaCorretta = 'a';

            strcpy(domande[15].domanda, "Qual è lo scopo dell'array `argv[]` in un programma C?");
            strcpy(domande[15].opzioni[0], "Contiene gli argomenti della riga di comando come stringhe.");
            strcpy(domande[15].opzioni[1], "Contiene il nome del programma eseguibile.");
            strcpy(domande[15].opzioni[2], "Memorizza il numero di argomenti della riga di comando.");
            strcpy(domande[15].opzioni[3], "È un array di numeri interi.");
            domande[15].rispostaCorretta = 'a';

            strcpy(domande[16].domanda, "Cosa accade quando un array multidimensionale viene passato a una funzione?");
            strcpy(domande[16].opzioni[0], "Solo il puntatore al primo elemento viene passato.");
            strcpy(domande[16].opzioni[1], "Tutta la memoria dell'array viene copiata.");
            strcpy(domande[16].opzioni[2], "Non è possibile passare array multidimensionali.");
            strcpy(domande[16].opzioni[3], "Tutti gli elementi dell'array vengono inizializzati a 0.");
            domande[16].rispostaCorretta = 'a';

            strcpy(domande[17].domanda, "Come si inizializza un array bidimensionale di dimensioni 3x3?");
            strcpy(domande[17].opzioni[0], "int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};");
            strcpy(domande[17].opzioni[1], "int arr[3][3] = [1,2,3,4,5,6,7,8,9];");
            strcpy(domande[17].opzioni[2], "int arr[3][3] = {1,2,3,4,5,6,7,8,9};");
            strcpy(domande[17].opzioni[3], "int arr[3][3] = (1,2,3,4,5,6,7,8,9);");
            domande[17].rispostaCorretta = 'a';

            strcpy(domande[18].domanda, "Qual è la caratteristica principale degli array statici in C?");
            strcpy(domande[18].opzioni[0], "Hanno una dimensione fissata al momento della compilazione.");
            strcpy(domande[18].opzioni[1], "Possono essere ridimensionati dinamicamente.");
            strcpy(domande[18].opzioni[2], "Non possono essere inizializzati.");
            strcpy(domande[18].opzioni[3], "Hanno un puntatore implicito.");
            domande[18].rispostaCorretta = 'a';

            strcpy(domande[19].domanda, "Cosa rappresenta `*(arr + i)` in un array `arr`?");
            strcpy(domande[19].opzioni[0], "L'elemento all'indice `i` dell'array.");
            strcpy(domande[19].opzioni[1], "L'indirizzo di memoria dell'elemento all'indice `i`.");
            strcpy(domande[19].opzioni[2], "Il valore dell'indirizzo di memoria successivo.");
            strcpy(domande[19].opzioni[3], "Il puntatore all'array.");
            domande[19].rispostaCorretta = 'a';

            strcpy(domande[20].domanda, "Completate la frase: Le liste e le tabelle di valori sono memorizzate in __________.");
            strcpy(domande[20].opzioni[0], "Array.");
            strcpy(domande[20].opzioni[1], "Strutture.");
            strcpy(domande[20].opzioni[2], "File.");
            strcpy(domande[20].opzioni[3], "Variabili.");
            domande[20].rispostaCorretta = 'a';

            strcpy(domande[21].domanda, "Completate la frase: Il numero usato per riferirsi a un particolare elemento di un array è chiamato il suo __________.");
            strcpy(domande[21].opzioni[0], "Indice.");
            strcpy(domande[21].opzioni[1], "Offset.");
            strcpy(domande[21].opzioni[2], "Chiave.");
            strcpy(domande[21].opzioni[3], "Parametro.");
            domande[21].rispostaCorretta = 'a';

            strcpy(domande[22].domanda, "Completate la frase: Una __________ va usata per specificare la dimensione di un array perché rende il programma più modificabile.");
            strcpy(domande[22].opzioni[0], "Costante simbolica.");
            strcpy(domande[22].opzioni[1], "Variabile globale.");
            strcpy(domande[22].opzioni[2], "Variabile locale.");
            strcpy(domande[22].opzioni[3], "Funzione.");
            domande[22].rispostaCorretta = 'a';

            strcpy(domande[23].domanda, "Completate la frase: Il processo di messa in ordine degli elementi di un array è chiamato __________ dell’array.");
            strcpy(domande[23].opzioni[0], "Ordinamento.");
            strcpy(domande[23].opzioni[1], "Filtraggio.");
            strcpy(domande[23].opzioni[2], "Indicizzazione.");
            strcpy(domande[23].opzioni[3], "Iterazione.");
            domande[23].rispostaCorretta = 'a';

            strcpy(domande[24].domanda, "Completate la frase: Determinare se un array contiene un certo valore chiave si dice __________ nell’array.");
            strcpy(domande[24].opzioni[0], "Ricerca.");
            strcpy(domande[24].opzioni[1], "Indicizzazione.");
            strcpy(domande[24].opzioni[2], "Classificazione.");
            strcpy(domande[24].opzioni[3], "Iterazione.");
            domande[24].rispostaCorretta = 'a';

            strcpy(domande[25].domanda, "Completate la frase: Un array che usa due indici è detto array __________.");
            strcpy(domande[25].opzioni[0], "Bidimensionale.");
            strcpy(domande[25].opzioni[1], "Dinamico.");
            strcpy(domande[25].opzioni[2], "Multivettoriale.");
            strcpy(domande[25].opzioni[3], "Monodimensionale.");
            domande[25].rispostaCorretta = 'a';

            strcpy(domande[26].domanda, "Un array può memorizzare molti tipi differenti di valori.");
            strcpy(domande[26].opzioni[0], "Vero.");
            strcpy(domande[26].opzioni[1], "Falso. Tutti gli elementi di un array devono essere dello stesso tipo.");
            strcpy(domande[26].opzioni[2], "");
            strcpy(domande[26].opzioni[3], "");
            domande[26].rispostaCorretta = 'b';

            strcpy(domande[27].domanda, "L’indice di un array può essere del tipo di dati double.");
            strcpy(domande[27].opzioni[0], "Vero.");
            strcpy(domande[27].opzioni[1], "Falso. Gli indici devono essere interi.");
            strcpy(domande[27].opzioni[2], "");
            strcpy(domande[27].opzioni[3], "");
            domande[27].rispostaCorretta = 'b';

            strcpy(domande[28].domanda, "Se in una lista di inizializzatori vi sono meno inizializzatori del numero degli elementi nell’array, il C automaticamente inizializza i restanti elementi all’ultimo valore nella lista degli inizializzatori.");
            strcpy(domande[28].opzioni[0], "Vero.");
            strcpy(domande[28].opzioni[1], "Falso. I restanti elementi sono inizializzati a 0.");
            strcpy(domande[28].opzioni[2], "");
            strcpy(domande[28].opzioni[3], "");
            domande[28].rispostaCorretta = 'b';

            strcpy(domande[29].domanda, "È un errore se una lista di inizializzatori contiene più inizializzatori di quanti sono gli elementi nell’array.");
            strcpy(domande[29].opzioni[0], "Vero.");
            strcpy(domande[29].opzioni[1], "Falso. Il compilatore segnalerà un errore.");
            strcpy(domande[29].opzioni[2], "");
            strcpy(domande[29].opzioni[3], "");
            domande[29].rispostaCorretta = 'a';

            strcpy(domande[30].domanda, "L’elemento individuale di un array che viene passato a una funzione come un argomento della forma a[i] e viene modificato nella funzione chiamata conterrà poi il valore modificato nella funzione chiamante.");
            strcpy(domande[30].opzioni[0], "Vero.");
            strcpy(domande[30].opzioni[1], "Falso. L'array è passato per riferimento, ma la modifica dipende dal contesto.");
            strcpy(domande[30].opzioni[2], "");
            strcpy(domande[30].opzioni[3], "");
            domande[30].rispostaCorretta = 'a';


            strcpy(domande[31].domanda, "Come si accede a un elemento di un array tramite un puntatore?");
            strcpy(domande[31].opzioni[0], "array + i");
            strcpy(domande[31].opzioni[1], "*(array + i)");
            strcpy(domande[31].opzioni[2], "&(array[i])");
            strcpy(domande[31].opzioni[3], "array[i]");
            domande[31].rispostaCorretta = 'b';

            strcpy(domande[32].domanda, "Qual è la differenza tra array[i] e *(array + i) in C?");
            strcpy(domande[32].opzioni[0], "Sono equivalenti");
            strcpy(domande[32].opzioni[1], "array[i] è più efficiente di *(array + i)");
            strcpy(domande[32].opzioni[2], "*(array + i) è valido solo con puntatori");
            strcpy(domande[32].opzioni[3], "Non c'è differenza ma *(array + i) è meno leggibile");
            domande[32].rispostaCorretta = 'a';

            strcpy(domande[33].domanda, "Un array può essere ridimensionato dinamicamente?");
            strcpy(domande[33].opzioni[0], "Sì, usando realloc()");
            strcpy(domande[33].opzioni[1], "No, la dimensione è fissa");
            strcpy(domande[33].opzioni[2], "Sì, usando malloc()");
            strcpy(domande[33].opzioni[3], "Solo se è dichiarato come puntatore");
            domande[33].rispostaCorretta = 'a';

            strcpy(domande[34].domanda, "Come si calcola la lunghezza di una stringa in C?");
            strcpy(domande[34].opzioni[0], "Con la funzione strlen()");
            strcpy(domande[34].opzioni[1], "Con la funzione size()");
            strcpy(domande[34].opzioni[2], "Con la funzione length()");
            strcpy(domande[34].opzioni[3], "Con la funzione string_length()");
            domande[34].rispostaCorretta = 'a';

            strcpy(domande[35].domanda, "Quale operatore viene utilizzato per accedere ai membri di una struttura in C?");
            strcpy(domande[35].opzioni[0], ".");
            strcpy(domande[35].opzioni[1], "->");
            strcpy(domande[35].opzioni[2], "::");
            strcpy(domande[35].opzioni[3], "#");
            domande[35].rispostaCorretta = 'a';

            strcpy(domande[36].domanda, "Qual è la differenza principale tra `malloc()` e `calloc()` in C?");
            strcpy(domande[36].opzioni[0], "`malloc()` alloca memoria non inizializzata, mentre `calloc()` alloca memoria e la inizializza a zero");
            strcpy(domande[36].opzioni[1], "`malloc()` inizializza la memoria a zero, mentre `calloc()` la lascia non inizializzata");
            strcpy(domande[36].opzioni[2], "`malloc()` alloca un solo blocco di memoria, mentre `calloc()` ne alloca più blocchi");
            strcpy(domande[36].opzioni[3], "Non c'è differenza tra i due");
            domande[36].rispostaCorretta = 'a';

            strcpy(domande[37].domanda, "Cosa fa la funzione `free()` in C?");
            strcpy(domande[37].opzioni[0], "Dealloca la memoria precedentemente allocata dinamicamente");
            strcpy(domande[37].opzioni[1], "Libera la memoria di sistema");
            strcpy(domande[37].opzioni[2], "Crea una nuova variabile");
            strcpy(domande[37].opzioni[3], "Inizializza una variabile");
            domande[37].rispostaCorretta = 'a';

            strcpy(domande[38].domanda, "Cosa rappresenta il carattere `\0` in C?");
            strcpy(domande[38].opzioni[0], "Il terminatore di stringa");
            strcpy(domande[38].opzioni[1], "Il carattere di nuova linea");
            strcpy(domande[38].opzioni[2], "Un operatore");
            strcpy(domande[38].opzioni[3], "Un valore numerico");
            domande[38].rispostaCorretta = 'a';

            strcpy(domande[39].domanda, "Cosa fa la funzione `strcmp()` in C?");
            strcpy(domande[39].opzioni[0], "Confronta due stringhe");
            strcpy(domande[39].opzioni[1], "Copia una stringa in un'altra");
            strcpy(domande[39].opzioni[2], "Aggiunge una stringa alla fine di un'altra");
            strcpy(domande[39].opzioni[3], "Converte una stringa in maiuscolo");
            domande[39].rispostaCorretta = 'a';

            strcpy(domande[40].domanda, "Quale delle seguenti affermazioni è falsa riguardo alla mediana?");
            strcpy(domande[40].opzioni[0], "La mediana è il valore centrale in una serie ordinata di dati.");
            strcpy(domande[40].opzioni[1], "L'algoritmo ordina l'array e seleziona l'elemento centrale.");
            strcpy(domande[40].opzioni[2], "Con numero pari di elementi, è la media dei due centrali.");
            strcpy(domande[40].opzioni[3], "Tutte le affermazioni precedenti sono vere.");
            domande[40].rispostaCorretta = 'd';

            strcpy(domande[41].domanda, "Quale delle seguenti affermazioni è falsa riguardo alla moda?");
            strcpy(domande[41].opzioni[0], "La moda è il valore che ricorre più frequentemente.");
            strcpy(domande[41].opzioni[1], "L'algoritmo conta occorrenze e seleziona il valore massimo.");
            strcpy(domande[41].opzioni[2], "La moda può essere determinata graficamente con un istogramma.");
            strcpy(domande[41].opzioni[3], "Tutte le affermazioni precedenti sono vere.");
            domande[41].rispostaCorretta = 'd';

            strcpy(domande[42].domanda, "Quale delle seguenti affermazioni è vera riguardo al bubble sort?");
            strcpy(domande[42].opzioni[0], "È facile da programmare.");
            strcpy(domande[42].opzioni[1], "Opera lentamente su array grandi.");
            strcpy(domande[42].opzioni[2], "Esistono tecniche di ordinamento più efficienti.");
            strcpy(domande[42].opzioni[3], "Tutte le affermazioni precedenti sono vere.");
            domande[42].rispostaCorretta = 'd';

            strcpy(domande[43].domanda, "Nel bubble sort, è necessaria una variabile aggiuntiva per uno scambio?");
            strcpy(domande[43].opzioni[0], "Vero");
            strcpy(domande[43].opzioni[1], "Falso");
            domande[43].rispostaCorretta = 'a';

            strcpy(domande[44].domanda, "Quale delle seguenti affermazioni è falsa riguardo alla ricerca lineare?");
            strcpy(domande[44].opzioni[0], "Confronta ogni elemento dell'array con la chiave.");
            strcpy(domande[44].opzioni[1], "Può trovare una corrispondenza prima dell'ultimo elemento.");
            strcpy(domande[44].opzioni[2], "Confronta in media metà degli elementi.");
            strcpy(domande[44].opzioni[3], "Funziona bene per array piccoli o non ordinati.");
            domande[44].rispostaCorretta = 'c';

            strcpy(domande[45].domanda, "Quale delle seguenti affermazioni è falsa riguardo alla ricerca binaria?");
            strcpy(domande[45].opzioni[0], "Si usa per array ordinati.");
            strcpy(domande[45].opzioni[1], "Elimina dalla ricerca due elementi dopo un confronto.");
            strcpy(domande[45].opzioni[2], "Confronta l'elemento centrale con la chiave.");
            strcpy(domande[45].opzioni[3], "Prosegue finché l'array si riduce a un elemento.");
            domande[45].rispostaCorretta = 'b';

            strcpy(domande[46].domanda, "Quale delle seguenti affermazioni è falsa riguardo agli indici di un array?");
            strcpy(domande[46].opzioni[0], "Devono essere maggiori o uguali a 0.");
            strcpy(domande[46].opzioni[1], "Il C non verifica automaticamente i limiti degli array.");
            strcpy(domande[46].opzioni[2], "Accedere a indici fuori dai limiti può dare errori.");
            strcpy(domande[46].opzioni[3], "Tutte le affermazioni precedenti sono vere.");
            domande[46].rispostaCorretta = 'd';

            strcpy(domande[47].domanda, "Quando printf valuta una stringa di controllo, è sicuro usare input dall'utente?");
            strcpy(domande[47].opzioni[0], "Vero");
            strcpy(domande[47].opzioni[1], "Falso");
            domande[47].rispostaCorretta = 'b';
        break;

    case 7:
        *numeroDomande = 23;

        // Domanda 0
        strcpy(domande[0].domanda, "La definizione: int *countPtr, count; specifica che countPtr e count sono di tipo int *, ciascuno è un puntatore a un intero.");
        strcpy(domande[0].opzioni[0], "Vero");
        strcpy(domande[0].opzioni[1], "Falso");
        domande[0].rispostaCorretta = 'b';

        // Domanda 1
        strcpy(domande[1].domanda, "Quale delle seguenti affermazioni è falsa?");
        strcpy(domande[1].opzioni[0], "Un puntatore può essere inizializzato a NULL, 0 o a un indirizzo.");
        strcpy(domande[1].opzioni[1], "Inizializzare un puntatore a 0 equivale a inizializzare un puntatore a NULL, ma 0 è preferibile.");
        strcpy(domande[1].opzioni[2], "L'unico valore intero che si può assegnare direttamente a una variabile puntatore è 0.");
        strcpy(domande[1].opzioni[3], "Inizializzate i puntatori per prevenire risultati inaspettati.");
        domande[1].rispostaCorretta = 'b';

        // Domanda 2
        strcpy(domande[2].domanda, "Presupponendo le definizioni double d = 98.5; *dPtr; l'istruzione dPtr = &d; assegna l'indirizzo della variabile d alla variabile puntatore dPtr.");
        strcpy(domande[2].opzioni[0], "Vero");
        strcpy(domande[2].opzioni[1], "Falso");
        domande[2].rispostaCorretta = 'a';

        strcpy(domande[3].domanda, "L'operatore unario di indirezione (*) restituisce il valore dell'oggetto al quale punta il suo operando (puntatore). Usare l'operatore * in questo modo viene detto:");
        strcpy(domande[3].opzioni[0], "Dereferenziare un puntatore");
        strcpy(domande[3].opzioni[1], "Indirizzare un valore");
        strcpy(domande[3].opzioni[2], "Accedere alla memoria");
        strcpy(domande[3].opzioni[3], "Referenziare un indirizzo");
        domande[3].rispostaCorretta = 'a';


        // Domanda 4
        strcpy(domande[4].domanda, "Quale delle seguenti affermazioni è falsa?");
        strcpy(domande[4].opzioni[0], "Per default, tutti gli argomenti (che non siano array) sono passati per valore.");
        strcpy(domande[4].opzioni[1], "Le funzioni spesso richiedono puntatori per evitare copie di oggetti grandi.");
        strcpy(domande[4].opzioni[2], "L'istruzione return si può usare per restituire più valori.");
        strcpy(domande[4].opzioni[3], "Il passaggio per riferimento permette di 'restituire' più valori.");
        domande[4].rispostaCorretta = 'c';

        // Domanda 5
        strcpy(domande[5].domanda, "Quale delle seguenti affermazioni è falsa?");
        strcpy(domande[5].opzioni[0], "Si usano puntatori e operatori di indirezione per il passaggio per riferimento.");
        strcpy(domande[5].opzioni[1], "L'operatore & passa gli indirizzi degli argomenti.");
        strcpy(domande[5].opzioni[2], "Gli array vengono passati per riferimento usando &.");
        strcpy(domande[5].opzioni[3], "Tutte le precedenti affermazioni sono vere.");
        domande[5].rispostaCorretta = 'c';

        // Domanda 6
        strcpy(domande[6].domanda, "Cosa rappresenta sPtr nel prototipo void convertToUppercase(char *sPtr)?");
        strcpy(domande[6].opzioni[0], "Un puntatore non costante a dati costanti.");
        strcpy(domande[6].opzioni[1], "Un puntatore costante a dati non costanti.");
        strcpy(domande[6].opzioni[2], "Un puntatore non costante a dati non costanti.");
        strcpy(domande[6].opzioni[3], "Un puntatore costante a dati costanti.");
        domande[6].rispostaCorretta = 'c';

        strcpy(domande[7].domanda, "Il privilegio di accesso più basso è quello concesso da un puntatore a dati __. Un puntatore di questo tipo punta sempre alla stessa locazione di memoria e i dati non possono essere modificati.");
        strcpy(domande[7].opzioni[0], "costante, costanti");
        strcpy(domande[7].opzioni[1], "volatile, non costanti");
        strcpy(domande[7].opzioni[2], "statica, volatili");
        strcpy(domande[7].opzioni[3], "dinamica, modificabili");
        domande[7].rispostaCorretta = 'a';


        // Domanda 8
        strcpy(domande[8].domanda, "Di norma, quando si passa un array a una funzione, si passa anche come argomento la dimensione dell’array. Qual è il problema di impostare direttamente la dimensione nella definizione della funzione?");
        strcpy(domande[8].opzioni[0], "Limiterebbe la funzione a una dimensione specifica, riducendone la riutilizzabilità.");
        strcpy(domande[8].opzioni[1], "Aumenterebbe la complessità temporale della funzione.");
        strcpy(domande[8].opzioni[2], "Creerebbe conflitti con i puntatori nell'array.");
        strcpy(domande[8].opzioni[3], "Comprometterebbe la sicurezza del buffer.");
        domande[8].rispostaCorretta = 'a';


        // Domanda 9
        strcpy(domande[9].domanda, "La funzione bubbleSort usa &array[j] e &array[j+1] per passaggio per riferimento. Supponete che swap riceva questi puntatori in int *firstPtr e int *secondPtr. Quale codice è corretto?");
        strcpy(domande[9].opzioni[0], "int temp = *firstPtr; *firstPtr = *secondPtr; *secondPtr = temp;");
        strcpy(domande[9].opzioni[1], "int temp = firstPtr; firstPtr = secondPtr; secondPtr = temp;");
        strcpy(domande[9].opzioni[2], "swap(&firstPtr, &secondPtr);");
        strcpy(domande[9].opzioni[3], "*firstPtr = *secondPtr; *secondPtr = *firstPtr;");
        domande[9].rispostaCorretta = 'a';


            // Domanda 10
        strcpy(domande[10].domanda, "Data la definizione dell'array: double temperatures[31]; l'espressione: sizeof(temperatures) / sizeof(temperatures[0]) quale attributo di temperatures determina?");
        strcpy(domande[10].opzioni[0], "La dimensione di ogni elemento");
        strcpy(domande[10].opzioni[1], "Il numero di elementi nell'array");
        strcpy(domande[10].opzioni[2], "La dimensione totale dell'array");
        strcpy(domande[10].opzioni[3], "Nessuna delle precedenti");
        domande[10].rispostaCorretta = 'b';

        // Domanda 11
        strcpy(domande[11].domanda, "Quando un intero è sommato a un puntatore o sottratto da esso, il puntatore è incrementato o decrementato di quell’intero moltiplicato per cosa?");
        strcpy(domande[11].opzioni[0], "La dimensione dell'oggetto a cui il puntatore fa riferimento");
        strcpy(domande[11].opzioni[1], "La dimensione del puntatore");
        strcpy(domande[11].opzioni[2], "L'indirizzo base dell'oggetto");
        strcpy(domande[11].opzioni[3], "La dimensione totale dell'array");
        domande[11].rispostaCorretta = 'a';

        strcpy(domande[12].domanda, "Se bPtr punta al secondo elemento dell'array b (b[1]), con quale espressione si può fare riferimento all'elemento b[3]?");
        strcpy(domande[12].opzioni[0], "*bPtr[2]");
        strcpy(domande[12].opzioni[1], "sizeof(b) / sizeof(bPtr)");
        strcpy(domande[12].opzioni[2], "*(bPtr + 2)");
        strcpy(domande[12].opzioni[3], "&b[1]");
        domande[12].rispostaCorretta = 'c';


        // Domanda 13
        strcpy(domande[13].domanda, "Un uso comune di un array di puntatori è quello di realizzare un array di cosa?");
        strcpy(domande[13].opzioni[0], "Numeri interi");
        strcpy(domande[13].opzioni[1], "Stringhe");
        strcpy(domande[13].opzioni[2], "Puntatori a funzioni");
        strcpy(domande[13].opzioni[3], "Nessuna delle precedenti");
        domande[13].rispostaCorretta = 'b';

        // Domanda 14
        strcpy(domande[14].domanda, "L'algoritmo per mescolare le carte che abbiamo presentato può essere eseguito indefinitamente se le carte già mescolate vengono ripetutamente selezionate a caso. Questo fenomeno è noto come?");
        strcpy(domande[14].opzioni[0], "Mescolamento circolare");
        strcpy(domande[14].opzioni[1], "Ridistribuzione casuale");
        strcpy(domande[14].opzioni[2], "Posposizione indefinita");
        strcpy(domande[14].opzioni[3], "Riordinamento infinito");
        domande[14].rispostaCorretta = 'c';

        // Domanda 15
        strcpy(domande[15].domanda, "La specifica di formato \"%5s of %-8s\" stampa una stringa allineata a destra in un campo di cinque caratteri seguita da 'of' e da una stringa allineata a sinistra in un campo di otto caratteri?");
        strcpy(domande[15].opzioni[0], "Vero");
        strcpy(domande[15].opzioni[1], "Falso");
        domande[15].rispostaCorretta = 'a';

        // Domanda 16
        strcpy(domande[16].domanda, "Il parametro compare dichiarato nell'intestazione della funzione bubble sort come: int (*compare)(int a, int b) è un puntatore a una funzione?");
        strcpy(domande[16].opzioni[0], "Vero");
        strcpy(domande[16].opzioni[1], "Falso");
        domande[16].rispostaCorretta = 'b';

        // Domanda 17
        strcpy(domande[17].domanda, "Proprio come un puntatore a una variabile è dereferenziato per accedere al valore della variabile, un puntatore a una funzione è dereferenziato per cosa?");
        strcpy(domande[17].opzioni[0], "Modificare la funzione");
        strcpy(domande[17].opzioni[1], "Chiamare la funzione");
        strcpy(domande[17].opzioni[2], "Allocare memoria per la funzione");
        strcpy(domande[17].opzioni[3], "Creare un nuovo puntatore");
        domande[17].rispostaCorretta = 'b';

        // Domanda 18
        strcpy(domande[18].domanda, "Una caratteristica chiave di funzioni come printf_s e scanf_s è quella di avere restrizioni in fase di esecuzione. Cosa richiedono i loro argomenti puntatore?");
        strcpy(domande[18].opzioni[0], "Devono essere non-NULL");
        strcpy(domande[18].opzioni[1], "Devono essere costanti");
        strcpy(domande[18].opzioni[2], "Devono essere allineati a 4 byte");
        strcpy(domande[18].opzioni[3], "Devono essere inizializzati a zero");
        domande[18].rispostaCorretta = 'a';

        // Domanda 19
        strcpy(domande[19].domanda, "L'uso scorretto dei puntatori porta oggi a molte delle più comuni vulnerabilità nella sicurezza dei sistemi?");
        strcpy(domande[19].opzioni[0], "Vero");
        strcpy(domande[19].opzioni[1], "Falso");
        domande[19].rispostaCorretta = 'a';

        // Domanda 20
        strcpy(domande[20].domanda, "Un puntatore dichiarato void può essere dereferenziato?");
        strcpy(domande[20].opzioni[0], "Vero");
        strcpy(domande[20].opzioni[1], "Falso");
        domande[20].rispostaCorretta = 'b';

        // Domanda 21
        strcpy(domande[21].domanda, "Una variabile puntatore contiene come suo valore cosa?");
        strcpy(domande[21].opzioni[0], "L'indirizzo di un'altra variabile");
        strcpy(domande[21].opzioni[1], "Il valore della variabile puntata");
        strcpy(domande[21].opzioni[2], "Un numero casuale");
        strcpy(domande[21].opzioni[3], "Nessuna delle precedenti");
        domande[21].rispostaCorretta = 'a';

        strcpy(domande[22].domanda, "Si supponga che b è un array e bptr un puntatore a tale array, quale espressione si riferisce all'indirizzo dell'elemento 3?");
        strcpy(domande[22].opzioni[0], "bPtr[3]");
        strcpy(domande[22].opzioni[1], "*(b + 3)");
        strcpy(domande[22].opzioni[2], "*(bPtr + 3)");
        strcpy(domande[22].opzioni[3], "&b[3]");
        domande[22].rispostaCorretta = 'd';
        break;
    
    default:
        *numeroDomande = 0; // nessuna domanda per livelli non validi.
        break;
    }

    mischiaDomande(domande, *numeroDomande);

    // Mescola le risposte di ogni domanda
    for (int i = 0; i < *numeroDomande; i++) {
        mischiaRisposte(&domande[i]);
    }
    
}



/* 
    

    



    

    

    

    strcpy(domande[28].domanda, "Come si dichiarano variabili di tipo puntatore in C?");
    strcpy(domande[28].opzioni[0], "tipo *nome;");
    strcpy(domande[28].opzioni[1], "tipo &nome;");
    strcpy(domande[28].opzioni[2], "tipo nome*;");
    strcpy(domande[28].opzioni[3], "tipo @nome;");
    domande[28].rispostaCorretta = 'a';

    strcpy(domande[29].domanda, "Come si accede al valore puntato da un puntatore in C?");
    strcpy(domande[29].opzioni[0], "Usando l'operatore `*`");
    strcpy(domande[29].opzioni[1], "Usando l'operatore `&`");
    strcpy(domande[29].opzioni[2], "Usando l'operatore `->`");
    strcpy(domande[29].opzioni[3], "Usando l'operatore `[]`");
    domande[29].rispostaCorretta = 'a';

    strcpy(domande[42].domanda, "Cosa fa la funzione `fopen()` in C?");
    strcpy(domande[42].opzioni[0], "Apre un file");
    strcpy(domande[42].opzioni[1], "Chiude un file");
    strcpy(domande[42].opzioni[2], "Legge un file");
    strcpy(domande[42].opzioni[3], "Scrive un file");
    domande[42].rispostaCorretta = 'a';

    strcpy(domande[43].domanda, "Come si apre un file in modalità scrittura in C?");
    strcpy(domande[43].opzioni[0], "fopen(\"file.txt\", \"w\");");
    strcpy(domande[43].opzioni[1], "fopen(\"file.txt\", \"r\");");
    strcpy(domande[43].opzioni[2], "fopen(\"file.txt\", \"a\");");
    strcpy(domande[43].opzioni[3], "fopen(\"file.txt\", \"w+...\");");
    domande[43].rispostaCorretta = 'a';

    strcpy(domande[45].domanda, "Cosa fa la funzione `fclose()` in C?");
    strcpy(domande[45].opzioni[0], "Chiude un file aperto");
    strcpy(domande[45].opzioni[1], "Apre un file");
    strcpy(domande[45].opzioni[2], "Legge un file");
    strcpy(domande[45].opzioni[3], "Scrive su un file");
    domande[45].rispostaCorretta = 'a';

    strcpy(domande[48].domanda, "Come si dichiara una variabile di tipo puntatore a funzione in C?");
    strcpy(domande[48].opzioni[0], "tipo (*nome)(parametri);");
    strcpy(domande[48].opzioni[1], "tipo nome(parametri);");
    strcpy(domande[48].opzioni[2], "parametri tipo(*nome);");
    strcpy(domande[48].opzioni[3], "tipo* nome(parametri);");
    domande[48].rispostaCorretta = 'a';

    

 */