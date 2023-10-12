/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 03:21:01 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/12 08:27:26 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	get_color(t_cub *cub, t_img *texture)
{
	char	*dst;

 	if (cub->texx < 0 || cub->texy < 0 || cub->texy > HEIGHT - 1 \
	|| cub->texx > WIGHT - 1)
		return (0);


/* 	texture->data_addr = mlx_get_data_addr(texture->img, &(texture->bpp),
			&(texture->line_size), &(texture->endian));
	if (!texture->data_addr)
		return (1); */
	dst = texture->data_addr + (cub->texy * texture->line_size + cub->texx * \
	(texture->bpp / 8));
	return (*(int *)dst);
}

void	put_pixel(t_cub *cub, int x, int y, int color)
{
	char	*dest;

	if (x < 0 || y < 0 || y > HEIGHT - 1 || x > WIGHT - 1)
		return ;
	dest = cub->img->data_addr + (y * cub->img->line_size) + x * (cub->img->bpp
			/ 8);
	*(unsigned int *)dest = color;
}

void	put_x10(t_cub *cub, int x, int y, int color)
{
	int	tmpx = x;
	int tmpy = y;
//	int	tabsize;
//	int	ok;
	
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
