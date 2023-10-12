/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 00:28:53 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/12 11:06:38 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	close_window(t_cub *cub)
{
	ft_putendl_fd("goodbye :)", 1);
	mlx_destroy_image(cub->img->mlx, cub->img->img);
	mlx_destroy_window(cub->img->mlx, cub->img->win);
	mlx_destroy_display(cub->img->mlx);
	//	free(cub->data.img);
	free(cub->img->mlx);
	free_tab(cub->data.parse_map->map_parse);
	free(cub->data.parse_map);
	exit(0);
}

void	user_movement(t_cub *cub, int key)
{
	double	m;

	m = 0.04; // movespeed
	if (key == cub->go_w->key)
	{
		if (cub->map[(int)(cub->posx + cub->dirx * m)][(int)(cub->posy)] != '1')
			cub->posx += cub->dirx * m;
		if (cub->map[(int)(cub->posx)][(int)(cub->posy + cub->diry * m)] != '1')
			cub->posy += cub->diry * m;
	}
	else if (key == cub->go_s->key)
	{
		if (cub->map[(int)(cub->posx - cub->dirx * m)][(int)(cub->posy)] != '1')
			cub->posx -= cub->dirx * m;
		if (cub->map[(int)(cub->posx)][(int)(cub->posy - cub->diry * m)] != '1')
			cub->posy -= cub->diry * m;
	}
	else if (key == cub->go_a->key)
	{
		if (((cub->dirx > -0.5 && cub->dirx < 0.5) && (cub->diry > 0.5
					&& cub->diry < 1.5)) || ((cub->dirx > -0.5
					&& cub->dirx < 0.3) && (cub->diry > -1.5 && cub->diry <
					-0.5)))
		{
			if (cub->map[(int)(cub->posx - cub->diry
					* m)][(int)(cub->posy)] != '1')
				cub->posx -= cub->diry * m;
			if (cub->map[(int)(cub->posx)][(int)(cub->posy - cub->dirx
					* m)] != '1')
				cub->posy -= cub->dirx * m;
		}
		else
		{
			if (cub->map[(int)(cub->posx + cub->diry
					* m)][(int)(cub->posy)] != '1')
				cub->posx += cub->diry * m;
			if (cub->map[(int)(cub->posx)][(int)(cub->posy + cub->dirx
					* m)] != '1')
				cub->posy += cub->dirx * m;
		}
	}
	else if (key == cub->go_d->key)
	{
		if (((cub->dirx > -0.5 && cub->dirx < 0.5) && (cub->diry > -1.5
					&& cub->diry < -0.5)) || ((cub->dirx > -0.5
					&& cub->dirx < 0.5) && (cub->diry > 0.5
					&& cub->diry < 1.5)))
		{
			if (cub->map[(int)(cub->posx + cub->diry
					* m)][(int)(cub->posy)] != '1')
				cub->posx += cub->diry * m;
			if (cub->map[(int)(cub->posx)][(int)(cub->posy + cub->dirx
					* m)] != '1')
				cub->posy += cub->dirx * m;
		}
		else
		{
			if (cub->map[(int)(cub->posx - cub->diry
					* m)][(int)(cub->posy)] != '1')
				cub->posx -= cub->diry * m;
			if (cub->map[(int)(cub->posx)][(int)(cub->posy - cub->dirx
					* m)] != '1')
				cub->posy -= cub->dirx * m;
		}
	}
}

