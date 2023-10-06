/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 05:00:52 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/06 07:19:57 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	display_minimap(t_cub *cub, char *finder, int lentab, int y_tab)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	while (y_tab < lentab)
	{
		x = 0;
		i = 0;
		while ((size_t)i < ft_strlen(cub->map[y_tab]))
		{
			if (cub->map[y_tab][i] == '1')
				put_x10(cub, x, y, 0x000000);
			else if (ft_strchr(finder, cub->map[y_tab][i]))
				put_x10(cub, x, y, 0xFF0000);
			else if (cub->map[y_tab][i] == '0' || !cub->map[y_tab][i])
				put_x10(cub, x, y, 0x13C6A2);
			x += 6;
			i++;
		}
		y += 6;
		y_tab++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img, 0, 2);
}

void	display_background(t_cub *cub)
{
	int		x;
	int		y;
	double	fade;

	fade = 1;
	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		fade *= 1.0018;
		while (x < WIGHT)
		{
			put_pixel(cub, x, y, 0x0000FF * fade);
			x++;
		}
		y++;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIGHT)
		{
			put_pixel(cub, x, y, 0x808080);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img, 0, 2);
}

void	display_game_frame(t_cub *cub)
{
	int	x;
	int	y;
	int	lineheight;
	int	color;

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
		color = 0xFFFF00;
		if (cub->side == 1)
			color = color / 2;
		y = cub->draw_start;
		while (y <= cub->draw_end && y >= cub->draw_start)
		{
			put_pixel(cub, x, y, color);
			y++;
		}
		x++;
	}
/*   	x = 0;
	y = 0;
	int y_tab = 0;
	int lentab = what_lentab(cub->map);
	int i;
	while (y_tab < lentab)
	{
		x = 0;
		i = 0;
		while ((size_t)i < ft_strlen(cub->map[y_tab]))
		{
			if (cub->map[y_tab][i] && cub->map[y_tab][i] == '1')
				put_x10(cub, x, y, 0x000000);
			if (ft_strchr("NSEW", cub->map[y_tab][i]))
				put_x10(cub, x, y, 0xFF0000);
			if (cub->map[y_tab][i] == '0' || !cub->map[y_tab][i])
				put_x10(cub, x, y, 0x13C6A2);
			x += 6;
			i++;
		}
		y += 6;
		y_tab++;
	}  */
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img, 0, 0);
	fprintf(stderr, "OK finit une frame\n");
}
