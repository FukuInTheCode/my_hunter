/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int display_setting(my_window_t *wt, my_duck_t *duck)
{
    int error = 0;

    if (wt->status == SETTINGS_AUD_ST)
        sfRenderWindow_drawSprite(wt->w, wt->bgs[8], NULL);
    if (wt->status == SETTINGS_VID_ST)
        sfRenderWindow_drawSprite(wt->w, wt->bgs[9], NULL);
    return error;
}
