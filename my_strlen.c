/*
** EPITECH PROJECT, 2023
** Pool Day 03
** File description:
** Placeholder
*/

#include "my.h"

size_t my_strlen(char const *str)
{
    size_t len = 0;

    for (; str[len]; len++);
    return len;
}
