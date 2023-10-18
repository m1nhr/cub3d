/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 03:06:11 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/18 03:11:40 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_raydir_delta(t_cub *cub, int x)
{
	cub->camerax = 2 * x / (double)WIGHT - 1;
	cub->raydirx = cub->dirx + cub->planex * cub->camerax;
	cub->raydiry = cub->diry + cub->planey * cub->camerax;
	if (cub->raydirx != 0)
		cub->deltadistx = ft_fabs(1 / cub->raydirx);
	else
		cub->deltadistx = 1e30;
	if (cub->raydiry != 0)
		cub->deltadisty = ft_fabs(1 / cub->raydiry);
	else
		cub->deltadisty = 1e30;
}

void	init_sidedist(t_cub *cub)
{
	cub->mapx = (int)cub->posx;
	cub->mapy = (int)cub->posy;
	if (cub->raydirx < 0)
	{
		cub->stepx = -1;
		cub->sidedistx = (cub->posx - cub->mapx) * cub->deltadistx;
	}
	else
	{
		cub->stepx = 1;
		cub->sidedistx = (cub->mapx + 1 - cub->posx) * cub->deltadistx;
	}
	if (cub->raydiry < 0)
	{
		cub->stepy = -1;
		cub->sidedisty = (cub->posy - cub->mapy) * cub->deltadisty;
	}
	else
	{
		cub->stepy = 1;
		cub->sidedisty = (cub->mapy + 1 - cub->posy) * cub->deltadisty;
	}
}

void	throw_rays(t_cub *cub)
{
	cub->hit = 0;
	while (cub->hit == 0)
	{
		if (cub->sidedistx < cub->sidedisty)
		{
			cub->sidedistx += cub->deltadistx;
			cub->mapx += cub->stepx;
			cub->side = 0;
		}
		else
		{
			cub->sidedisty += cub->deltadisty;
			cub->mapy += cub->stepy;
			cub->side = 1;
		}
		if (cub->map[cub->mapx][cub->mapy] == '1')
			cub->hit = 1;
	}
	return ;
}
