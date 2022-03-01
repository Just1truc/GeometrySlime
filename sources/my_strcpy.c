/*
** EPITECH PROJECT, 2021
** str copy
** File description:
** copy an str
*/

#include "my_runner.h"

char *my_strcpy(char *dest, char const *src)
{
    int i;

    i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
