# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: darkwater <marvin@42.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 20:18:43 by darkwater         #+#    #+#              #
#    Updated: 2024/03/30 22:56:13 by lstephen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fractol

SRC				= main.c				\
				mandelbrot.c			\
				julia.c					\
				print_set.c				\
				utils.c					\
				colour_manipulation.c	\
				hook_testing.c			\
				event_handling.c		\
				mlx_setup.c				\

SRC_DIR			= ./src/

SRC_PRE			= $(addprefix $(SRC_DIR), $(SRC))

OBJS			= $(SRC_PRE:.c=.o)

OBJ_OUTPUT		= .output

HEADER			= ./includes/

LIBFT			= libft.a

LIBFT_DIR		= ./libft/

LIBFT_PRE		= $(addprefix $(LIBFT_DIR), $(LIBFT))

MLX				= mlx

MLX_NAME		= libmlx.dylib

MLX_DIR			= ./mlx_swift/

MLX_PRE			= $(addprefix $(MLX_DIR), $(MLX_NAME))

CC				= cc

CFLAGS			= -Wall -Wextra -Werror -Wpedantic

# ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Colours  ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ #

RED				= \033[0;31m

GREEN			= \033[0;32m

NC				= \033[0m

# ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Messages ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ #

BEGIN_COMP		= echo "\n ~ ~ ~ $(GREEN)Compiling Objects$(NC) ~ ~ ~\n"

PROGRAM_COMP	= echo "\n ~ ~ ~ $(GREEN)Compiling Program$(NC) ~ ~ ~\n"

MLX_BUILD		= echo "\n ~ ~ ~ $(GREEN)Building MiniLibX$(NC) ~ ~ ~\n"

MLX_CLEAN_MSG	= echo "\n ~ ~ ~ $(RED)Cleaning  MiniLibX$(NC) ~ ~ ~\n"

CLEAN_MSG		= echo "\n ~ ~ ~ $(RED)Cleaning all object files$(NC) ~ ~ ~\n"

FCLEAN_MSG		= echo "\n ~ ~ ~ $(RED)Removing Programs$(NC) ~ ~ ~\n"

# ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Rules ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ #

all: $(NAME)

$(NAME): $(LIBFT_PRE) $(MLX_PRE) $(OBJ_OUTPUT) $(OBJS)
#$(NAME): $(LIBFT_PRE) $(OBJ_OUTPUT) $(OBJS)
	@$(PROGRAM_COMP)
	@#$(CC) $(CFLAGS) $(OBJS) -lm -L$(LIBFT_DIR) -lft -o $(NAME)
	$(CC) $(CFLAGS) $(OBJS) -lm -L$(LIBFT_DIR) -lft -L./ -l$(MLX) -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT_PRE):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_PRE):
	@$(MLX_BUILD)
	$(MAKE) -C $(MLX_DIR)

$(OBJ_OUTPUT):
	@$(BEGIN_COMP)
	@touch .output

%.o: %.c
	@#$(CC) $(CFLAGS) -c -I $(HEADER) $< -o $@
	$(CC) $(CFLAGS) -c $(SIZE_X) $(SIZE_Y) -I $(HEADER) -I $(MLX_DIR) $< -o $@

clean:
	@$(MLX_CLEAN_MSG)
	@$(MAKE) clean -C $(MLX_DIR)
	@$(CLEAN_MSG)
	$(RM) $(OBJ_OUTPUT) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	@$(FCLEAN_MSG)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
