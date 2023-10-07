/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 03:21:01 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/07 02:55:48 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	put_pixel(t_cub *cub, int x, int y, int color)
{
	char	*dest;

	dest = cub->img->data_addr + (y * cub->img->line_size) + x * (cub->img->bpp
			/ 8);
	*(unsigned int *)dest = color;
}

void	img_init(t_cub *cub)
{
	cub->img = malloc(sizeof(t_image));
	if (!cub->img)
		exit(1);
	cub->img->img = mlx_new_image(cub->mlx, HEIGHT, WIGHT);
	cub->img->data_addr = mlx_get_data_addr(cub->img->img, &(cub->img->bpp),
			&(cub->img->line_size), &(cub->img->endian));
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
