/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:46:53 by rmarecar          #+#    #+#             */
/*   Updated: 2023/10/22 09:52:49 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	free_textures(t_main *data)
{
	if (data->no)
		free(data->no);
	if (data->ea)
		free(data->ea);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
}

int	check_textures(t_main *data)
{
	if (access(data->no, R_OK))
	{
		perror(data->no);
		return (-1);
	}
	if (access(data->so, R_OK))
	{
		perror(data->so);
		return (-1);
	}
	if (access(data->ea, R_OK))
	{
		perror(data->ea);
		return (-1);
	}
	if (access(data->we, R_OK))
	{
		perror(data->we);
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
		data->so = s1;
		return (1);
	}
	else if (!ft_strncmp(&str[i], "WE ", 3))
	{
		i += 3;
		while (str[i] == ' ')
			i++;
		s1 = ft_strtrim(&str[i], " ");
		data->we = s1;
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
		data->no = s1;
		return (1);
	}
	else if (!ft_strncmp(&str[i], "EA ", 3))
	{
		i += 3;
		while (str[i] == ' ')
			i++;
		s1 = ft_strtrim(&str[i], " ");
		data->ea = s1;
		return (1);
	}
	return (get_textures2(data, str, i));
}
