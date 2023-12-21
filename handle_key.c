/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int handle_key(sfEvent *evt, my_window_t *wt)
{
    if (evt->key.code != sfKeyEscape)
        return 0;
    if (wt->status == SETTINGS_VID_ST ||
        wt->status == SETTINGS_AUD_ST)
        wt->status = MENU_ST;
    return 0;
}
