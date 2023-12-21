/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static int setup_backgrounds2(my_window_t *wt, sfVector2u w_size)
{
    sfSprite_setScale(wt->bgs[5], (sfVector2f){25e-2, 25e-2});
    sfSprite_setScale(wt->bgs[4], (sfVector2f){5e-1, 5e-1});
    sfSprite_move(wt->bgs[5], (sfVector2f){0., w_size.y -
        sfSprite_getGlobalBounds(wt->bgs[5]).height});
    sfSprite_move(wt->bgs[4],
        (sfVector2f){sfSprite_getGlobalBounds(wt->bgs[5]).width / 1.33,
        w_size.y - sfSprite_getGlobalBounds(wt->bgs[4]).height});
    return 0;
}

static int inside_loop(my_window_t *wt, sfVector2u w_size, uint8_t i)
{
    sfVector2u t_size;
    sfColor col;
    sfTexture *t;

    t = sfTexture_createFromFile(paths[i], NULL);
    t_size = sfTexture_getSize(t);
    wt->bgs[i] = sfSprite_create();
    sfSprite_setTexture(wt->bgs[i], t, sfFalse);
    sfSprite_setScale(wt->bgs[i], (sfVector2f){w_size.x / (float)t_size.x,
        w_size.y / (float)t_size.y});
    col = sfSprite_getColor(wt->bgs[i]);
    col.a = 255 * (i != 1);
    sfSprite_setColor(wt->bgs[i], col);
    return 0;
}

static int setup_backgrounds(my_window_t *wt)
{
    sfVector2u w_size;

    wt->w = sfRenderWindow_create((sfVideoMode){1200, 675, 32}, "my_hunter",
        sfTitlebar | sfClose | sfResize, NULL);
    w_size = sfRenderWindow_getSize(wt->w);
    for (uint8_t i = 0; i < 6; i++)
        inside_loop(wt, w_size, i);
    return setup_backgrounds2(wt, w_size);
}

static int free_all(my_window_t *wt)
{
    int error = 0;

    sfRenderWindow_destroy(wt->w);
    sfSprite_destroy(wt->bgs[0]);
    sfSprite_destroy(wt->bgs[1]);
    sfSprite_destroy(wt->bgs[2]);
    sfSprite_destroy(wt->bgs[3]);
    sfSprite_destroy(wt->bgs[4]);
    sfSprite_destroy(wt->bgs[5]);
    sfClock_destroy(wt->clock);
    return error;
}

int main(int argc, char **argv, char **envp)
{
    int error = 0;
    my_window_t wt = {
        NULL,
        (sfSprite *[6]){(sfSprite *)NULL, (sfSprite *)NULL, (sfSprite *)NULL,
        (sfSprite *)NULL, (sfSprite *)NULL, (sfSprite *)NULL},
        MENU_ST,
        sfClock_create(),
        0,
        3,
        0,
    };
    my_duck_t *duck = NULL;

    srand(time(0));
    if (handle_args(argc, argv, envp) == 84)
        return 84 + free_all(&wt);
    error |= setup_backgrounds(&wt);
    duck = gen_enemy(&wt);
    error |= game_loop(&wt, duck);
    error |= free_all(&wt);
    return error;
}
