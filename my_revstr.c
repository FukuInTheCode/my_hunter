/*
** EPITECH PROJECT, 2023
** Pool Day 06
** File description:
** Placeholder
*/

#include "my.h"

char *my_revstr(char *str)
{
    int len = 0;
    char tmp;

    for (int i = 0; str[i] != '\0'; i++)
        len++;
    for (int i = 0; i < len / 2; i++) {
        tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
    return str;
}
