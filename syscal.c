#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char buf[BUFSIZ];
    int n;
    int fd;
    fd = open("F1.txt", O_RDWR);
    int n_read = read(fd, buf, BUFSIZ);
    int n_write = write(fd, buf, BUFSIZ);
    close(fd);
}