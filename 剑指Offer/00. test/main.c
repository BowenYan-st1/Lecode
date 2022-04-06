/*
 * @Author: unkonw
 * @Date: 2022-03-30 17:59:33
 * @LastEditors: aydan.yan
 * @LastEditTime: 2022-03-31 19:55:42
 * @FilePath: /剑指Offer/00. test/main.c
 * @Description:
 *
 * Copyright (c) 2022 by XGIMI, All Rights Reserved.
 */
#include <arpa/inet.h>
#include <netdb.h>
#include <resolv.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    char                *hostname = "www.baidu.com";
    char                 ipbuf[16], ip6buf[64];
    struct addrinfo      hints, *res, *rp;
    struct sockaddr_in  *addr;
    struct sockaddr_in6 *addr6;
    int                  err;

    res_init();
    send(MSG_NOSIGNAL);
    memset(&hints, 0, sizeof(hints));
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_family = AF_INET;
    hints.ai_flags = AI_PASSIVE; /* For wildcard IP address */
    hints.ai_protocol = 0;       /* Any protocol */
    err = getaddrinfo(hostname, NULL, &hints, &res);
    if (err) {
        printf("error %d: %s\n", err, gai_strerror(err));
        return 1;
    }
    for (rp = res; rp != NULL; rp = rp->ai_next) {
        if (rp->ai_family == AF_INET) {
            addr = (struct sockaddr_in *)rp->ai_addr;
            printf("%s\n", inet_ntop(AF_INET, &addr->sin_addr, ipbuf, 16));
        } else {
            addr6 = (struct sockaddr_in6 *)rp->ai_addr;
            printf("%s\n", inet_ntop(AF_INET6, &addr6->sin6_addr, ip6buf, 64));
        }
    }
    freeaddrinfo(res);
    return 0;
}