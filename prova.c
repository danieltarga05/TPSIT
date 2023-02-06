#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int numeri[10];

    for (int i = 1; i < argc; i++)
    {
        numeri[i] = atoi(argv[1]);
    }
    pari(argv[1]);
}

/*int massimo(char *numeri[10])
{
    int tmp = numeri[0];
    for (int i = 1; i < 10; i++)
    {
        if (numeri[1] > tmp)
        {
            tmp = numeri[1];
        }
    }
    return tmp;
}*/

int pari(int pari[10])
{
    int tmp;
    for (int k = 0; k < 10; k++)
    {
        if (pari[k] % 2 == 0)
        {
            tmp = pari[k];
            printf("%d\n", tmp);
        }
    }
    return tmp;
}