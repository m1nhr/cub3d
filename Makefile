# Variables

NAME    =    cub3D

CC        =    cc
FLAG    =    -Wall -Wextra -Werror -g

DIRLIB    =    ./inc/libft/
FILELIB    =    libft.a
NAMELFT    =    $(addprefix $(DIRLIB), $(FILELIB))

FLAGMLX    =    -L ./inc/minilibx-linux/ -lmlx -lX11 -lXext -g3 -lm
DIRMLX    =    ./inc/minilibx-linux/
MLXFILE    =    libmlx.a
MLXEXE    =     $(addprefix $(DIRMLX), $(MLXFILE)) $(FLAGMLX)

SRC_DIR    =    src/
OBJ_DIR =    obj/
INCLUDE    =    -I./inc -I./inc/minilibx-linux -I./inc/libft


# Colors

DEF_COLOR    = \033[0;39m
GRAY         = \033[0;90m
RED         = \033[0;91m
GREEN         = \033[0;92m
YELLOW         = \033[0;93m
BLUE        = \033[0;94m
MAGENTA        = \033[0;95m
CYAN        = \033[0;96m
WHITE        = \033[0;97m

# Sources



FILES    =  main/main \
			get_next_line/get_next_line \
			get_next_line/get_next_line_utils \
			cub/cub cub/display_cub \
			cub/draw cub/ending \
			cub/event cub/img_stuff \
			cub/init_raycasting \
			cub/move \
			cub/rays \
			cub/utils \
			parsin/parsing \
			parsin/utils \
			parsin/parsing_utils \
			parsin/parse_textures \
			parsin/parse_map \
			parsin/parse_colors
	

SRCS    =    $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS    =    $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

OBJF    =    .cache_exists

$(OBJF)    :
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/parsin
	@mkdir -p $(OBJ_DIR)/main
	@mkdir -p $(OBJ_DIR)/cub
	@mkdir -p $(OBJ_DIR)/get_next_line

all        :    lib mlx $(NAME)

lib:
	@echo "$(YELLOW)COMPILING $(DIRLIB)$(DEF_COLOR)"
	@make -C $(DIRLIB)

mlx:
	@echo "$(YELLOW)COMPILING $(DIRMLX)...$(DEF_COLOR)"
	@make -sC $(DIRMLX)
	@echo "$(GREEN)MLX_lib created$(DEF_COLOR)"

$(NAME)    :  $(OBJS) Makefile inc/minilibx-linux/mlx.h inc/libft/libft.h
	@echo "$(YELLOW)COMPILING Cub3D...$(DEF_COLOR)"
	@$(CC) $(FLAG) $(OBJS) $(NAMELFT) $(MLXEXE) $(INCLUDE) -o $(NAME)
	@echo "$(GREEN)Cub3D compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o    :    $(SRC_DIR)%.c  inc/cub3d.h | $(OBJF) 
	$(CC) $(FLAG) $(INCLUDE) -c $< -o $@

clean    :
	@make clean -sC $(DIRMLX)
	@echo "$(MAGENTA)Minilibx objects cleaned!$(DEF_COLOR)"
	@make clean -sC $(DIRLIB)
	@rm -rf $(OBJ_DIR)
	@$(RM) -f $(OBJF)
	@echo "$(MAGENTA)Cub3D objects cleaned!$(DEF_COLOR)"

fclean    :    clean
	@rm -f $(NAME)
	@rm -f $(NAMELFT)
	@echo "$(YELLOW)Libft cleaned!$(DEF_COLOR)"
	@echo "$(YELLOW)Cub3D executable cleaned!$(DEF_COLOR)"

re        :    fclean all
	@echo "$(GREEN)Cleaned and rebuilt!$(DEF_COLOR)"

.PHONY    :    all clean fclean re