#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/poll.h>
#include <sys/ioctl.h>
#include <string.h>
#include <string.h>
#include <time.h>
#include <sys/epoll.h>

const int SERVER_PORT = 8000;
const char SERVER_ADDR[] = "127.0.0.1";
const int MAX_CLIENT = 100;
const int MAX_SIZE = 1024;

int main()
{
    int listen_fd, client_fd;
    int i;
    char buff[MAX_SIZE];
    struct sockaddr_in server_addr, client_addr;
    struct epoll_event epollevent, events[MAX_CLIENT];

    bzero(&server_addr, sizeof(server_addr));
    bzero(&client_addr, sizeof(client_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if ( -1 == listen_fd )
    {
        perror("socket error");
        return -1;
    }

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("bind error");
        return -1;
    }

    if (listen(listen_fd, MAX_CLIENT) == -1)
    {
        perror("listen error");
        return -1;
    }

    int epfd = epoll_create1(0);
    if (-1 == epfd)
    {
        perror("epoll create");
        return -1;
    }

    // add listen_fd to epoll, listen for connection event
    bzero(&epollevent, sizeof(epollevent));
    epollevent.events = EPOLLIN;
    epollevent.data.fd = listen_fd;

    if (epoll_ctl(epfd, EPOLL_CTL_ADD, client_fd, &epollevent) == -1)
    {
        perror("epoll ctl");
        return -1;
    }

    for (;;)
    {
        int nfds = epoll_wait(epfd, events, MAX_CLIENT, -1);
        if (-1 == nfds)
        {
            perror("epoll wait");
            continue;
        }
        for(i=0; i<nfds; ++i) 
        {
            if (events[i].data.fd == listen_fd) // connection
            {
                //accept
                socklen_t client_addr_size = sizeof(client_addr);
                client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_addr_size);
                if (-1 == client_fd)
                {
                    perror("accept error");
                    continue;
                }
                printf("accept client:%s:%u\n",inet_ntoa(client_addr.sin_addr), ntohl(client_addr.sin_port));

                // Register the client to epoll
                bzero(&epollevent, sizeof(epollevent));
                epollevent.events = EPOLLIN;
                epollevent.data.fd = client_fd;
                if (epoll_ctl(epfd, EPOLL_CTL_ADD, client_fd, &epollevent) == -1)
                {
                    perror("epoll ctl");
                    continue;
                }
            } else if (events[i].events & EPOLLIN)   // read event
            {
                // read data
                if (read(events[i].data.fd, buff, MAX_SIZE) == -1)
                {
                    perror("read error");
                    continue;
                }
                printf("Read data from client:%s\n", buff);

                // writable
                // Register the client to epoll
                bzero(&epollevent, sizeof(epollevent));
                epollevent.events = EPOLLOUT;
                epollevent.data.fd = events[i].data.fd;
                if (epoll_ctl(epfd, EPOLL_CTL_MOD, events[i].data.fd, &epollevent) == -1)
                {
                    perror("epoll ctl");
                    continue;
                }
            } else if (events[i].events & EPOLLOUT) // write event
            {
                // network client written to the current time
                time_t t = time(NULL);
                if ( (time_t)-1 == t)
                {
                    perror("time");
                    continue;
                }
 
                char *now = asctime(gmtime(&t));
 
                if (write(events[i].data.fd, now, strlen(now)) == -1)
                {
                    perror("write error");
                    continue;
                }
                // set-readable
                // Register the client to epoll
                bzero(&epollevent, sizeof(epollevent));
                epollevent.events = EPOLLIN;
                epollevent.data.fd = events[i].data.fd;
                if (epoll_ctl(epfd, EPOLL_CTL_MOD, events[i].data.fd, &epollevent) == -1)
                {
                    perror("epoll ctl");
                    continue;
                }
            } else if (events[i].events & EPOLLHUP)
            {
                //delete
                bzero(&epollevent, sizeof(epollevent));
                epollevent.events = EPOLLHUP;
                if (epoll_ctl(epfd,EPOLL_CTL_DEL, events[i].data.fd, &epollevent) == -1)
                {
                    perror("epoll ctl");
                    continue;
                }
                printf("Client closed \n");
            } else {
                printf("Handling Events unrealized:% d \n",events[i].events);
                continue;
            }
        }
    }

    close(epfd);
    close(client_fd);
    close(listen_fd);

    return 0;
}