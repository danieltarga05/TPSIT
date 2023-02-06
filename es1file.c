#include <stdio.h>
#include <string.h>
#define MAX 81
/* ricerca di parole in un file di testo */
int main()
{
    FILE *f1;            // dichiarazione di file
    char P[MAX], S[MAX]; // dichiarazione di due stringhe
    int cont = 0;
    f1 = fopen("F1.txt", "r");//apre il file solo in lettura
    if (f1 == NULL)
    {
        printf("Errore apertura del file!\n");
        return 0;
    }
    printf("\nParola da cercare ? ");
    scanf("%s", P);
    fscanf(f1, "%s", S);
    while (!feof(f1))//end of file (va avanti a leggere, si ferma e quando finische il file non legge più)
    {
        if (strcmp(S, P) == 0)
        {
            printf("\nHo trovato %s!\n", P);
            cont++;
        }
        fscanf(f1, "%s", S);
    }
    printf("Trovata %s %d volte \n", P, cont);
    fclose(f1);
}