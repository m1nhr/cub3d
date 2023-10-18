/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 03:02:22 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/18 03:05:41 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	user_d_movement(t_cub *cub, double m)
{
	if (((cub->dirx > -0.5 && cub->dirx < 0.5) && (cub->diry > -1.5
				&& cub->diry < -0.5)) || ((cub->dirx > -0.5 && cub->dirx
				< 0.5) && (cub->diry > 0.5 && cub->diry < 1.5)))
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

void	user_a_movement(t_cub *cub, double m)
{
	if (((cub->dirx > -0.5 && cub->dirx < 0.5) && (cub->diry > 0.5
				&& cub->diry < 1.5)) || ((cub->dirx > -0.5 && cub->dirx
				< 0.3) && (cub->diry > -1.5 && cub->diry < -0.5)))
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

void	user_movement(t_cub *cub, int key)
{
	double	m;

	m = 0.03;
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
		user_a_movement(cub, m);
	else if (key == cub->go_d->key)
		user_d_movement(cub, m);
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
