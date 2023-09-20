/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 00:28:53 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/09/21 01:02:46 by tmorikaw         ###   ########.fr       */
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