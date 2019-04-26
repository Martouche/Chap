/*
** EPITECH PROJECT, 2019
** made by Martin Vantalon
** File description:
** mychap structure and include
*/

#ifndef MYCHAP_H_
#define MYCHAP_H_

#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netdb.h>
#include <malloc.h>
#include <string.h>
#include <resolv.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <unistd.h>
#include <netinet/ip.h>
#include <netinet/udp.h>

#define PCKT_LEN 8192

typedef struct chap_s {
    char **tab;
    int port;
    char *target;
    char *passwd;
}chap_t;

struct ipheader {
    unsigned char iph_ihl:5, iph_ver:4;
    unsigned char iph_tos;
    unsigned short int iph_len;
    unsigned short int iph_ident;
    unsigned char iph_flag;
    unsigned short int iph_offset;
    unsigned char iph_ttl;
    unsigned char iph_protocol;
    unsigned short int iph_chksum;
    unsigned int iph_sourceip;
    unsigned int iph_destip;
};

struct udpheader {
    unsigned short int udph_srcport;
    unsigned short int udph_destport;
    unsigned short int udph_len;
    unsigned short int udph_chksum;
};

#endif
