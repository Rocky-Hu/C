#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[]) {
    int lfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (lfd == -1) {
        perror("socket: ");
        return -1;
    }

    struct sockaddr_in sockaddr;
    memset(&sockaddr, 0, sizeof(struct sockaddr_in));
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(3459);
    sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    int optval = 1;
    setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    if (bind(lfd, (struct sockaddr*)&sockaddr, sizeof(sockaddr)) == -1) {
        perror("bind: ");
        return -1;
    }

    if (listen(lfd, 128) == -1) {
        perror("listen: ");
        return -1;
    }

    struct sockaddr_storage claddr;
    socklen_t addrlen = sizeof(struct sockaddr_storage);
    int cfd = accept(lfd, (struct sockaddr*)&claddr, &addrlen);
    if (cfd == -1) {
        perror("accept: ");
        return -1;
    }
    printf("client connected: %d\n", cfd);

    char buff[100];
    for (;;) {
        ssize_t num = read(cfd, buff, 100);
        if (num == 0) {
            printf("client close: %d\n", cfd);
            close(cfd);
            break;
        } else if (num == -1) {
            int no = errno;
            if (no != EINTR && no != EAGAIN && no != EWOULDBLOCK) {
                printf("client error: %d\n", cfd);
                close(cfd);
            }
        } else {
            if (write(cfd, buff, num) != num) {
                printf("client error: %d\n", cfd);
                close(cfd);
            }
        }
    }
    return 0;
}