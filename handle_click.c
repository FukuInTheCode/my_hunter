/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"
#include <SFML/Graphics/Rect.h>

static int handle_click_game(sfVector2i mouse_pos,
    my_window_t *wt, my_duck_t *duck)
{
    sfFloatRect sprite_rect = sfSprite_getGlobalBounds(duck->sprite);
    sfVector2u w_size = sfRenderWindow_getSize(wt->w);

    if (sfFloatRect_contains(&sprite_rect, mouse_pos.x, mouse_pos.y)) {
        sfSprite_move(duck->sprite,
            (sfVector2f){w_size.x * 3., w_size.y * 3.});
        update_enemy(wt, duck);
        wt->score++;
    } else {
        wt->lives--;
    }
    if (wt->lives == 0)
        wt->status = GAMEOVER_ST;
    return 0;
}

static int handle_click_gameover(sfVector2i mouse_pos, my_window_t *wt,
    my_duck_t *duck)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(wt->bgs[4]);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(wt->bgs[5]);
    sfColor col = sfSprite_getColor(wt->bgs[1]);

    wt->lives = 3;
    wt->score = 0;
    col.a = 0;
    sfSprite_setColor(wt->bgs[1], col);
    wt->is_day = true;
    if (sfFloatRect_contains(&rect, mouse_pos.x, mouse_pos.y))
        wt->status = GAME_ST;
    if (sfFloatRect_contains(&rect2, mouse_pos.x, mouse_pos.y))
        wt->status = MENU_ST;
    return 0;
}

static int handle_click_menu(sfVector2i mouse_pos, my_window_t *wt,
    my_duck_t *duck)
{
    sfVector2u w_size = sfRenderWindow_getSize(wt->w);
    sfFloatRect rect = sfSprite_getGlobalBounds(wt->bgs[6]);

    if (sfFloatRect_contains(&rect, mouse_pos.x, mouse_pos.y)) {
        wt->status = GAME_ST;
        wt->lives = 3;
        wt->score = 0;
        sfSprite_move(duck->sprite, (sfVector2f){0., w_size.y * 4.});
    }
    return 0;
}

int handle_click(sfEvent *evt, my_window_t *wt, my_duck_t *duck)
{
    sfVector2i mouse_pos = {evt->mouseButton.x, evt->mouseButton.y};

    if (wt->status == MENU_ST)
        return handle_click_menu(mouse_pos, wt, duck);
    if (wt->status == GAMEOVER_ST)
        return handle_click_gameover(mouse_pos, wt, duck);
    if (wt->status == GAME_ST)
        return handle_click_game(mouse_pos, wt, duck);
    return 0;
}
