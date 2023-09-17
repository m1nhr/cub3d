/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marecarrayan <marecarrayan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:24:48 by marecarraya       #+#    #+#             */
/*   Updated: 2023/09/18 00:22:54 by marecarraya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int main(int argc, char *argv[])
{
	t_main	data;

	if (parsing(argc, argv, &data) == -1)
		return (0);
	return (0);
}