/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int gen_var(my_window_t *wt, my_duck_t *duck)
{
    sfVector2u w_size = sfRenderWindow_getSize(wt->w);

    if (duck->move == linear_movement)
        duck->linear_y = rand() % (w_size.y - duck->sprite_rect.height);
    if (duck->move == sin_movement)
        for (int i = 0; i < 3; i++)
            duck->sin_a[i] = (rand() % 11) / 10.;
    return 0;
}
