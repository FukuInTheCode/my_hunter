/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "include/my.h"
#include "my.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>

static int game_loop(my_window_t *wt)
{
    int error = 0;

    for (; sfRenderWindow_isOpen(wt->w);) {
        sfRenderWindow_drawSprite(wt->w, wt->bgs[0], NULL);
        sfRenderWindow_display(wt->w);
    }
    return error;
}

static int setup_backgrounds(sfSprite *bgs[2])
{
    int error = 0;
    sfTexture *bg1 = sfTexture_createFromFile(
        "./assets/background_day.png", NULL);

    bgs[0] = sfSprite_create();
    sfSprite_setTexture(bgs[0], bg1, sfTrue);
    return error;
}

static int free_all(my_window_t *wt)
{
    int error = 0;

    sfRenderWindow_destroy(wt->w);
    sfSprite_destroy(wt->bgs[0]);
    return error;
}

int main(int argc, char **argv)
{
    int error = 0;
    my_window_t wt = {
        sfRenderWindow_create((sfVideoMode){1080, 720, 32}, "my_hunter",
        sfTitlebar| sfClose | sfResize, NULL),
        (sfSprite *[2]){(sfSprite *)NULL, (sfSprite *)NULL}
    };

    error |= setup_backgrounds(wt.bgs);
    error |= game_loop(&wt);
    error |= free_all(&wt);
    return error;
}
