#ifndef CUB3D_H
# define CUB3D_H

# include "../src/get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>
#include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define HEIGHT 750
# define WIGHT 750

typedef struct s_parse_map
{
	char		**map_parse;
	char		**map;
	int			fd;
	int			width;
	int			height;
}				t_parse_map;

typedef struct s_textures
{
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
}				t_textures;

typedef struct s_colors
{
	int			red;
	int			green;
	int			blue;
}				t_colors;

typedef struct s_main
{
	char		**map;
	t_parse_map	*parse_map;
	t_colors	colors_floor;
	t_colors	colors_ceiling;
	t_textures	textures;
}				t_main;

typedef struct s_image
{
	void		*img;
	char		*data_addr;
	int			bpp;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_cub
{
	char		**map;
	void		*mlx;
	void		*win;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;

	double		planex;
	double		planey;

	double		raydirx;
	double		raydiry;

	int			mapx;
	int			mapy;
	
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	double		dist_to_wall;
	int			draw_start;
	int			draw_end;
	double		camerax;
	double		time;
	double 		oldtime; // pour les fps
	t_image		*img;
	t_main		*data;
	t_colors	colors_ceiling;
	t_colors	colors_floor;
	t_textures	textures;
}				t_cub;

/*PARSING DIRECTORY*/

int				check_format(char *s);
int				check_args(int argc, char *av[]);
int				parsing(int argc, char *argv[], t_main *data);
size_t			ft_tablen(char **tab);
char			**ft_tabdup(char **tab);
int				check_format(char *s);
void			init_values(t_main *data);
int				is_not_valid_char(char c);
void			free_tab(char **tab);
void			print_tab(char **tab);
int				longest_len(char **map);

void			check_colors(t_main *data, t_colors colors);
void			check_colors_str(t_main *data, char **tab);
int				get_colors(t_main *data, char *str);

void			add_space(char *str, int size);
int				check_map_str(char *str);
int				get_textures(t_main *data, char *str);
int				init_textures(t_main *data, char **map);
int				init_map(t_parse_map *parser, char *map_name);


//main cub
void			go_cub(t_main *data);
//init
void	init_value(t_cub *cub, t_main *data);
double	start_pos(char **tab, int ok);

// img
void			put_pixel(t_cub *cub, int x, int y, int color);
void			img_init(t_cub *cub);
// utils
int	what_lentab(char **tab);
double	get_start_pos(t_cub *cub, int ok);

#endif
