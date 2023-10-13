/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 04:06:34 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/13 06:01:12 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	free_cub_value(t_cub *cub)
{
	free(cub->NO);
	free(cub->SO);
	free(cub->WE);
	free(cub->EA);
	free(cub->img);
	free(cub->texture1);
	free(cub->texture2);
	free(cub->texture3);
	free(cub->texture4);
	free(cub->go_w);
	free(cub->go_s);
	free(cub->go_a);
	free(cub->go_d);
	free(cub->cam_left);
	free(cub->cam_right);
}

int	close_window(t_cub *cub)
{
	ft_putendl_fd("goodbye :)", 1);
	if (cub->img->img)
		mlx_destroy_image(cub->img->mlx, cub->img->img);
	if (cub->texture1->img)
		mlx_destroy_image(cub->img->mlx, cub->texture1->img);
	if (cub->texture2->img)
		mlx_destroy_image(cub->img->mlx, cub->texture2->img);
	if (cub->texture3->img)
		mlx_destroy_image(cub->img->mlx, cub->texture3->img);
	if (cub->texture4->img)
		mlx_destroy_image(cub->img->mlx, cub->texture4->img);
	mlx_destroy_window(cub->img->mlx, cub->img->win);
	mlx_destroy_display(cub->img->mlx);
	free(cub->img->mlx);
	free_cub_value(cub);

//	free_tab(cub->map);
	// free_tab(cub->data->parse_map->map_parse);
    // free(cub->data->parse_map);

	exit(0);
}