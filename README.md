# Teoria Quiz

Questo progetto è un'applicazione in C che permette agli studenti di esercitarsi con domande a risposta multipla, simulando un ambiente di esame. L'utente può scegliere il livello di difficoltà e rispondere alle domande relative al linguaggio di programmazione C, al fine di prepararsi per l'esame.

## Funzionalità principali

- **Inizia il quiz**: Gli studenti possono iniziare un quiz con un numero di domande in base al livello di difficoltà selezionato.
- **Cambio di livello di difficoltà**: L'utente può selezionare il livello di difficoltà tra 1 e 5.
- **Visualizzazione dei risultati**: Dopo aver completato il quiz, l'applicazione mostra il punteggio ottenuto rispetto al numero di domande.

## Struttura del progetto

Il progetto è strutturato in diverse cartelle e file per una gestione ordinata del codice:

Cartella `quiz`

Contiene i file sorgente principali e le librerie necessarie per eseguire il quiz.

- `quiz.c`: Questo è il file principale che contiene la logica di esecuzione del quiz, la gestione delle domande, la selezione del livello di difficoltà, e la visualizzazione dei risultati. L'utente può scegliere tra diverse opzioni (iniziare il quiz, cambiare livello, vedere i risultati o uscire dal programma).

- `ask.c`: Contiene le funzioni di supporto per la gestione delle domande. Include funzioni per caricare le domande in base al livello di difficoltà e per mescolare le risposte e le domande, rendendo il quiz più imprevedibile.

- `ask.h`: Header file che dichiara le strutture di dati (come Domanda) e le funzioni utilizzate per gestire il quiz, come la funzione di caricamento delle domande, il mescolamento delle risposte e delle domande, e la gestione del livello di difficoltà.

## Descrizione del flusso di esecuzione

1. **Inizio del programma**: Quando il programma viene avviato, l'utente vede un menu con le seguenti opzioni:

   - **Inizia il quiz**: Avvia il quiz e le domande vengono caricate in base al livello selezionato.
   - **Cambia livello di difficoltà**: L'utente può scegliere il livello da 1 a 5. Ogni livello contiene un set diverso di domande.
   - **Visualizza risultati**: Dopo aver completato il quiz, l'utente può visualizzare i risultati.
   - **Esci**: Uscita dal programma.

2. **Caricamento delle domande**: Le domande vengono caricate dinamicamente in base al livello selezionato, utilizzando la funzione `caricaDomande`. Le risposte vengono mescolate per ogni domanda e l'ordine delle domande viene mescolato per ogni sessione di quiz, grazie alla funzione `mischiaRisposte` e `mischiaDomande`.

3. **Gestione delle risposte**: Durante il quiz, l'utente deve scegliere la risposta corretta per ogni domanda. Il programma verifica la risposta e aggiorna il punteggio.

4. **Visualizzazione dei risultati**: Alla fine del quiz, viene visualizzato il punteggio ottenuto e il numero di domande risposte correttamente.

## Funzioni da implementare e migliorare

- **Aggiunta di nuove domande**: È possibile ampliare il quiz aggiungendo nuove domande nei vari livelli.
- **Gestione di più livelli di difficoltà**: Il progetto supporta già i livelli di difficoltà da 1 a 5 (da capitolo 1 a capitolo 5). Potresti aggiungere altre categorie o maggiori dettagli per ogni livello.
- **Personalizzazione della visualizzazione dei risultati**: Puoi estendere la funzionalità per salvare i risultati in un file o fornire feedback più dettagliato sull'andamento dell'utente.
- **Sistemare il livello 1**: All'avvio del livello 1 (o capitolo 1) Il test non si avvia a differenza degli altri livelli (o capitoli).

## Come ampliare il progetto

- **Aggiungere nuove domande**: Puoi aggiungere facilmente nuove domande nel file `ask.c` per ogni livello. Basta seguire la struttura delle domande già presenti.

- **Funzionalità di salvataggio e recupero dei punteggi**: Aggiungere un sistema per salvare i punteggi degli utenti su file, in modo che possano essere visualizzati successivamente.

- **Interfaccia grafica**: Si potrebbe sviluppare un'interfaccia grafica per rendere l'esperienza utente più interattiva e accattivante.

- **Aggiungere nuove funzionalità di valutazione**: Potresti implementare funzioni avanzate per fornire un'analisi più approfondita delle risposte, come la spiegazione delle risposte corrette

## Avvio del programma

Una volta apportate le modifiche ai file sorgenti, è necessario compilare il programma nel terminale utilizzando il comando:

```bash
gcc quiz.c ask.c -o quiz
```

Questo comando compila i file sorgenti `quiz.c`.c e `ask.c` e genera un eseguibile chiamato `quiz`.

Successivamente, per avviare il programma, eseguire il comando:

```bash
./quiz
```
Questo avvierà il quiz, dove potrai rispondere alle domande e visualizzare i risultati alla fine.

- Il comando `gcc quiz.c ask.c -o quiz` è utilizzato per compilare il programma. Il flag `-o quiz` specifica che l'eseguibile generato sarà chiamato `quiz`.
- Il comando `./quiz` esegue il programma compilato.

## Note

Se apportate delle modifiche che desiderate pubblicare, assicuratevi di farlo nel branch **Pupgrade***. In alternativa, potete creare un nuovo branch e inviare una richiesta di *merge* per unire le modifiche al branch principale.
