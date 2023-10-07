/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 00:28:53 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/07 06:57:05 by tmorikaw         ###   ########.fr       */
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

void	user_movement(t_cub *cub, int key)
{
	double	m;

	m = 0.05; // movespeed
	if (key == 119)  // w
	{
		if (cub->map[(int)(cub->posx + cub->dirx * m)][(int)(cub->posy)] != '1')
			cub->posx += cub->dirx * m;
		if (cub->map[(int)(cub->posx)][(int)(cub->posy + cub->diry * m)] != '1')
			cub->posy += cub->diry * m;
	}
	else if (key == 115) // s
	{
		if (cub->map[(int)(cub->posx - cub->dirx * m)][(int)(cub->posy)] != '1')
			cub->posx -= cub->dirx * m;
		if (cub->map[(int)(cub->posx)][(int)(cub->posy - cub->diry * m)] != '1')
			cub->posy -= cub->diry * m;
	}
 	else if (key == 97)
	{
		if (cub->map[(int)(cub->posx + cub->diry * m)][(int)(cub->posy)] != '1')
			cub->posx += cub->diry * m;
		if (cub->map[(int)(cub->posx)][(int)(cub->posy + cub->dirx * m)] != '1')
			cub->posy += cub->dirx * m;
	}
	else if (key == 100)
	{
		if (cub->map[(int)(cub->posx - cub->diry * m)][(int)(cub->posy)] != '1')
			cub->posx -= cub->diry * m;
		if (cub->map[(int)(cub->posx)][(int)(cub->posy - cub->dirx * m)] != '1')
			cub->posy -= cub->dirx * m;
	}
}

void	cam_movement(t_cub *cub, int key, double rt)
{
	double	olddirx;
	double	oldplanex;

	if (key == 65363)  // left
	{
		olddirx = cub->dirx;
		cub->dirx = cub->dirx * cos(-rt) - cub->diry * sin(-rt);
		cub->diry = olddirx * sin(-rt) + cub->diry * cos(-rt);
		oldplanex = cub->planex;
		cub->planex = cub->planex * cos(-rt) - cub->planey * sin(-rt);
		cub->planey = oldplanex * sin(-rt) + cub->planey * cos(-rt);
	}
	else if (key == 65361)  // right
	{
		olddirx = cub->dirx;
		cub->dirx = cub->dirx * cos(rt) - cub->diry * sin(rt);
		cub->diry = olddirx * sin(rt) + cub->diry * cos(rt);
		oldplanex = cub->planex;
		cub->planex = cub->planex * cos(rt) - cub->planey * sin(rt);
		cub->planey = oldplanex * sin(rt) + cub->planey * cos(rt);
	}
}

int	game_on(t_cub *cub)
{
//	display_background(cub);
	display_game_frame(cub);
//	display_minimap(cub, "NESW", what_lentab(cub->map), 0);
	return (0);
}

void	keymap_event(t_cub *cub)
{
	if (cub->go_w->ok == TRUE)
		user_movement(cub, 119);
	if (cub->go_s->ok == TRUE)
		user_movement(cub, 115);
	if (cub->go_a->ok == TRUE)
		user_movement(cub, 97);
	if (cub->go_d->ok == TRUE)
		user_movement(cub, 100);
	if (cub->cam_left->ok == TRUE)
		cam_movement(cub, 65363, 0.02);
	if (cub->cam_right->ok == TRUE)
		cam_movement(cub, 65361, 0.02);
	return ;
}

int	key_press(int key, t_cub *cub)
{
	printf("presssssss\n");
	if (key == XK_Escape)
		close_window(cub);
	if (key == 119)
		cub->go_w->ok = TRUE;
	if (key == 115)
		cub->go_s->ok = TRUE;
	if (key == 97)
		cub->go_a->ok = TRUE;
	if (key == 100)
		cub->go_d->ok = TRUE;
	if (key == 65363)
		cub->cam_left->ok = TRUE;
	if (key == 65361)
		cub->cam_right->ok = TRUE;
	game_on(cub);
	return (0);
}

int	key_release(int key, t_cub *cub)
{
	printf("release\n");
	if (key == 119)
		cub->go_w->ok = FALSE;
	if (key == 115)
		cub->go_s->ok = FALSE;
	if (key == 97)
		cub->go_a->ok = FALSE;
	if (key == 100)
		cub->go_d->ok = FALSE;
	if (key == 65363)
		cub->cam_left->ok = FALSE;
	if (key == 65361)
		cub->cam_right->ok = FALSE;
	return (0);
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
	mlx_hook(cub.win, KeyPress, KeyPressMask, &key_press, &cub);
//	mlx_do_key_autorepeaton(cub.mlx);
	mlx_hook(cub.win, KeyRelease, KeyReleaseMask, &key_release, &cub);
	mlx_hook(cub.win, DestroyNotify, 0, &close_window, &cub);
	mlx_loop_hook(cub.mlx, &game_on, &cub);
//	game_on(&cub);
	mlx_loop(cub.mlx);
//	mlx_do_key_autorepeatoff(cub.mlx);
}
