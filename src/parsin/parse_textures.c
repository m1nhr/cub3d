/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarecar <rmarecar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:46:53 by rmarecar          #+#    #+#             */
/*   Updated: 2023/10/18 03:43:33 by rmarecar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	free_textures(t_main *data)
{
	if (data->NO)
		free(data->NO);
	if (data->EA)
		free(data->EA);
	if (data->SO)
		free(data->SO);
	if (data->WE)
		free(data->WE);
}

int	check_textures(t_main *data)
{
	if (access(data->NO, R_OK))
	{
		perror(data->NO);
		return (-1);
	}
	if (access(data->SO, R_OK))
	{
		perror(data->SO);
		return (-1);
	}
	if (access(data->EA, R_OK))
	{
		perror(data->EA);
		return (-1);
	}
	if (access(data->WE, R_OK))
	{
		perror(data->WE);
		return (-1);
	}
	return (0);
}

int	init_textures(t_main *data, char **map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!get_textures(data, map[i]))
		{
			printf("Error\nInvalid textures\n%s\n", map[i]);
			return (0);
		}
		i++;
	}
	while (i < 6)
	{
		if (!get_colors(data, map[i]))
		{
			printf("Error\nInvalid colors\n%s\n", map[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

int	get_textures2(t_main *data, char *str, int i)
{
	char	*s1;

	if (!ft_strncmp(&str[i], "SO ", 3))
	{
		i += 3;
		while (str[i] == ' ')
			i++;
		s1 = ft_strtrim(&str[i], " ");
		data->SO = s1;
		return (1);
	}
	else if (!ft_strncmp(&str[i], "WE ", 3))
	{
		i += 3;
		while (str[i] == ' ')
			i++;
		s1 = ft_strtrim(&str[i], " ");
		data->WE = s1;
		return (1);
	}
	else
		return (0);
}

int	get_textures(t_main *data, char *str)
{
	int		i;
	char	*s1;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (!ft_strncmp(&str[i], "NO ", 3))
	{
		i += 3;
		while (str[i] == ' ')
			i++;
		s1 = ft_strtrim(&str[i], " ");
		data->NO = s1;
		return (1);
	}
	else if (!ft_strncmp(&str[i], "EA ", 3))
	{
		i += 3;
		while (str[i] == ' ')
			i++;
		s1 = ft_strtrim(&str[i], " ");
		data->EA = s1;
		return (1);
	}
	return (get_textures2(data, str, i));
}
