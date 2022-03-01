/*
** EPITECH PROJECT, 2021
** My putstr
** File description:
** len(ç in py
*/

#include "my_runner.h"

int my_strlen(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
