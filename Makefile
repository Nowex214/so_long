SHELL = /bin/sh

NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I$(MINILIBX_DIR) -I$(LIBFT_DIR)
MINIFLAGS = -L$(MINILIBX_DIR) -lmlx -L/usr/X11/lib -lXext -lX11 -lm -lbsd 
AR = ar rcs
RM = rm -f

LIBFT_DIR = libft
MINILIBX_DIR = minilibx-linux
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX = $(MINILIBX_DIR)/libmlx.a

SRCS = srcs/graphics/graphics.c\
		srcs/core/main.c\
		srcs/core/read_map.c\
		srcs/control/control.c\
		srcs/tools/camera.c\
		srcs/tools/found.c\
		srcs/control/mouvement.c\
		srcs/tools/hud.c\
		srcs/animation/idle_anim.c\
		srcs/animation/walk_anim.c\
		srcs/player/player.c\
		srcs/graphics/load_image.c\
		srcs/core/game.c\
		srcs/player/player_mouvement.c\
		srcs/graphics/load_image2.c\
		srcs/animation/other_anim.c\
		srcs/core/free.c\
		srcs/enemy/enemy.c\
		srcs/enemy/enemy_mouv.c\
		srcs/core/error.c\
		srcs/core/init.c\
		srcs/core/free2.c\
		srcs/core/reachable.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINIFLAGS) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	@$(MAKE) -C $(MINILIBX_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re