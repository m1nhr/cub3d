/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:24:48 by marecarraya       #+#    #+#             */
/*   Updated: 2023/10/18 03:00:42 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	main(int argc, char *argv[])
{
	t_main	data;

	if (parsing(argc, argv, &data) == -1)
		return (0);
	go_cub(&data);
	return (0);
}
