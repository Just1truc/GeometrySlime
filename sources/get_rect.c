/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** return rectangle
*/

#include "my_runner.h"

sfIntRect get_rect(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return rect;
}
