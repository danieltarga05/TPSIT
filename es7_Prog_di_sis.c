#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define READ 0
#define WRITE 1
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Errore");
        exit(1);
    }

    int p1p2[2], p2p3[2], p3p0[2], pid, tot;
    char buffer, *puntatore, stringa[1000];

    pipe(p1p2);
    pid = fork();
    if (pid == 0)
    {
        close(p1p2[0]);
        close(WRITE);
        dup(p1p2[1]);
        close(p1p2[1]);
        execl("/usr/sbin/traceroute", "traceroute", argv[1], NULL);
        return -1;
    }

    pipe(p2p3);
    pid = fork();
    if (pid == 0)
    {
        close(p1p2[1]);
        close(READ);
        dup(p2p3[0]);
        close(p2p3[0]);

        close(p2p3[0]);
        close(WRITE);
        dup(p2p3[1]);
        close(p2p3[1]);
        execl("/usr/bin/awk", "awk", "{print $4}", (char *)0);
        return -1;
    }

    pipe(p3p0);
    pid = fork();
    if (pid == 0)
    {
        close(p2p3[1]);
        close(READ);
        dup(p2p3[0]);
        close(p2p3[0]);
        close(p3p0[0]);

        close(WRITE);
        dup(p3p0[1]);
        close(p3p0[1]);
        execl("/usr/bin/tail", "-n", "+2", (char *)0);
        return -1;
    }

    close(p2p3[0]);
    close(p2p3[1]);
    close(p3p0[0]);

    int nread = read(p3p0[0], buffer, sizeof(buffer));
    while (nread > 0)
    {
        strncat(stringa, &buffer, sizeof(buffer));
        if (buffer == '\n')
        {
            tot += strtod(stringa, &puntatore);
            stringa[0] = '\0';
        }
    }

    close(p3p0[0]);
    printf("Tempo: %fms", tot);
    return 0;
}