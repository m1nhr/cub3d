/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 03:12:37 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/18 03:14:06 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	update_texture(t_cub *cub, int line_height)
{
	if (cub->side == 0)
		cub->wall_x = cub->posy + cub->dist_to_wall * cub->raydiry;
	else
		cub->wall_x = cub->posx + cub->dist_to_wall * cub->raydirx;
	cub->wall_x -= floor((cub->wall_x));
	cub->texx = (int)(cub->wall_x * 64);
	if (cub->side == 0 && cub->raydirx > 0)
		cub->texx = 64 - cub->texx - 1;
	if (cub->side == 1 && cub->raydiry < 0)
		cub->texx = 64 - cub->texx - 1;
	cub->walk = 1.0 * 64 / line_height;
	cub->tex_pos = \
	(cub->draw_start - HEIGHT / 2 + line_height / 2) * cub->walk;
}

void	get_draw_point(t_cub *cub)
{
	if (cub->side == 0)
		cub->dist_to_wall = (cub->sidedistx - cub->deltadistx);
	else
		cub->dist_to_wall = (cub->sidedisty - cub->deltadisty);
	cub->lineheight = (int)(HEIGHT / cub->dist_to_wall);
	cub->draw_start = -cub->lineheight / 2 + HEIGHT / 2;
	if (cub->draw_start < 0)
		cub->draw_start = 0;
	cub->draw_end = cub->lineheight / 2 + HEIGHT / 2;
	if (cub->draw_end >= HEIGHT)
		cub->draw_end = HEIGHT - 1;
}

void	draw_total_frame(t_cub *cub, int x, int y, int lineheight)
{
	while (y < cub->draw_start)
	{
		put_pixel(cub, x, y, get_rgb(cub, 1));
		y++;
	}
	update_texture(cub, lineheight);
	while (y <= cub->draw_end && y >= cub->draw_start)
	{
		cub->texy = (int)cub->tex_pos;
		cub->tex_pos += cub->walk;
		if (cub->side == 0 && cub->raydirx < 0)
			put_pixel(cub, x, y, get_color(cub, cub->texture1));
		else if (cub->side == 0 && cub->raydirx >= 0)
			put_pixel(cub, x, y, get_color(cub, cub->texture2));
		else if (cub->side == 1 && cub->raydiry < 0)
			put_pixel(cub, x, y, get_color(cub, cub->texture3));
		else if (cub->side == 1 && cub->raydiry >= 0)
			put_pixel(cub, x, y, get_color(cub, cub->texture4));
		y++;
	}
	while (y < HEIGHT)
	{
		put_pixel(cub, x, y, get_rgb(cub, 0));
		y++;
	}
}