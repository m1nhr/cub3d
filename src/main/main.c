/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarecar <rmarecar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:24:48 by marecarraya       #+#    #+#             */
/*   Updated: 2023/09/27 17:31:07 by rmarecar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int main(int argc, char *argv[])
{
	t_main	data;

	if (parsing(argc, argv, &data) == -1)
		return (0);
	//go_cub(&data);
	free_tab(data.parse_map->map_parse);
	free(data.parse_map);
	return (0);
}