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

typedef struct chap_s {
    char **tab;
    int port;
    char *target;
    char *passwd;
}chap_t;

#endif
