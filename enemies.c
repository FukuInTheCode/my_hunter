/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"
#include <SFML/System/Vector2.h>

int draw_enemies(my_window_t *wt, my_duck_t *duck)
{
    int error = 0;

    for (; duck; duck = duck->next)
        sfRenderWindow_drawSprite(wt->w, duck->sprite, NULL);
    return error;
}

static my_duck_t *gen_enemy(my_window_t *wt, my_duck_t *ducks)
{
    my_duck_t *duck = malloc(sizeof(my_duck_t));
    sfIntRect r = {0, 0, 156, 133};
    sfTexture *t = sfTexture_createFromFile("assets/boo_sprite_sheet.png", &r);
    sfVector2u w_size = sfRenderWindow_getSize(wt->w);

    if (!duck)
        return NULL;
    duck->sprite = sfSprite_create();
    sfSprite_setTexture(duck->sprite, t, sfTrue);
    sfSprite_setPosition(duck->sprite, (sfVector2f){0., rand() %
        (w_size.y - r.height)});
    duck->next = ducks;
    return duck;
}

int add_enemy(my_window_t *wt, my_duck_t **ducks)
{
    *ducks = gen_enemy(wt, *ducks);
    return 0;
}
