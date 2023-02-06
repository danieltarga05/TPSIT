#include <stdio.h>
#include <string.h>

void stampa()
{
    int array[6] = {10, 15, 20, 25, 30, 35};
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", array[i]);
    }
}
void inverso()
{
    int array[6] = {10, 15, 20, 25, 30, 35};
    for (int i = 5; i >= 0; i--)
    {
        printf("%d ", array[i]);
    }
}
void sommaemedia()
{
    int array[6] = {10, 15, 20, 25, 30, 35};
    int i;
    int somma;
    float media;
    for (i = 0; i < 6; i++)
    {
        somma += array[i];
    }
    media = somma / i;
    printf("la somma è: %d\n", somma);
    printf("la media è: %f\n", media);
}
void nuemripari()
{
    int j = 0;
    int array[6] = {10, 15, 20, 25, 30, 35};
    int arraypari[j];
    for (int i = 0; i < 6; i++)
    {
        if (array[i] % 2 == 0)
        {
            arraypari[j] = array[i];
            j++;
        }
    }
    printf("array pari: %d\n ", arraypari[j]);
}

void nuemridispari()
{
    int j = 0;
    int array[6] = {10, 15, 20, 25, 30, 35};
    int arraydispari[j];
    for (int i = 0; i < 6; i++)
    {
        if (array[i] % 2 == 1)
        {
            arraydispari[j] = array[i];
            j++;
        }
    }
    printf("array pari: %d\n ", arraydispari[j]);
}

void selectionsort()
{
    int d = 6;
    int array[d];
    int i, j, tmp, min;
    for (i = 0; i < d; i++)
    {
        scanf("%d \n", &array[i]);
    }
    for (i = 0; i < d; i++)
    {
        min = i;
        for (i = j + 1; j < d + 1; j++)
        {
            if (array[j] < array[min])
                min = j;
        }
        tmp = array[min];
        array[min] = array[i];
        array[i] = tmp;
    }
    for (i = 0; i < d; i++)
    {
        printf("%d ", array[i]);        for (j = i+1; j < n; j++)
    }
}

int main(int argc, char *argv[])
{
    int scelta;
    do
    {
        printf("Scegli il numero da 1 a 9: ");
        scanf("%d", &scelta);
    } while (scelta < 1 || scelta > 9);

    switch (scelta)
    {
    case 1:
        stampa();
        break;
    case 2:
        inverso();
        break;
    case 3:
        sommaemedia();
        break;
    case 4:
        nuemripari();
        break;
    case 5:
        nuemridispari();
        break;
    case 6:
        printf("a");
        break;
    case 7:
        printf("a");
        break;
    case 8:
        printf("a");
        break;
    case 9:
        selectionsort();
        break;
    }
}