/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarecar <rmarecar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 00:28:53 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/09/27 18:11:07 by rmarecar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	close_window(t_cub *cub)
{
	ft_putendl_fd("goodbye :)", 1);
	mlx_destroy_image(cub->mlx, cub->img->img);
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_display(cub->mlx);
	free (cub->img);
	free (cub->data);
	exit (1);
	return (0);
}

/*
dirX et dirY représentent la direction du joueur, 
et planeX et planY le plan de la caméra du joueur. 
Assurez-vous que le plan de la caméra est perpendiculaire 
à la direction, mais vous pouvez en modifier la longueur. 
Le rapport entre la longueur de la direction et le plan de la 
caméra détermine le FOV, ici le vecteur direction est 
un peu plus long que le plan de la caméra, donc le FOV sera 
inférieur à 90° (plus précisément, 
le FOV est de 2 * atan(0,66 /1.0)=66°, ce qui est parfait 
pour un jeu de tir à la première personne). 
Plus tard, lors d'une rotation avec les touches de saisie, 
les valeurs de dir et plane seront modifiées, mais elles 
resteront toujours perpendiculaires et garderont la même longueur.*/

double	get_start_pos(t_cub *cub, int ok)
{
	int	x;
	int	y;

	y = 0;
	while (cub->map[y])
	{
		x = 0;
		while (cub->map[y][x])
		{
			if (cub->map[y][x] == 'N' || cub->map[y][x] == 'S'
				|| cub->map[y][x] == 'E' || cub->map[y][x] == 'W')
			{
				if (ok)
					return (x);
				else
					return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	init_value(t_cub *cub)
{
	cub->posX = get_start_pos(cub, 1);
	cub->posY = get_start_pos(cub, 0);	// position de depart x et y;
	cub->dirX = -1;
	cub->dirY = 0; 	// vexteur de direction initial
	cub->planeX = 0;
	cub->planeY = 0.66; // version RC 2d du plan de la cam
	cub->time = 0; // time of current frame
	cub->oldtime = 0; //time of previous frame
}

void	put_x10(t_cub *cub, int x, int y, int color)
{
	int tmpx;
	int tabsize;
	int ok;

	tabsize = 0;
	while (cub->map[tabsize])
		tabsize++;
	while (y <= tabsize * 6)
	{
		tmpx = x;
		ok = 0;
		while ((size_t)tmpx < (ft_strlen(cub->map[ok]) - 1) * 6)
		{
			put_pixel(cub, tmpx, y, color);
			tmpx++;
		}
		y++;
	}
}

int	what_lentab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	display_minimap(t_cub *cub)
{
 	int x;
	int y;
	int lentab;
	int y_tab;
	int i;

	y = 0;
	y_tab = 0;
	lentab = what_lentab(cub->map);
	while (y_tab < lentab)
	{
		x = 0;
		i = 0;
		while ((size_t)i < ft_strlen(cub->map[y_tab]))
		{
			if (cub->map[y_tab][i] == '1')
				put_x10(cub, x, y, 0x000000);
			else if (cub->map[y_tab][i] == 'N' || cub->map[y_tab][i] == 'S'
				|| cub->map[y_tab][i] == 'E' || cub->map[y_tab][i] == 'W')
				put_x10(cub, x, y, 0xFF0000);
			else if (cub->map[y_tab][i] == '0' || !cub->map[y_tab][i])
				put_x10(cub, x, y, 0x13C6A2);
			x += 6;
			i++;
		}
		y += 6;
		y_tab++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img, 0, 2);
}

void	display_win(t_cub *cub, int height, int wight)
{
	int x;
	int y = 0;
	while (y < height)
	{
		x = 0;
		while (x < wight)
			put_pixel(cub, x++, y, 0xA1A1A1);
		y++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img, 0, 2);
}

void    init_cub(t_main *data, t_cub *cub)
{
	cub->map = data->map;
	cub->colors_ceiling = data->colors_ceiling;
	cub->colors_floor = data->colors_floor;
	cub->textures = data->textures;
	cub->mlx = mlx_init();
	if (!cub->mlx)
		exit (1);
	cub->win = mlx_new_window(cub->mlx, 750, 750, "CUB3D");
	if (!cub->win)
		exit (1);
	init_value(cub);
	img_init(cub);
//	img_init(data); 
//	mlx_hook(data->win, 2, 1L << 0, &keymap, data);
//	mlx_mouse_hook(data->win, &ctrl_mouse, data);
	mlx_hook(cub->win, 17, 1L << 17, &close_window, data);
	int i =0;
	while (cub->map[i])
	{
		fprintf(stderr, "%s = %d\n", cub->map[i], i);
		i++;
	}
	fprintf(stderr, "start pos = [%f][%f]\n", cub->posX, cub->posY);
	display_win(cub, 750, 750);
	display_minimap(cub);
	mlx_loop(cub->mlx);
}

void    go_cub(t_main *data)
{
    t_cub cub;
    
    init_cub(data, &cub);
    
}