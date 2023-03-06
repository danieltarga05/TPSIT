#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int pid, p0p1[2], p1p0[2];
    int dim;
    pipe(p0p1);
    pipe(p1p0);

    pid = fork();
    if (pid > 0)
    {
        int numeri[dim], somma = 0;
        printf("Inserisci dimensione: ");
        scanf("%d", &dim);
        for (int i = 0; i < dim; i++)
            scanf("%d", &numeri[i]);
        close(p0p1[0]);
        close(p1p0[1]);
        write(p0p1[1], numeri, dim);
        read(p1p0[0], (void *)&somma, sizeof(somma));
        printf("Somma %d\n", somma);
        exit(0);
    }
    else
    {

        int somma = 0, numeri[dim];

        close(p0p1[1]);
        close(p1p0[0]);

        read(p0p1[0], numeri, dim);

        for (int i = 0; i < dim; i++)        
            somma = somma + numeri[i];       
        printf("FIGLIO: somma %d\n", somma);
        write(p1p0[1], &somma, sizeof(somma));

        exit(0);
    }
}
