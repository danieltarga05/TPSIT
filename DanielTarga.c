#include <stdio.h>
#include <string.h>
#define MAX 100

int main()
{
    FILE *f1, *f2;
    // int contatore = 0;
    int i, j;
    char stringa[MAX];
    f1 = fopen("f1.txt", "r");//apro file 1 in lettura
    f2 = fopen("risultato.txt", "w");// apro file 2 in scrittura
    if (f1 == NULL)//se il file non esiste o non c'è niente, dà errore
    {
        printf("errore!");
    }
    if (f2 == NULL)
    {
        printf("errore!");
    }
    while (!feof(f1))
    {
        fscanf(f1, "%s", stringa);//legge il contenuto nel file
        for (i = 2; i < strlen(stringa); i++)//metto l'incremento = 2 perchè deve essere minimo di lunghezza 2 la parola
        {
            for (j = strlen(stringa); j > 2 ; j--)
            {
                if (stringa[j] == stringa[i])
                {
                    fprintf(f2, "Stringhe palindrome: %s \n", stringa);
                }
            }
        }
    }
    fclose(f1);//chiudo il file 1
    fclose(f2);//chiudo il file 2
    return 0;
}