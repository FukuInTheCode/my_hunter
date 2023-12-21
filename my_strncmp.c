/*
** EPITECH PROJECT, 2023
** Pool Day 06
** File description:
** Placeholder
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (0 > n)
        n = 99999;
    for (; i < n && s1[i] && s2[i] && s1[i] == s2[i]; i++);
    if ((s1[i] == '\0' && s2[i] == '\0') || i == n)
        return 0;
    return s1[i] - s2[i];
}
