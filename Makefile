NAME		=	cub3d
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -g

LIBFT_PATH	=	./inc/libft/
LIBFT_FILE	=	libft.a
LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))
MLX_PATH	= 	./inc/minilibx-linux/
MLX_FILE	= 	libmlx_Linux.a
MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))
LIBFLAGS 	= -I../inc/minilibx-linux/libmlx_Linux.a -L inc/minilibx-linux/ -lmlx -lX11 -lXext -lm -g

C_FILES		=	$(wildcard ./src/*/*.c)
INC_DIR		=	./inc/
OBJ			=	$(C_FILES:.c=.o)

.c.o:
		$(CC) $(FLAGS) -I$(INC_DIR) -c $< -o $@

all:	$(NAME)

lib:
		@echo "\nCOMPILING $(LIBFT_PATH)\n"
		@make -C $(LIBFT_PATH)
		@echo "$(LIBFT_LIB) created\n"

mlx:
		@echo "\nCOMPILING $(MLX_PATH)\n"
		@make -C $(MLX_PATH)
		@echo "$(MLX_LIB) created\n"


$(NAME): lib mlx $(OBJ)
		@echo "\nCOMPILING CUB3D...\n"
		$(CC) $(FLAGS) $(OBJ) $(LIBFLAGS) $(MLX_LIB) $(LIBFT_LIB) -I$(INC_DIR) -o $(NAME)

clean:
		@make clean -sC $(LIBFT_PATH)
		@make clean -sC $(MLX_PATH)
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)
		@make fclean -C $(LIBFT_PATH)
#		@make fclean -C $(MLX_PATH)

re: fclean all

.PHONY: all clean fclean re
