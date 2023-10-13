/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 05:00:52 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/13 05:43:50 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	display_minimap(t_cub *cub, int x, int y)
{
	int	i;
	int	y_tab;
	int	lentab;

	y_tab = 0;
	lentab = what_lentab(cub->map);
	while (y_tab < lentab)
	{
		i = 0;
		x = 0;
		while ((size_t)i < ft_strlen(cub->map[y_tab]))
		{
			if (i == (int)cub->posy && y_tab == (int)cub->posx)
				put_x10(cub, x, y, 0xFF0000);
			else if (cub->map[y_tab][i] && cub->map[y_tab][i] == '1')
				put_x10(cub, x, y, 0x13C6A2);
			x += 6;
			i++;
		}
		y += 6;
		y_tab++;
	}
}

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
 
int	display_game_frame(t_cub *cub)
{
	int	x;
	int	lineheight;

	x = 0;
	while (x < WIGHT)
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
		throw_rays(cub);
		if (cub->side == 0)
			cub->dist_to_wall = (cub->sidedistx - cub->deltadistx);
		else
			cub->dist_to_wall = (cub->sidedisty - cub->deltadisty);
		lineheight = (int)(HEIGHT / cub->dist_to_wall);
		cub->draw_start = -lineheight / 2 + HEIGHT / 2;
		if (cub->draw_start < 0)
			cub->draw_start = 0;
		cub->draw_end = lineheight / 2 + HEIGHT / 2;
		if (cub->draw_end >= HEIGHT)
			cub->draw_end = HEIGHT - 1;
		draw_total_frame(cub, x, 0, lineheight);
		x++;
	}
	mlx_mouse_move(cub->img->mlx, cub->img->win, 750 / 2, 750 / 2);
	display_minimap(cub, 0, 0);
	mlx_put_image_to_window(cub->img->mlx, cub->img->win, cub->img->img, 0, 0);
	keymap_event(cub);
	fprintf(stderr, "coord>[%f][%f] +  dirx = %f & diry = %f\n", cub->posy, cub->posx, cub->dirx, cub->diry);
	return (0);
}
