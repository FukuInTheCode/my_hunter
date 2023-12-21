/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int display_gameover(my_window_t *wt, my_duck_t *duck)
{
    int error = 0;

    sfRenderWindow_drawSprite(wt->w, wt->bgs[3], NULL);
    sfRenderWindow_drawSprite(wt->w, wt->bgs[4], NULL);
    sfRenderWindow_drawSprite(wt->w, wt->bgs[5], NULL);
    return error;
}
