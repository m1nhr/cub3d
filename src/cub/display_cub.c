/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 05:00:52 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/22 09:00:13 by tmorikaw         ###   ########.fr       */
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
				put_x10(cub, x, y, 0x9933FF);
			x += 6;
			i++;
		}
		y += 6;
		y_tab++;
	}
}

int	display_game_frame(t_cub *cub)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		init_raydir_delta(cub, x);
		init_sidedist(cub);
		throw_rays(cub);
		get_draw_point(cub);
		draw_total_frame(cub, x, 0, cub->lineheight);
		x++;
	}
	if (cub->mouse_on == 0)
		mlx_mouse_move(cub->img->mlx, cub->img->win, WIDTH / 2, HEIGHT / 2);
	display_minimap(cub, 0, 0);
	mlx_put_image_to_window(cub->img->mlx, cub->img->win, cub->img->img, 0, 0);
	keymap_event(cub);
	return (0);
}
