#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>

int main()
{
    char buf[20];
    size_t nbytes;
    strcpy(buf, "This is a test\n");
    nbytes = strlen(buf);
    int fd = open("/dev/stdout", O_WRONLY|O_TRUNC);
    printf("%d\n", fd);
    write(fd, buf, nbytes);
    return 0;
}