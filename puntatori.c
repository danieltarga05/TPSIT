#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int pid = fork();
    if (pid == 0)
    {
        printf("conversione in maiuscolo: %c\n", toupper(argv[1][0]));
        exit(0);
    } 
    wait(&pid);
}