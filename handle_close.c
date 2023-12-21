/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"
#include <SFML/Graphics/RenderWindow.h>

int handle_close(sfEvent *evt, my_window_t *wt)
{
    sfRenderWindow_close(wt->w);
    return 0;
}
