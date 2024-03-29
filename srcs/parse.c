/*
** EPITECH PROJECT, 2019
** my parsing argument functions
** File description:
** made by Martin Vantalon
*/

#include "../include/mychap.h"

char *check_ip(char *str)
{
    if (strcmp(str, "localhost") == 0)
        return "127.0.0.1";
    return str;
}

bool check_port(const char *str)
{
    int port = atoi(str);
    return port > 1024 ? true : false;
}

bool evaluate_opt(int *opt, cmd_args *args)
{
    switch (*opt) {
        case 't':
            args->ip = check_ip(optarg);
            break;
        case 'p':
            args->port = check_port(optarg) ? strdup(optarg) : NULL;
            if (!args->port)
                return false;
            break;
        case 'P':
            args->password = strdup(optarg);
            break;
        case ':':
        case '?':
            return false;
    }
    return true;
}

int my_parsing(int ac, char **av, cmd_args *args)
{
    int opt;
    static struct option long_options[] =
    {
        {"password", required_argument, NULL, 'P'},
        {"port", required_argument, NULL, 'p'},
        {"target", required_argument, NULL, 't'},
        {NULL, 0, NULL, 0}
    };

    while ((opt = getopt_long(ac, av, ":t:p:P:",
    long_options, NULL)) != ERROR) {
        if (!evaluate_opt(&opt, args))
            return -1;
    }
    check_host_name(args);
    if (optind < ac)
        return -1;
    return 0;
}

void check_host_name(cmd_args *args)
{
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_protocol = 0;
    hints.ai_flags = AI_ADDRCONFIG;
    struct addrinfo *res = NULL;
    int err = getaddrinfo(args->ip, args->port, &hints, &res);
    if (err != SUCCESS) {
        printf("No such hostname: '%s'\n", args->ip);
        exit(SUCCESS);
    }
}
