/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int display_game(my_window_t *wt, my_duck_t *duck)
{
    int error = 0;

    update_enemy(wt, duck);
    sfRenderWindow_drawSprite(wt->w, wt->bgs[0], NULL);
    sfRenderWindow_drawSprite(wt->w, wt->bgs[1], NULL);
    sfRenderWindow_drawSprite(wt->w, duck->sprite, NULL);
    return error;
}
