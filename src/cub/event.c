/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarecar <rmarecar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 04:05:29 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/13 07:24:28 by rmarecar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int    motion_mouse(int x, int y, t_cub *cub)
{
	int	previous_x;

	(void)y;
	cub->mouse_x = 750 / 2;
	previous_x = cub->mouse_x;
	cub->mouse_x = x;
	if (cub->mouse_x > previous_x)
		cub->cam_mouse_right = TRUE;
	else if (cub->mouse_x < previous_x)
		cub->cam_mouse_left = TRUE;
	else
	{
		cub->cam_mouse_left = FALSE;
		cub->cam_mouse_right = FALSE;
	}
	return (0);
}

void    keymap_event(t_cub *cub)
{
	if (cub->go_w->ok == TRUE)
		user_movement(cub, 119);
	if (cub->go_s->ok == TRUE)
		user_movement(cub, 115);
	if (cub->go_a->ok == TRUE)
		user_movement(cub, 97);
	if (cub->go_d->ok == TRUE)
		user_movement(cub, 100);
	if (cub->cam_left->ok == TRUE)
		cam_movement(cub, 65363, 0.02);
	if (cub->cam_right->ok == TRUE)
		cam_movement(cub, 65361, 0.02);
	if (cub->cam_mouse_left == TRUE && cub->mouse_on == 0)
		cam_movement(cub, 65361, 0.025);
	if (cub->cam_mouse_right == TRUE  && cub->mouse_on == 0)
		cam_movement(cub, 65363, 0.025);
	return ;
}

int	key_press(int key, t_cub *cub)
{
	if (key == XK_Escape)
		close_window(cub);
	if (key == 119)
		cub->go_w->ok = TRUE;
	if (key == 115)
		cub->go_s->ok = TRUE;
	if (key == 97)
		cub->go_a->ok = TRUE;
	if (key == 100)
		cub->go_d->ok = TRUE;
	if (key == 65363)
		cub->cam_left->ok = TRUE;
	if (key == 65361)
		cub->cam_right->ok = TRUE;
	if (key == XK_c)
		cub->mouse_on = 1;
	if (key == XK_v)
		cub->mouse_on = 0;
	display_game_frame(cub);
	return (0);
}

int	key_release(int key, t_cub *cub)
{
	if (key == 119)
		cub->go_w->ok = FALSE;
	if (key == 115)
		cub->go_s->ok = FALSE;
	if (key == 97)
		cub->go_a->ok = FALSE;
	if (key == 100)
		cub->go_d->ok = FALSE;
	if (key == 65363)
		cub->cam_left->ok = FALSE;
	if (key == 65361)
		cub->cam_right->ok = FALSE;
	return (0);
}