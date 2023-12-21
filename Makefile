##
## EPITECH PROJECT, 2023
## settingup Makefile
## File description:
## Placeholder
##

NAME   = my_hunter

CC	   = gcc

CFLAGS = -Wall -Wextra -Wno-unused-value -Wno-sign-compare \
	-Wno-unused-parameter -I./include -g -std=c99 -lm

CSFML = -lcsfml-system -lcsfml-window -lcsfml-network \
			-lcsfml-graphics -lcsfml-audio

CRITERION = -lcriterion

SRC	= my_hunter.c \
	  manage_event.c \
	  game_loop.c \
	  display_game.c \
	  display_menu.c \
	  display_setting.c \
	  display_gameover.c \
	  handle_close.c \
	  handle_args.c \
	  handle_click.c \
	  handle_key.c \
	  handle_settings.c \
	  enemy.c \
	  my_strlen.c \
	  my_strncmp.c \
	  enemy_mouvement.c \
	  gen_enemy_var.c \
	  handle_game.c \
	  my_revstr.c \
	  my_put_nbr.c \

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(CSFML) \
	$(CRITERION)
clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
