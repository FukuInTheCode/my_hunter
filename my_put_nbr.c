/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** new my_put_nbr for myprintf
*/

#include "include/my.h"
#include "my.h"

char *my_put_nbr(int nb, char buffer[1000])
{
    char tmp;
    long nb2 = nb;

    for (int i = 0; i < 1000; buffer[i++] = 0);
    if (nb2 < 0)
        nb2 = -nb2;
    if (nb == 0 || nb == -0)
        buffer[my_strlen(buffer)] = '0';
    for (; nb2 != 0 ; nb2 = nb2 / 10) {
        tmp = (nb2 % 10) + 48;
        buffer[my_strlen(buffer)] = tmp;
    }
    my_revstr(buffer);
    return (buffer);
}
