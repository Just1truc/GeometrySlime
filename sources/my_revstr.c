/*
** EPITECH PROJECT, 2021
** my
** File description:
** my
*/

#include "my_runner.h"

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int i;
    int size;
    int pat;
    char swap;

    pat = my_strlen(str) - 1;
    i = 0;
    while (i < pat) {
        swap = str[i];
        str[i] = str[pat];
        str[pat] = swap;
        i++;
        pat--;
    }
    return (str);
}
