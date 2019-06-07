/*
** EPITECH PROJECT, 2019
** made by Martin Vantalon
** File description:
** mychap structure and include
*/

#ifndef MYCHAP_H_
#define MYCHAP_H_

#define _GNU_SOURCE 1

#define ERROR -1
#define SUCCESS 0
#define FAIL 84
#define INIT_MSG "client hello"
#define PACKET_LEN 1024

#include <openssl/opensslconf.h>
#include <openssl/crypto.h>
#include <openssl/sha.h>
#include <openssl/opensslv.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <stdlib.h>
#include <arpa/inet.h>
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
#include <getopt.h>
#include <netinet/ip.h>
#include <netinet/udp.h>

#define PCKT_LEN 8192


struct pseudo_header
{
    u_int32_t source_address;
    u_int32_t dest_address;
    u_int8_t placeholder;
    u_int8_t protocol;
    u_int16_t udp_length;
};

typedef struct client_t
{
    struct iphdr *_ip4;
    struct udphdr *_udp;
    struct sockaddr_in *_config;
    struct sockaddr_in sock_info;
    int sock;
    char *payload;
} client;


typedef struct cmd_args_t
{
    char *port;
    char *ip;
    char *password;
} cmd_args;

// PARSING
int my_parsing(int ac, char **av, cmd_args *args);
bool evaluate_opt(int *opt, cmd_args *args);
char *check_ip(char *str);
bool check_port(const char *str);

// CONFIG SOCKET
void create_socket(client *client);
void configure_socket(client *client, cmd_args *args);
void init_client(client *client, cmd_args *args);
void configure_headers(client *client, cmd_args *args,
char *data, int packet_len);
struct sockaddr_in get_client_sock_info(client *);
void configure_udp_header(client *client, cmd_args *args, int packet_len);
void configure_ip_header(client *client, char *data, int packet_len);

// UTILS
void cleanup(client *client, cmd_args *args);
unsigned short csum(unsigned short *buf, int nwords);

//AUTH
void send_msg(client *client, const char *msg, cmd_args *args);
char *get_msg(client *client);
void create_headers(client *client, cmd_args *args);
void init_handshake(client *client, cmd_args *args);
void check_challenge_success(char *str);
char *sha256_hash(char *);

#endif
