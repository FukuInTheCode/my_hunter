/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int display_game(my_window_t *wt)
{
    int error = 0;

    sfRenderWindow_drawSprite(wt->w, wt->bgs[0], NULL);
    sfRenderWindow_drawSprite(wt->w, wt->bgs[1], NULL);
    return error;
}
