/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:40:20 by marecarraya       #+#    #+#             */
/*   Updated: 2023/10/19 04:37:39 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_args(int argc, char *av[])
{
	int	fd;

	if (argc == 1 || argc > 2)
		return (printf("Error\nInvalid number of arguments\n"));
	if (!check_format(av[1]))
		return (printf("Error\n%s isn't a .cub file\n", av[1]));
	fd = open(av[1], O_DIRECTORY);
	if (fd != -1)
		return (printf("Error\n%s is a directory\n", av[1]));
	fd = open(av[1], O_RDONLY);
	if ((fd < 0))
	{
		perror(av[1]);
		return (-1);
	}
	close(fd);
	return (0);
}

int	find_map_start(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && j < 6)
	{
		if (!strncmp(&str[i], "NO ", 3) || !strncmp(&str[i], "SO ", 3))
			j++;
		if (!strncmp(&str[i], "EA ", 3) || !strncmp(&str[i], "WE ", 3))
			j++;
		if (!strncmp(&str[i], "F ", 2) || !strncmp(&str[i], "C ", 2))
			j++;
		i++;
	}
	if (j != 6)
	{
		printf("\nError\nMissing textures or colors information\n");
		exit (1);
	}
	while (str[i] && str[i] != '\n')
		i++;
	while (str[i] == '\n')
		i++;
	return (i);
}

int	check_map_str(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = find_map_start(str) - 1;
	while (str[++i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			printf("Error\nEmpty line in map\n");
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (-1);
		if (is_not_valid_char(str[i]))
			return (-1);
		if (ft_isalpha(str[i]))
			j++;
		if (j > 1)
			printf("Error\nTwo starting positions\n");
		if (j > 1)
			return (-1);
	}
	if (j == 0)
		printf("Error\nNo starting position\n");
	if (j == 0)
		return (-1);
	return (0);
}

int	init_data(t_main *data, char *map_name)
{
	init_values(data);
	if (init_map(data->parse_map, map_name) == -1)
	{
		free_tab(data->parse_map->map_parse);
		free(data->parse_map);
		return (-1);
	}
	data->map = data->parse_map->map;
	if (!init_textures(data, data->parse_map->map_parse))
	{
		free_textures(data);
		free_tab(data->parse_map->map_parse);
		free(data->parse_map);
		return (-1);
	}
	return (0);
}

int	parsing(int argc, char *argv[], t_main *data)
{
	if (check_args(argc, argv) != 0)
		return (-1);
	if (init_data(data, argv[1]) == -1)
		return (-1);
	if (check_textures(data) == -1)
	{
		free_textures(data);
		return (-1);
	}
	return (0);
}
