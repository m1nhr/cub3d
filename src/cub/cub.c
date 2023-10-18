/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 00:28:53 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/18 05:17:57 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	get_texture_dig(t_cub *cub, int h, int w)
{
	cub->texture3 = ft_calloc(1, sizeof(t_img));
	if (!cub->texture3)
		error_alloc(cub, "Error alloc texture3");
	cub->texture3->img = mlx_xpm_file_to_image(cub->img->mlx, cub->WE, &w, &h);
	if (!cub->texture3->img)
		return (error_void("Error texture3->img"));
	cub->texture3->data_addr = mlx_get_data_addr(cub->texture3->img,
			&(cub->texture3->bpp), &(cub->texture3->line_size),
			&(cub->texture3->endian));
	cub->texture4 = ft_calloc(1, sizeof(t_img));
	if (!cub->texture4)
		error_alloc(cub, "Error alloc texture4");
	cub->texture4->img = mlx_xpm_file_to_image(cub->img->mlx, cub->EA, &w, &h);
	if (!cub->texture4->img)
		return (error_void("Error texture4->img"));
	cub->texture4->data_addr = mlx_get_data_addr(cub->texture4->img,
			&(cub->texture4->bpp), &(cub->texture4->line_size),
			&(cub->texture4->endian));
}

void	get_texture(t_cub *cub)
{
	int	h;
	int	w;

	cub->texture1 = ft_calloc(1, sizeof(t_img));
	if (!cub->texture1)
		error_alloc(cub, "Error alloc texture1");
	cub->texture1->img = mlx_xpm_file_to_image(cub->img->mlx, cub->NO, &w, &h);
	if (!cub->texture1->img)
		return (error_void("Error texture1->img"));
	cub->texture1->data_addr = mlx_get_data_addr(cub->texture1->img,
			&(cub->texture1->bpp), &(cub->texture1->line_size),
			&(cub->texture1->endian));
	cub->texture2 = ft_calloc(1, sizeof(t_img));
	if (!cub->texture2)
		error_alloc(cub, "Error alloc texture2");
	cub->texture2->img = mlx_xpm_file_to_image(cub->img->mlx, cub->SO, &w, &h);
	if (!cub->texture2->img)
		return (error_void("Error texture2->img"));
	cub->texture2->data_addr = mlx_get_data_addr(cub->texture2->img,
			&(cub->texture2->bpp), &(cub->texture2->line_size),
			&(cub->texture2->endian));
	get_texture_dig(cub, h, w);
}

int	mlx_stuff(t_cub *cub)
{
	cub->img = ft_calloc(1, sizeof(t_img));
	if (!cub->img)
		error_alloc(cub, "Error alloc cub->img");
	cub->img->mlx = mlx_init();
	if (!cub->img->mlx)
		return (error_ok("Error mlx_init", 1));
	cub->img->win = mlx_new_window(cub->img->mlx, 750, 750, "CUB3D");
	if (!cub->img->win)
		return (error_ok("Error mlx_win", 1));
	cub->img->img = mlx_new_image(cub->img->mlx, HEIGHT, WIGHT);
	cub->img->data_addr = mlx_get_data_addr(cub->img->img, &(cub->img->bpp),
			&(cub->img->line_size), &(cub->img->endian));
	return (0);
}

void	go_cub(t_main *data)
{
	t_cub	cub;

	init_value(&cub, data);
	if (mlx_stuff(&cub))
		return ;
	get_texture(&cub);
	mlx_hook(cub.img->win, KeyPress, KeyPressMask, &key_press, &cub);
	mlx_hook(cub.img->win, MotionNotify, PointerMotionMask, &motion_mouse, &cub);
	//	mlx_do_key_autorepeaton(cub.mlx);
	mlx_hook(cub.img->win, KeyRelease, KeyReleaseMask, &key_release, &cub);
	mlx_hook(cub.img->win, DestroyNotify, 0, &close_window, &cub);
	if (cub.mouse_on == 0)
		mlx_mouse_hide(cub.img->mlx, cub.img->win);
	mlx_loop_hook(cub.img->mlx, &display_game_frame, &cub);
	mlx_loop(cub.img->mlx);
	//	mlx_do_key_autorepeatoff(cub.mlx);
}
