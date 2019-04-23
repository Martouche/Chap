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
    if (ac == 7) {
        my_parsing(ac, av);
    }
    return 0;
}