void	cam_movement(t_cub *cub, int key, double rt)
{
	double	olddirx;
	double	oldplanex;

	if (key == cub->cam_left->key)
	{
		olddirx = cub->dirx;
		cub->dirx = cub->dirx * cos(-rt) - cub->diry * sin(-rt);
		cub->diry = olddirx * sin(-rt) + cub->diry * cos(-rt);
		oldplanex = cub->planex;
		cub->planex = cub->planex * cos(-rt) - cub->planey * sin(-rt);
		cub->planey = oldplanex * sin(-rt) + cub->planey * cos(-rt);
	}
	else if (key == cub->cam_right->key)
	{
		olddirx = cub->dirx;
		cub->dirx = cub->dirx * cos(rt) - cub->diry * sin(rt);
		cub->diry = olddirx * sin(rt) + cub->diry * cos(rt);
		oldplanex = cub->planex;
		cub->planex = cub->planex * cos(rt) - cub->planey * sin(rt);
		cub->planey = oldplanex * sin(rt) + cub->planey * cos(rt);
	}
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
	display_game_frame(cub);
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

/* void	ft_get_texture_adress(t_cub *cub)
{
	
	cub->texture1.data_addr = mlx_get_data_addr(cub->texture1.img,
			&(cub->texture1.bpp),
			&(cub->texture1.line_size), &(cub->texture1.endian));
	cub->texture2.data_addr = mlx_get_data_addr(cub->texture2.img,
			&(cub->texture2.bpp),
			&(cub->texture2.line_size), &(cub->texture2.endian));
	cub->texture3.data_addr = mlx_get_data_addr(cub->texture3.img,
			&(cub->texture3.bpp),
			&(cub->texture3.line_size), &(cub->texture3.endian));
	cub->texture4.data_addr = mlx_get_data_addr(cub->texture4.img,
			&(cub->texture4.bpp),
			&(cub->texture4.line_size), &(cub->texture4.endian));
}

        tex.img = mlx_xpm_file_to_image(cub->mlx, trimmed, &tex.len,
		&tex.height);
    if (!tex.img)
        return (return_error("PARSING ERROR: Couldn't import texture\n", 0));
    tex.addr = mlx_get_data_addr(tex.img, &tex.bpp, &tex.len, &tex.end);

 */

void	get_texture(t_cub *cub)
{
	int	h;
	int	w;

	cub->texture1 = ft_calloc(1, sizeof(t_img));
	cub->texture1->img = mlx_xpm_file_to_image(cub->img->mlx, cub->NO, &w, &h);
	if (!cub->texture1->img)
		return ;
	cub->texture1->data_addr = mlx_get_data_addr(cub->texture1->img,
			&(cub->texture1->bpp), &(cub->texture1->line_size),
			&(cub->texture1->endian));
	cub->texture2 = ft_calloc(1, sizeof(t_img));
	cub->texture2->img = mlx_xpm_file_to_image(cub->img->mlx, cub->SO, &w, &h);
	if (!cub->texture2->img)
		return ;
	cub->texture2->data_addr = mlx_get_data_addr(cub->texture2->img,
			&(cub->texture2->bpp), &(cub->texture2->line_size),
			&(cub->texture2->endian));
	cub->texture3 = ft_calloc(1, sizeof(t_img));
	cub->texture3->img = mlx_xpm_file_to_image(cub->img->mlx, cub->WE, &w, &h);
	if (!cub->texture3->img)
		return ;
	cub->texture3->data_addr = mlx_get_data_addr(cub->texture3->img,
			&(cub->texture3->bpp), &(cub->texture3->line_size),
			&(cub->texture3->endian));
	cub->texture4 = ft_calloc(1, sizeof(t_img));
	cub->texture4->img = mlx_xpm_file_to_image(cub->img->mlx, cub->EA, &w, &h);
	if (!cub->texture4->img)
		return ;
	cub->texture4->data_addr = mlx_get_data_addr(cub->texture4->img,
			&(cub->texture4->bpp), &(cub->texture4->line_size),
			&(cub->texture4->endian));
}

int	init_text(t_cub *cub)
{
	if (cub->side == 0 && cub->raydirx < 0)
		cub->t.textdir = 0;
	if (cub->side == 0 && cub->raydirx >= 0)
		cub->t.textdir = 1;
	if (cub->side == 1 && cub->raydiry < 0)
		cub->t.textdir = 2;
	if (cub->side == 1 && cub->raydiry >= 0)
		cub->t.textdir = 3;
	if (cub->side == 0)
		cub->t.wallx = cub->posy + cub->dist_to_wall * cub->raydirx;
	else
		cub->t.wallx = cub->posx + cub->dist_to_wall * cub->raydiry;
	cub->t.wallx -= floor(cub->t.wallx);
	return (0);
}

int	mlx_stuff(t_cub *cub)
{
	cub->img = ft_calloc(1, sizeof(t_img));
	if (!cub->img)
		return (1); // void error malloc
	cub->img->mlx = mlx_init();
	if (!cub->img->mlx)
		return (1); // error mlx_init
	cub->img->win = mlx_new_window(cub->img->mlx, 750, 750, "CUB3D");
	if (!cub->img->win)
		return (1); // error mlx_win
	cub->img->img = mlx_new_image(cub->img->mlx, HEIGHT, WIGHT);
	cub->img->data_addr = mlx_get_data_addr(cub->img->img, &(cub->img->bpp),
			&(cub->img->line_size), &(cub->img->endian));
	return (0);
}

void	go_cub(t_main *data)
{
	t_cub	cub;

	/* 	cub = malloc(sizeof(t_cub));
	if (!cub)
		return ; */
	init_value(&cub, data);
	if (mlx_stuff(&cub))
		return ;
	//get_texture(&cub);
	mlx_hook(cub.img->win, KeyPress, KeyPressMask, &key_press, &cub);
	//	mlx_do_key_autorepeaton(cub.mlx);
	mlx_hook(cub.img->win, KeyRelease, KeyReleaseMask, &key_release, &cub);
	mlx_hook(cub.img->win, DestroyNotify, 0, &close_window, &cub);
	mlx_loop_hook(cub.img->mlx, &display_game_frame, &cub);
	mlx_loop(cub.img->mlx);
	//	mlx_do_key_autorepeatoff(cub.mlx);
}
