/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int display_menu(my_window_t *wt, my_duck_t *duck)
{
    int error = 0;

    sfRenderWindow_drawSprite(wt->w, wt->bgs[2], NULL);
    sfRenderWindow_drawSprite(wt->w, wt->bgs[6], NULL);
    sfRenderWindow_drawSprite(wt->w, wt->bgs[7], NULL);
    return error;
}
