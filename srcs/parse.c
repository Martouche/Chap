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
    printf("zeub\n");
    while (i < ac) {
        tab[i] = malloc(sizeof(char) * strlen(av[i]) + 1);
        tab[i] = strdup(av[i]);
        i++;
    }
    if (strcmp(tab[1], "-t") != 0 || strcmp(tab[1], "--target") != 0)
        exit(84);
    if (strcmp(tab[3], "-p") != 0 || strcmp(tab[3], "--port") != 0)
        exit(84);
    if (strcmp(tab[5], "-P") != 0 || strcmp(tab[5], "--password") != 0)
        exit(84);

}
