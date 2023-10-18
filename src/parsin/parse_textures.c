/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarecar <rmarecar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:46:53 by rmarecar          #+#    #+#             */
/*   Updated: 2023/10/18 01:28:39 by rmarecar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	init_textures(t_main *data, char **map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!get_textures(data, map[i]))
		{
			printf("Error: invalid textures\n%s\n", map[i]);
			return (0);
		}
		i++;
	}
	while (i < 6)
	{
		if (!get_colors(data, map[i]))
		{
			printf("Error: invalid colors\n%s\n", map[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

int	get_textures2(t_main *data, char *str, int i)
{
	if (!ft_strncmp(&str[i], "SO ", 3))
	{
		i += 3;
		while (str[i] == ' ')
			i++;
		data->SO = &str[i];
		return (1);
	}
	else if (!ft_strncmp(&str[i], "WE ", 3))
	{
		i += 3;
		while (str[i] == ' ')
			i++;
		data->WE = &str[i];
		return (1);
	}
	else
		return (0);
}

int	get_textures(t_main *data, char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (!ft_strncmp(&str[i], "NO ", 3))
	{
		i += 3;
		while (str[i] == ' ')
			i++;
		data->NO = &str[i];
		return (1);
	}
	else if (!ft_strncmp(&str[i], "EA ", 3))
	{
		i += 3;
		while (str[i] == ' ')
			i++;
		data->EA = &str[i];
		return (1);
	}
	return (get_textures2(data, str, i));
}
