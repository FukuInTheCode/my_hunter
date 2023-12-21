/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static int setup_backgrounds(my_window_t *wt)
{
    char *paths[] = {"./assets/background_day.png",
        "./assets/background_night.jpg"};
    sfTexture *t;
    sfVector2u w_size = sfRenderWindow_getSize(wt->w);
    sfVector2u t_size;
    sfColor col;

    for (uint8_t i = 0; i < 2; i++) {
        t = sfTexture_createFromFile(paths[i], NULL);
        t_size = sfTexture_getSize(t);
        wt->bgs[i] = sfSprite_create();
        sfSprite_setTexture(wt->bgs[i], t, sfFalse);
        sfSprite_setScale(wt->bgs[i],
            (sfVector2f){w_size.x / (float)t_size.x,
            w_size.y / (float)t_size.y});
        col = sfSprite_getColor(wt->bgs[i]);
        col.a = 255 * (i == 0);
        sfSprite_setColor(wt->bgs[i], col);
    }
    return 0;
}

static int free_all(my_window_t *wt)
{
    int error = 0;

    sfRenderWindow_destroy(wt->w);
    sfSprite_destroy(wt->bgs[0]);
    return error;
}

int main(int argc, char **argv, char **envp)
{
    int error = 0;
    my_window_t wt = {
        sfRenderWindow_create((sfVideoMode){1200, 675, 32}, "my_hunter",
        sfTitlebar| sfClose | sfResize, NULL),
        (sfSprite *[2]){(sfSprite *)NULL, (sfSprite *)NULL},
        GAME_ST
    };
    my_duck_t *ducks = NULL;

    srand(time(0));
    add_enemy(&wt, &ducks);
    error |= setup_backgrounds(&wt);
    error |= game_loop(&wt, &ducks);
    error |= free_all(&wt);
    return error;
}
