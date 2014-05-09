/*
 * \file        main.c
 * \brief       
 *
 * \version     1.0.0
 * \date        2014年04月26日
 * \author      Ethan Shan <shanxiaoxi@allwinnertech.com>
 *
 * Copyright (c) 2014 Allwinner Technology. All Rights Reserved.
 *
 */

//           ___                                        
//         ,'_  "`-.      ,-'""`-.                      
//        ('"/"-.   \    /  ,-,.  \
//         `'    \  ,-'-/    /  `-'                     
//               ,-'-.      /                           
//            __ ("|")     f   NUGGGGGGGGGGGGGGGGGGGGGGH
//           (_)`-"---.    |                            
//            l   ---.     j   I'M A BUNNY       
//             `---'     ,'                             
//                 \    f      HUUUUUUUUUUUUUUGGHHGHHHHH
//                  )   l                               
//               __f _   Y     I love  carrot
//            ,'",-'"_"  l                              
//           (,,(,,,' `   Y                             
//                |       l                             
//                |        \,';,                        
//                l    ,    Y, ;                        
//                (`._(     ),'                         
//                 `.  `.  (                            
//               ,--',--'   )                         
//              (,,,(,,,---'                            

#include <linux/icmp.h>
//#include <netinet/ip_icmp.h>

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#include <ncurses.h>

#include "config.h"

#define MAX_WAIT_TIME 100

int main(int argc, char** argv)
{
    struct hostent *host;
    struct protoent *protocol;
    unsigned long inaddr = 0l;
    int waittime = MAX_WAIT_TIME;
    int size = 50 * 1024;
    if (argc < 2) {
        printf("Usage:%s hostname/IP address\n", argv[0]);
        exit(1);
    }

    // Obtain icmp protocol entry
    if ((protocol = getprotobyname("icmp")) == NULL) {
        perror("getprotobyname call error");
        exit(1);
    }
    int sockfd;
    // Create raw socket
    if ((sockfd = socket(AF_INET, SOCK_RAW, protocol->p_proto)) < 0) {
        perror("socket error");
        exit(1);
    }
    setuid(getutid());
    initscr();

    printw("Hello");
    refresh();
    getchar();
    endwin();
    printf("APP:\t%s\nVERSION:\t%s\n", APP_NAME, VERSION);
    return 0;
}
