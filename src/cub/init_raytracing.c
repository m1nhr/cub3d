/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raytracing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 08:35:31 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/12 09:56:31 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

double	start_pos(char **tab, int ok)
{
	double	y;
	double	x;
	char	*finder;

	x = 0;
	finder = "NESW";
	while (tab[(int)x])
	{
		y = 0;
		while (tab[(int)x][(int)y])
		{
			if (ft_strchr(finder, tab[(int)x][(int)y]))
			{
				if (ok)
					return (y);
				return (x);
			}
			y++;
		}
		x++;
	}
	return (0);
}

void	init_malloc_event(t_cub *cub)
{
	cub->go_w = malloc(sizeof(t_bool));
	cub->go_w->key = 119;
	cub->go_s = malloc(sizeof(t_bool));
	cub->go_s->key = 115;
	cub->go_a = malloc(sizeof(t_bool));
	cub->go_a->key = 97;
	cub->go_d = malloc(sizeof(t_bool));
	cub->go_d->key = 100;
	cub->cam_left = malloc(sizeof(t_bool));
	cub->cam_left->key = 65363;
	cub->cam_right = malloc(sizeof(t_bool));
	cub->cam_right->key = 65361;
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
	int	i;

	cub->map = data->map;
	cub->colors_ceiling = cub->data.colors_ceiling;
	cub->colors_floor = cub->data.colors_floor;
	//cub->textures = data->textures;
	cub->posx = start_pos(cub->map, 0);
	cub->posy = start_pos(cub->map, 1);
	cub->side = -1;
	cub->NO = ft_strdup(data->NO);
	cub->SO = ft_strdup(data->SO);
	cub->WE = ft_strdup(data->WE);
	cub->EA = ft_strdup(data->EA);
//	cub->img->img = NULL;
	//cub->img->win = NULL;
	//cub->map = NULL;
	init_pos(cub);
	init_malloc_event(cub);
	i = 0;
	while (cub->map[i])
	{
		fprintf(stderr, "%s = %d\n", cub->map[i], i);
		i++;
	}
}
