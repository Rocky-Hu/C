#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

static int tcp_listen(char *ip, int port) 
{
    int lfd, opt, err;
    struct sockaddr_in addr;

    lfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_TCP);
    assert(lfd != -1);

    opt = 1;
    err = setsockopt(lfd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt));
    assert(!err);

    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(port);

    err = bind(lfd, (struct sockaddr *)&addr, sizeof(addr));
    assert(!err);

    err = listen(lfd, 8);
    assert(!err);

    return lfd;
}

int main(int args, char *argv[]) 
{
    int lfd, sfd;

    lfd = tcp_listen("127.0.0.1", 8888);
    while (1) {
        sfd = accept(lfd, NULL, NULL);
        close(sfd);
        printf("接收到tcp连接：%d\n", sfd);
    }

    return 0; 
}
