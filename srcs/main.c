/*
** EPITECH PROJECT, 2019
** my main functions
** File description:
** made by Martin Vantalon
*/

#include "../include/mychap.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void print(char const *str)
{
    int i;
    i = 0;
    while (str[i] != '\0' ) {
        my_putchar(str[i]);
        i = i + 1;
    }
}

int main(int ac, char **av)
{
    cmd_args args;
    client client;

    if (ac == 7) {
        if (my_parsing(ac, av, &args) != 0)
            return 84;
        init_client(&client, &args);
        init_handshake(&client, &args);
    }
    return 0;
}
