/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static int handle_audio(my_window_t *wt)
{
    char tmp[1001] = {0};
    sfVector2f offset = {0, sfSprite_getGlobalBounds(wt->bgs[8]).height};

    sfText_setPosition(wt->text, offset);
    sfRenderWindow_drawSprite(wt->w, wt->bgs[8], NULL);
    sfRenderWindow_drawText(wt->w, wt->text, NULL);
    sfText_setString(wt->text,
        my_put_nbr((int)sfMusic_getVolume(wt->music), tmp));
    return 0;
}

int display_setting(my_window_t *wt, my_duck_t *duck)
{
    int error = 0;

    if (wt->status == SETTINGS_AUD_ST)
        handle_audio(wt);
    if (wt->status == SETTINGS_VID_ST)
        sfRenderWindow_drawSprite(wt->w, wt->bgs[9], NULL);
    return error;
}
