/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 00:28:53 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/09/21 08:14:27 by tmorikaw         ###   ########.fr       */
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

void	put_pixel(t_cub *cub, int x, int y, int color)
{
	char	*dest;

	dest = cub->img->data_addr + (y * cub->img->line_size)
		+ x * (cub->img->bpp / 8);
	*(unsigned int *)dest = color;
}

void	img_init(t_cub *cub)
{
	cub->img = malloc(sizeof(t_image));
	if (!cub->img)
		exit(1);
	cub->img->img = mlx_new_image(cub->mlx, 750, 750);
	cub->img->data_addr = mlx_get_data_addr(cub->img->img, &(cub->img->bpp),
			&(cub->img->line_size),
			&(cub->img->endian));
}

/*Quelques premières variables sont déclarées : 
posX et posY représentent le vecteur position du joueur, 
dirX et dirY représentent la direction du joueur, et planeX 
et planY le plan de la caméra du joueur. 
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
void	init_value(t_cub *cub)
{
	cub->posX = 22;
	cub->posY = 12;	// position de depart x et y;
	cub->dirX = -1;
	cub->dirY = 0; 	// vexteur de direction initial
	cub->planeX = 0;
	cub->planeY = 0.66; // version RC 2d du plan de la cam
	cub->time = 0; // time of current frame
	cub->oldtime = 0; //time of previous frame
}

/* void	display_win(t_cub *cub)
{
	int i = 0;
	while 
}
 */

void	put_x10(t_cub *cub, int x, int y, int color, int ok)
{
	int tmpx;
	int tabsize;
	
	tabsize = 0;
	while (cub->map[tabsize])
		tabsize++;
	while (y <= tabsize * 8)
	{
		tmpx = x;
		while ((size_t)tmpx < (ft_strlen(cub->map[ok]) - 1) * 8)
		{
			put_pixel(cub, tmpx, y, color);
			tmpx++;
		}
		y++;
	}
}

void	display_minimap(t_cub *cub)
{
 	int x;
	int y;
	int lentab = 0;
	int y_tab;
	int i;

	y = 0;
	y_tab = 0;
	while (cub->map[lentab])
		lentab++;
	while (y_tab < lentab)
	{
		x = 0;
		i = 0;
		while ((size_t)i < ft_strlen(cub->map[y_tab]))
		{
			if (cub->map[y_tab][i] == '1')
				put_x10(cub, x, y, 0x000000, y_tab);
			else
				put_x10(cub, x, y, 0x13C6A2, y_tab);
			x += 8;
			i++;
		}
		y += 8;
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
			put_pixel(cub, x++, y, 0xFFFF00);
		y++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img, 0, 2);
}

void    init_cub(t_main *data, t_cub *cub)
{
	cub->map = data->map;
	cub->colors = data->colors;
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
	
	display_win(cub, 750, 750);
	display_minimap(cub);
	mlx_loop(cub->mlx);
}

void    go_cub(t_main *data)
{
    t_cub cub;
    
    init_cub(data, &cub);
    
}