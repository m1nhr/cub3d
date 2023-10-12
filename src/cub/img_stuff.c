/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 03:21:01 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/12 05:19:02 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
/*
int	get_color(t_struct *all, t_algo *algo, t_img *img, void *image)
{
	char	*dst;

	if (algo->tex.x < 0 || algo->tex.y < 0 || algo->tex.y > HEIGHT - 1 \
	|| algo->tex.x > WIGHT - 1)
		return (0);
	img->data = \
	mlx_get_data_addr(image, &img->bpp, &img->size_line, &img->endian);
	if (!img->data)
		clean_win_kill(all);
	dst = img->data + (algo->tex.y * img->size_line + algo->tex.x * \
	(img->bpp / 8));
	return (*(int *)dst);
}*/

void	put_pixel(t_cub *cub, int x, int y, int color)
{
	char	*dest;

	if (x < 0 || y < 0 || y > HEIGHT - 1 || x > WIGHT - 1)
		return ;
	dest = cub->data.data_addr + (y * cub->data.line_size) + x * (cub->data.bpp
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
