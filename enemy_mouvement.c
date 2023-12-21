/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int linear_movement(my_window_t *wt, my_duck_t *duck)
{
    sfVector2f sprite_pos = sfSprite_getPosition(duck->sprite);

    sprite_pos.x += (duck->is_right - !duck->is_right)
        * 1 * (wt->score + 1.);
    sprite_pos.y = duck->linear_y;
    sfSprite_setPosition(duck->sprite, sprite_pos);
    return 0;
}

int sin_movement(my_window_t *wt, my_duck_t *duck)
{
    sfVector2f sprite_pos;
    sfVector2u w_size = sfRenderWindow_getSize(wt->w);

    linear_movement(wt, duck);
    sprite_pos = sfSprite_getPosition(duck->sprite);
    sprite_pos.y = duck->sin_a[0] * sin(sprite_pos.x / w_size.x
        + duck->sin_a[1]) + duck->sin_a[2];
    sprite_pos.y *= w_size.y;
    sfSprite_setPosition(duck->sprite, sprite_pos);
    return 0;
}

func choose_movement_function(void)
{
    if (rand() % 2)
        return sin_movement;
    return linear_movement;
}
