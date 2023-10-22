/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 03:21:01 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/22 08:07:37 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	get_rgb(t_cub *cub, int ok)
{
	int	color;

	if (ok)
		color = ((cub->colors_ceiling.red & 0x0ff) << 16)
			|((cub->colors_ceiling.green & 0x0ff) << 8)
			|(cub->colors_ceiling.blue & 0x0ff);
	else
		color = ((cub->colors_floor.red & 0x0ff) << 16)
			|((cub->colors_floor.green & 0x0ff) << 8)
			|(cub->colors_floor.blue & 0x0ff);
	return (color);
}

int	get_color(t_cub *cub, t_img *texture)
{
	char	*dst;

	if (cub->texx < 0 || cub->texy < 0 || cub->texy > HEIGHT - 1
		|| cub->texx > WIDTH - 1)
		return (0);
	dst = texture->data_addr + (cub->texy * texture->line_size + cub->texx
			* (texture->bpp / 8));
	return (*(int *)dst);
}

void	put_pixel(t_cub *cub, int x, int y, int color)
{
	char	*dest;

	if (x < 0 || y < 0 || y > HEIGHT - 1 || x > WIDTH - 1)
		return ;
	dest = cub->img->data_addr + (y * cub->img->line_size) + x * (cub->img->bpp
			/ 8);
	*(int *)dest = color;
}

void	put_x10(t_cub *cub, int x, int y, int color)
{
	int	tmpx;
	int	tmpy;

	tmpx = x;
	tmpy = y;
	while (y < (tmpy + 6))
	{
		x = tmpx;
		while (x < (tmpx + 6))
		{
			put_pixel(cub, x, y, color);
			x++;
		}
		y++;
	}
}
