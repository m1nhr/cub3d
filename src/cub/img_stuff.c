/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 03:21:01 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/06 05:03:51 by tmorikaw         ###   ########.fr       */
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
	int	tmpx;
	int	tabsize;
	int	ok;

	tabsize = 0;
	while (cub->map[tabsize])
		tabsize++;
	while (y <= tabsize * 6)
	{
		tmpx = x;
		ok = 0;
		while ((size_t)tmpx < (ft_strlen(cub->map[ok]) - 1) * 6)
		{
			put_pixel(cub, tmpx, y, color);
			tmpx++;
		}
		y++;
	}
}
