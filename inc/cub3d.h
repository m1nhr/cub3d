/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 04:47:12 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/22 12:18:32 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../src/get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>

# define WIDTH 1000
# define HEIGHT 1000
# define TRUE 1
# define FALSE 0

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
	int			height;
	int			width;
	int			textdir;
	double		wallx;
	int			texx;
	int			texy;
	double		step;
	double		texpos;
}				t_textures;

typedef struct s_colors
{
	int			red;
	int			green;
	int			blue;
}				t_colors;

typedef struct s_bool
{
	int			key;
	int			ok;
}				t_bool;

typedef struct s_img
{
	void		*mlx;
	void		*win;

	void		*img;
	char		*data_addr;
	int			bpp;
	int			line_size;
	int			endian;
}				t_img;

typedef struct s_main
{
	char		**map;
	t_parse_map	*parse_map;
	t_colors	colors_floor;
	t_colors	colors_ceiling;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
}				t_main;

typedef struct s_cub
{
	char		**map;
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
	int			lineheight;
	int			draw_start;
	int			draw_end;
	double		camerax;
	char		*sno;
	char		*sso;
	char		*swe;
	char		*sea;
	double		wall_x;
	int			texx;
	int			texy;
	double		tex_pos;
	double		walk;
	int			mouse_x;
	int			mouse_on;
	int			cam_mouse_right;
	int			cam_mouse_left;
	t_bool		*move;
	t_bool		*go_w;
	t_bool		*go_s;
	t_bool		*go_a;
	t_bool		*go_d;
	t_bool		*cam_right;
	t_bool		*cam_left;
	t_img		*img;
	t_img		*texture1;
	t_img		*texture2;
	t_img		*texture3;
	t_img		*texture4;
	t_main		*data;
	t_colors	colors_ceiling;
	t_colors	colors_floor;
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
void			check_colors(t_main *data, t_colors colors, char **tab);
void			check_colors_str(t_main *data, char **tab);
int				get_colors(t_main *data, char *str);
void			add_space(char *str, int size);
int				check_map_str(char *str);
int				get_textures(t_main *data, char *str);
int				init_textures(t_main *data, char **map);
int				init_map(t_parse_map *parser, char *map_name);
void			free_textures(t_main *data);
int				check_textures(t_main *data);

/*RAYCASTING DIRECTORY*/
void			go_cub(t_main *data);
//init
void			init_value(t_cub *cub, t_main *data);
//event
int				motion_mouse(int x, int y, t_cub *cub);
int				key_release(int key, t_cub *cub);
int				key_press(int key, t_cub *cub);
void			keymap_event(t_cub *cub);
//display
int				display_game_frame(t_cub *cub);
//rays
void			init_raydir_delta(t_cub *cub, int x);
void			init_sidedist(t_cub *cub);
void			throw_rays(t_cub *cub);
//draw
void			draw_total_frame(t_cub *cub, int x, int y, int lineheight);
void			get_draw_point(t_cub *cub);
//move
void			cam_movement(t_cub *cub, int key, double rt);
void			user_movement(t_cub *cub, int key);
//img
int				get_color(t_cub *cub, t_img *texture);
int				get_rgb(t_cub *cub, int ok);
void			put_pixel(t_cub *cub, int x, int y, int color);
void			put_x10(t_cub *cub, int x, int y, int color);
//ending
int				close_window(t_cub *cub);
void			error_alloc(t_cub *cub, char *str);
int				error_ok(char *str, int ok);
// utils
int				what_lentab(char **tab);
double			start_pos(char **tab, int ok);
void			error_void(char *str);
float			ft_fabs(float i);
char			**good_map(t_cub *cub, t_main *data, char **old);

#endif
