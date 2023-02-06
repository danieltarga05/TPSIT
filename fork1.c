#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pid;
    int uguale = 10;
    int diversa = 10;
    printf("1) prima della fork\n");
    pid = fork();
    printf("2) dopo della fork\n");
    if (pid == 0)
    {
        printf("3) sono il processo figlio con pid %d", getpid());
        printf("variabile %d\n", uguale);
        printf("processo %d\n", diversa);
        exit(1);
    }
    else
    {
        printf("3) sono il processo padre con pid %d", getpid());
        printf("variabile %d\n", uguale);
        printf("processo %d\n", diversa);
        exit(0);
    }
}