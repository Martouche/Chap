/*
** EPITECH PROJECT, 2019
** my parsing argument functions
** File description:
** made by Martin Vantalon
*/

#include "../include/mychap.h"

void my_parsing(int ac, char **av)
{
    char **tab = malloc(sizeof(char *) * ac + 1);
    int i = 0;

    print("zeub\n");
    while (i < ac) {
        tab[i] = malloc(sizeof(char) * strlen(av[i]) + 1);
        tab[i] = strdup(av[i]);
        i++;
    }
    if (my_compare(tab[1], "-t", "--target") == 1)
        exit(84);
    if (my_compare(tab[3], "-p", "--port") == 1)
        exit(84);
    if (my_compare(tab[5], "-P", "--password") == 1)
        exit(84);
    if (init_connexion(tab[2], atoi(tab[4])) == 2) {
        print("It went wrong here\n");
        exit(84);
    }
}

int my_compare(char *str, char *compare1, char *compare2)
{
    if (strcmp(str, compare1) != 0 && strcmp(str, compare2) != 0)
        return 1;
    return 0;
}
int init_connexion(char *target, int port)
{
    int sd;
    struct hostent *host;
    struct sockaddr_in addr;
    if ((host = gethostbyname(target)) == NULL) {
       perror(target);
       abort();
       print("OUlah ca abort");
    }
    sd = socket(PF_INET, SOCK_STREAM, 0);
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = *(long*)(host->h_addr);
    if (connect(sd, (struct sockaddr*)&addr, sizeof(addr)) != 0 ) {
        close(sd);
        perror(target);
        abort();
    }
    return 0;
}
