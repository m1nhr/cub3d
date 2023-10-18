/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 03:02:22 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/18 10:33:57 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	user_lateral_movement(t_cub *cub, int key, double m)
{
	if (key == cub->go_d->key)
	{
		if (cub->map[(int)(cub->posx + cub->planex * m)][(int)(cub->posy)] != '1')
			cub->posx += cub->planex * m;
		if (cub->map[(int)(cub->posx)][(int)(cub->posy + cub->planey * m)] != '1')
			cub->posy += cub->planey * m;
	}
	else if (key == cub->go_a->key)
	{
		if (cub->map[(int)(cub->posx - cub->planex * m)][(int)(cub->posy)] != '1')
			cub->posx -= cub->planex * m;
		if (cub->map[(int)(cub->posx)][(int)(cub->posy - cub->planey * m)] != '1')
			cub->posy -= cub->planey * m;
	}
}

void	user_movement(t_cub *cub, int key)
{
	double	m;

	m = 0.025;
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
	else if (key == cub->go_a->key || key == cub->go_d->key)
		user_lateral_movement(cub, key, m);
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
