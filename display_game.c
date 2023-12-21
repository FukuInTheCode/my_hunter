/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static int display_score(my_window_t *wt)
{
    char str[1010] = {0};
    char *base_str = "SCORE : ";

    for (int i = 0; i++ < 8; str[i - 1] = base_str[i - 1]);
    my_put_nbr(wt->score, str + 8);
    sfText_setString(wt->text, str);
    sfRenderWindow_drawText(wt->w, wt->text, NULL);
    return 0;
}

int display_game(my_window_t *wt, my_duck_t *duck)
{
    int error = 0;
    uint64_t elapsed = sfClock_getElapsedTime(wt->clock).microseconds;
    sfColor col = sfSprite_getColor(wt->bgs[1]);

    update_enemy(wt, duck);
    sfRenderWindow_drawSprite(wt->w, wt->bgs[0], NULL);
    sfRenderWindow_drawSprite(wt->w, wt->bgs[1], NULL);
    sfRenderWindow_drawSprite(wt->w, duck->sprite, NULL);
    display_score(wt);
    if (elapsed / 1e5 - wt->bg_n > 1.) {
        col.a += (wt->is_day - !wt->is_day);
        if (col.a == 255 || col.a == 0)
            wt->is_day = !wt->is_day;
        wt->bg_n++;
    }
    sfSprite_setColor(wt->bgs[1], col);
    return error;
}
