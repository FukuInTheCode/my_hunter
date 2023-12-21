##
## EPITECH PROJECT, 2023
## settingup Makefile
## File description:
## Placeholder
##

NAME   = my_hunter

CC	   = gcc

CFLAGS = -Wall -Wextra -Wno-unused-value -Wno-sign-compare \
	-Wno-unused-parameter -I./include -g -std=c99

CSFML = -lcsfml-system -lcsfml-window -lcsfml-network \
			-lcsfml-graphics -lcsfml-audio

CRITERION = -lcriterion

SRC	= my_hunter.c \
	  manage_event.c \
	  enemies.c \
	  game_loop.c \
	  display_game.c \
	  handle_close.c \

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
