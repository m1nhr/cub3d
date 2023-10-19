/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:24:48 by marecarraya       #+#    #+#             */
/*   Updated: 2023/10/19 04:38:18 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_intro(void)
{
	ft_putendl_fd("\e[35m ----------------------------------------- ", 1);
	ft_putendl_fd("| ██████╗██╗   ██╗██████╗ ██████╗ ██████╗ |", 1);
	ft_putendl_fd("|██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗|", 1);
	ft_putendl_fd("|██║     ██║   ██║██████╔╝ █████╔╝██║  ██║|", 1);
	ft_putendl_fd("|██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║|", 1);
	ft_putendl_fd("|╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝|", 1);
	ft_putendl_fd("| ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ |", 1);
	ft_putendl_fd(" ----------------------------------------- ", 1);
	ft_putendl_fd("v1.0 2023 | Copyright TTM/RMM | Do not distribute!\e[0m\n", 1);
	ft_putendl_fd("\e[45mHow to play ? \e[0m", 1);
	ft_putendl_fd("\e[45m🅆/🄰/🅂/🄳 to move around the map \e[0m", 1);
	ft_putendl_fd("\e[45m<-/-> arrow to rotate the vision \e[0m", 1);
	ft_putendl_fd("\e[45mmouse to rotate the vision too \e[0m", 1);
	ft_putendl_fd("\e[45mechap to exit \e[0m", 1);
}

int	main(int argc, char *argv[])
{
	t_main	data;

	if (parsing(argc, argv, &data) == -1)
		return (0);
	draw_intro();
	go_cub(&data);
	return (0);
}
