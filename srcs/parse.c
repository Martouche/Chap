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
