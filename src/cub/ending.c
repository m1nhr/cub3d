/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 04:06:34 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/18 05:23:25 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	error_ok(char *str, int ok)
{
	ft_putendl_fd(str, 1);
	return (ok);
}

void	error_alloc(t_cub *cub, char *str)
{
	ft_putendl_fd(str, 1);
	close_window(cub);
}

void	free_cub_value(t_cub *cub)
{
	if (cub->NO)
		free(cub->NO);
	if (cub->SO)
		free(cub->SO);
	if (cub->WE)
		free(cub->WE);
	if (cub->EA)
		free(cub->EA);
	if (cub->go_w)
		free(cub->go_w);
	if (cub->go_s)
		free(cub->go_s);
	if (cub->go_a)
		free(cub->go_a);
	if (cub->go_d)
		free(cub->go_d);
	if (cub->cam_left)
		free(cub->cam_left);
	if (cub->cam_right)
		free(cub->cam_right);
}

void	free_img(t_cub *cub, t_img *obj)
{
	if (obj->img)
		mlx_destroy_image(cub->img->mlx, obj->img);
	if (obj)
		free(obj);
}

int	close_window(t_cub *cub)
{
	ft_putendl_fd("goodbye :)", 1);

	if (cub->texture1)
		free_img(cub, cub->texture1);
	if (cub->texture2)
		free_img(cub, cub->texture2);
	if (cub->texture3)
		free_img(cub, cub->texture3);
	if (cub->texture4)
		free_img(cub, cub->texture4);
	if (cub->img)
	{
		if (cub->img->img)
			mlx_destroy_image(cub->img->mlx, cub->img->img);
		mlx_destroy_window(cub->img->mlx, cub->img->win);
		mlx_destroy_display(cub->img->mlx);
		if (cub->img->mlx)
			free(cub->img->mlx);
		free(cub->img);
	}
	free_cub_value(cub);
	exit(0);
}
