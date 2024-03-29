/*
** EPITECH PROJECT, 2018
** CONFIG SOCKET
** File description:
** CONFIG SOCKET
*/

#include "../include/mychap.h"

void init_client(client *client, cmd_args *args)
{
    if ((client->_config = malloc(sizeof(struct sockaddr_in))) == NULL) {
        perror("malloc");
        exit(FAIL);
    }
    if (!args->ip || !args->port || !args->password)
        exit(FAIL);
    client->_ip4 = malloc(sizeof(struct iphdr));
    client->_udp = malloc(sizeof(struct udphdr));
    if (!client->_ip4 || !client->_udp) {
        perror("malloc");
        exit(FAIL);
    }
    create_socket(client);
    configure_socket(client, args);
}

void create_socket(client *client)
{
    if ((client->sock = socket(AF_INET, SOCK_RAW, IPPROTO_UDP)) == ERROR) {
        perror("socket");
        exit(FAIL);
    }
    client->sock_info = get_client_sock_info(client);
}

void configure_socket(client *client, cmd_args *args)
{
    char opt = 1;
    client->_config->sin_family = AF_INET;
    client->_config->sin_addr.s_addr = inet_addr(args->ip);
    client->_config->sin_port = htons(atoi(args->port));

    if (setsockopt(client->sock, IPPROTO_IP, IP_HDRINCL,
    &opt, sizeof(opt)) < SUCCESS) {
        perror("setsockopt");
        exit(FAIL);
    }
}
