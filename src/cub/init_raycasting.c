/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 08:35:31 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/19 04:50:44 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_malloc_event_dig(t_cub *cub)
{
	cub->cam_left = malloc(sizeof(t_bool));
	if (!cub->cam_left)
		error_alloc(cub, "Error alloc cam_left");
	cub->cam_left->key = 65363;
	cub->cam_left->ok = FALSE;
	cub->cam_right = malloc(sizeof(t_bool));
	if (!cub->cam_right)
		error_alloc(cub, "Error alloc cam_right");
	cub->cam_right->key = 65361;
	cub->cam_right->ok = FALSE;
	cub->cam_mouse_right = 0;
	cub->cam_mouse_left = 0;
}

void	init_malloc_event(t_cub *cub)
{
	cub->go_w = malloc(sizeof(t_bool));
	if (!cub->go_w)
		error_alloc(cub, "Error alloc go_w");
	cub->go_w->key = 119;
	cub->go_w->ok = FALSE;
	cub->go_s = malloc(sizeof(t_bool));
	if (!cub->go_s)
		error_alloc(cub, "Error alloc go_s");
	cub->go_s->key = 115;
	cub->go_s->ok = FALSE;
	cub->go_a = malloc(sizeof(t_bool));
	if (!cub->go_a)
		error_alloc(cub, "Error alloc go_a");
	cub->go_a->key = 97;
	cub->go_a->ok = FALSE;
	cub->go_d = malloc(sizeof(t_bool));
	if (!cub->go_d)
		error_alloc(cub, "Error alloc go_d");
	cub->go_d->key = 100;
	cub->go_d->ok = FALSE;
	init_malloc_event_dig(cub);
}

void	init_pos_dig(t_cub *cub)
{
	if (cub->map[(int)cub->posx][(int)cub->posy] == 'W')
	{
		cub->dirx = 0;
		cub->diry = -1;
		cub->planex = -0.66;
		cub->planey = 0;
	}
	else if (cub->map[(int)cub->posx][(int)cub->posy] == 'E')
	{
		cub->dirx = 0;
		cub->diry = 1;
		cub->planex = 0.66;
		cub->planey = 0;
	}
	return ;
}

void	init_pos(t_cub *cub)
{
	if (cub->map[(int)cub->posx][(int)cub->posy] == 'N')
	{
		cub->dirx = -1;
		cub->diry = 0;
		cub->planex = 0;
		cub->planey = 0.66;
	}
	else if (cub->map[(int)cub->posx][(int)cub->posy] == 'S')
	{
		cub->dirx = 1;
		cub->diry = 0;
		cub->planex = 0;
		cub->planey = -0.66;
	}
	else
		init_pos_dig(cub);
}

void	init_value(t_cub *cub, t_main *data)
{
	cub->map = good_map(cub, data, data->map);
	cub->colors_ceiling = data->colors_ceiling;
	cub->colors_floor = data->colors_floor;
	cub->posx = start_pos(cub->map, 0) + 0.5;
	cub->posy = start_pos(cub->map, 1) + 0.5;
	cub->sno = ft_strdup(data->NO);
	cub->sso = ft_strdup(data->SO);
	cub->swe = ft_strdup(data->WE);
	cub->sea = ft_strdup(data->EA);
	free_textures(data);
	cub->texture1 = NULL;
	cub->texture2 = NULL;
	cub->texture3 = NULL;
	cub->texture4 = NULL;
	cub->side = 0;
	cub->mouse_on = 0;
	init_pos(cub);
	init_malloc_event(cub);
}
