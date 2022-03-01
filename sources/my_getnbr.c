/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** get char and resturn int
*/

#include "my_runner.h"

int my_getnbr(char *str)
{
    int number = 0;
    int i = 0;
    int sign = 1;

    while (str[i] == '-' || str[i] == '0') {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i] != '\0' && str[i] != 'a') {
        if (str[i] >= 47 && str[i] <= 57)
            number = number * 10 + (str[i] - 48);
        i++;
    }
    return (number * sign);
}
