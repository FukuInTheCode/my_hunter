/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static sfTexture *set_texture(my_window_t *wt, my_duck_t *duck)
{
    double spawn_rate = get_spawn_chance(wt);

    return duck->skins[rand() % 1001 < spawn_rate * 100];
}

static int gen_enemy_info(my_window_t *wt, my_duck_t *duck)
{
    sfVector2u w_size = sfRenderWindow_getSize(wt->w);
    sfIntRect sprite_rect = {0, 0, 154, 134};

    sfSprite_setTexture(duck->sprite, set_texture(wt, duck), sfTrue);
    duck->is_right = rand() % 2;
    sfSprite_setTextureRect(duck->sprite, sprite_rect);
    sfSprite_setRotation(duck->sprite, 0);
    sfSprite_setScale(duck->sprite, (sfVector2f){1, 1});
    sfSprite_setPosition(duck->sprite,
        (sfVector2f){w_size.x * !duck->is_right, w_size.y / 2. - 134. / 2.});
    if (duck->is_right)
        sfSprite_scale(duck->sprite, (sfVector2f){-1, 1});
    duck->move = choose_movement_function();
    duck->move_n = sfClock_getElapsedTime(wt->clock).microseconds / 2e4;
    gen_var(wt, duck);
    return 0;
}

static int move_enemy(my_window_t *wt, my_duck_t *duck,
    sfInt64 elapsed)
{
    if (elapsed / 2e4 - duck->move_n > 1.) {
        duck->move_n++;
        duck->move(wt, duck);
    }
    return 0;
}

int update_enemy(my_window_t *wt, my_duck_t *duck)
{
    sfVector2f duck_pos;
    sfVector2u w_size = sfRenderWindow_getSize(wt->w);
    sfInt64 elapsed = sfClock_getElapsedTime(wt->clock).microseconds;
    sfIntRect sprite_rect = sfSprite_getTextureRect(duck->sprite);

    move_enemy(wt, duck, elapsed);
    if (elapsed / 5e5 - duck->anim_n > 1.) {
        sprite_rect.left = 154 * (rand() % 27);
        duck->anim_n++;
    }
    duck_pos = sfSprite_getPosition(duck->sprite);
    if ((duck->is_right && duck_pos.x > w_size.x + 161) ||
        duck_pos.y > w_size.y)
        gen_enemy_info(wt, duck);
    if (!duck->is_right && duck_pos.x < -161)
        gen_enemy_info(wt, duck);
    sfSprite_setTextureRect(duck->sprite, sprite_rect);
    return 0;
}

my_duck_t *gen_enemy(my_window_t *wt)
{
    my_duck_t *duck = malloc(sizeof(my_duck_t));
    duck->skins[0] = sfTexture_createFromFile("./assets/boo_sprite_sheet.png",
        NULL);

    duck->sprite = sfSprite_create();
    duck->anim_n = 0;
    gen_enemy_info(wt, duck);
    return duck;
}
