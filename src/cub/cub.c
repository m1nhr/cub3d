/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 00:28:53 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/06 05:22:28 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	close_window(t_cub *cub)
{
	ft_putendl_fd("goodbye :)", 1);
	mlx_destroy_image(cub->mlx, cub->img->img);
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_display(cub->mlx);
	free(cub->img);
	free(cub->mlx);
	free_tab(cub->data->parse_map->map_parse);
	free(cub->data->parse_map);
	exit(0);
}

void	movement_dig(t_cub *cub, int key, double rt) // rt = rotspeed
{
	double	olddirx;
	double	oldplanex;

	if (key == 100)  //d
	{
		olddirx = cub->dirx;
		cub->dirx = cub->dirx * cos(-rt) - cub->diry * sin(-rt);
		cub->diry = olddirx * sin(-rt) + cub->diry * cos(-rt);
		oldplanex = cub->planex;
		cub->planex = cub->planex * cos(-rt) - cub->planey * sin(-rt);
		cub->planey = oldplanex * sin(-rt) + cub->planey * cos(-rt);
	}
	else if (key == 97)  // a
	{
		olddirx = cub->dirx;
		cub->dirx = cub->dirx * cos(rt) - cub->diry * sin(rt);
		cub->diry = olddirx * sin(rt) + cub->diry * cos(rt);
		oldplanex = cub->planex;
		cub->planex = cub->planex * cos(rt) - cub->planey * sin(rt);
		cub->planey = oldplanex * sin(rt) + cub->planey * cos(rt);
	}
}

void	movement(t_cub *cub, int key)
{
	double	m;

	m = 0.4; // movespeed
	if (key == 119)  // w
	{
		if (cub->map[(int)(cub->posx + cub->dirx * m)][(int)(cub->posy)] == '0')
			cub->posx += cub->dirx * m;
		if (cub->map[(int)(cub->posx)][(int)(cub->posy + cub->diry * m)] == '0')
			cub->posy += cub->diry * m;
	}
	else if (key == 115) // s
	{
		if (cub->map[(int)(cub->posx - cub->dirx * m)][(int)(cub->posy)] == '0')
			cub->posx -= cub->dirx * m;
		if (cub->map[(int)(cub->posx)][(int)(cub->posy - cub->diry * m)] == '0')
			cub->posy -= cub->diry * m;
	}
	else
		movement_dig(cub, key, 0.2);
}

int	keymap_event(int key, t_cub *cub)
{
	if (key == XK_Escape)
		close_window(cub);
	if (key == 119 || key == 97 || key == 115 || key == 100)
		movement(cub, key);
	game_on(cub);
	return (0);
}

void	game_on(t_cub *cub)
{
	display_background(cub);
	display_game_frame(cub);
	//display_minimap(cub, "NESW", what_lentab(cub->map), 0);
}

void go_cub(t_main *data)
{
	t_cub cub;

	init_value(&cub, data);
	cub.mlx = mlx_init();
	if (!cub.mlx)
		exit(1);
	cub.win = mlx_new_window(cub.mlx, 750, 750, "CUB3D");
	if (!cub.win)
		exit(1);
	img_init(&cub);
	mlx_hook(cub.win, KeyPress, KeyPressMask, &keymap_event, &cub);
	mlx_hook(cub.win, DestroyNotify, 0, &close_window, &cub);
	game_on(&cub);
	mlx_loop(cub.mlx);
}
