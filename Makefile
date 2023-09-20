NAME		=	cub3d
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -g

LIBFT_PATH	=	./inc/libft/
LIBFT_FILE	=	libft.a
LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

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

$(NAME): lib $(OBJ)
		@echo "\nCOMPILING CUB3D...\n"
		$(CC) $(FLAGS) $(OBJ) $(LIBFT_LIB) -I$(INC_DIR) -o $(NAME)

clean:
		@make clean -sC $(LIBFT_PATH)
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)
		@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re
