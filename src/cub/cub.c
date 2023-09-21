/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 00:28:53 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/09/21 02:47:00 by tmorikaw         ###   ########.fr       */
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
//	img_init(data); 
//	mlx_hook(data->win, 2, 1L << 0, &keymap, data);
//	mlx_mouse_hook(data->win, &ctrl_mouse, data);
	mlx_hook(cub->win, 17, 1L << 17, &close_window, data);
	//display_win(cub);
	mlx_loop(cub->mlx);
}

void    go_cub(t_main *data)
{
    t_cub cub;
    
    init_cub(data, &cub);
    
}