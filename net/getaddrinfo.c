#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {

    int s;
    struct addrinfo hints, *res;

    getaddrinfo("www.baidu.com", "http", &hints, &res);


}