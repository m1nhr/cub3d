#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "../src/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>

typedef struct s_parse_map
{
	char	**map_parse;
    char    **map;
	int		fd;
	int		width;
	int		height;
}	t_parse_map;

typedef struct s_main
{
	char		**map;
	t_parse_map	*parse_map;
}	t_main;

/*PARSING DIRECTORY*/
int	check_format(char *s);
int	check_args(int argc, char *av[]);
int	parsing(int argc, char *argv[], t_main *data);

#endif
