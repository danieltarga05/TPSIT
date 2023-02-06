#include <stdio.h>
#include <string.h>

char sololettere(char a[])
{
    /*char risultato;
    for (int i = 0; i < strlen(a); i++)
    {
        if ()
        {
            return a[i];
        }
    }

    return risultato;*/
}

void conteggio(char a[], char lettera)
{
    int contatore = 0;
    for (int i = 0; i < strlen(a); i++)
    {
        if (lettera == a[i])
        {
            contatore++;
        }
    }
    printf("Il numero di lettere nel testo è: %d\n", contatore);
}

void lunghezza(char a[], char a1[])
{
    if (strlen(a) < strlen(a1))
    {
        printf("La seconda stringa è più grande\n");
    }
    else if (strlen(a) > strlen(a1))
    {
        printf("La prima stringa è più grande\n");
    }
}

void contavocali(char a[], char a1[])
{
    int conta_stringa1 = 0;
    int conta2_stringa2 = 0;

    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u')
        {
            conta_stringa1++;
        }
    }

    for (int i = 0; i < strlen(a1); i++)
    {
        if (a1[i]=='a' || a1[i]=='e' || a1[i]=='i' || a1[i]=='o' || a1[i]=='u')
        {
            conta2_stringa2++;
        }
    }

    if (conta_stringa1 < conta2_stringa2)
    {
        printf("La seconda stringa contine più vocali\n");
    }
    else if (conta_stringa1 > conta2_stringa2)
    {
        printf("La prima stringa contiene più vocali\n");
    }
}
int main()
{
    char a[] = {'C', 'i', 'a', 'a', '8', '9', '3', '\0'};
    char a1[] = {'T', 'o', 'm', 'm', 'a', 's', 'o', '1', '\0'};
    char lettera;
    sololettere(a);
    printf("%s\n", a);
    printf("Inserisci lettera che vuoi conteggiare: ");
    scanf("%c", &lettera);
    conteggio(a, lettera);
    lunghezza(a, a1);
    contavocali(a, a1);
}