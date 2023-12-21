/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

double get_spawn_chance(my_window_t *wt)
{
    uint8_t alpha = sfSprite_getColor(wt->bgs[1]).a;

    return alpha / 255.;
}
