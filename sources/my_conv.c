/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** convert int to str
*/

#include "my_runner.h"

char *my_conv(int nbr, int nb)
{
    int b = 0;
    char *result = malloc(sizeof(char) * 34);

    while (nbr > 0) {
        result[b] = nbr % nb + '0';
        nbr = nbr / nb;
        b++;
    }
    if (b == 0) {
        result[b] = '0';
        b++;
    }
    result[b] = '\0';
    return (my_revstr(result));
}
