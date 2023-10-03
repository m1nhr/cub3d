/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarecar <rmarecar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:44:28 by rmarecar          #+#    #+#             */
/*   Updated: 2023/10/03 17:04:32 by rmarecar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	check_colors(t_main *data, t_colors colors)
{
	if (colors.red < 0 || colors.red > 255)
	{
		printf("Error: %d is an invalid color value\n", colors.red);
		free_tab(data->parse_map->map_parse);
		free(data->parse_map);
		exit(1);
	}
	if (colors.green < 0 || colors.green > 255)
	{
		printf("Error: %d is an invalid color value\n", colors.green);
		free_tab(data->parse_map->map_parse);
		free(data->parse_map);
		exit(1);
	}
	if (colors.blue < 0 || colors.blue > 255)
	{
		printf("Error: %d is an invalid color value\n", colors.blue);
		free_tab(data->parse_map->map_parse);
		free(data->parse_map);
		exit(1);
	}
}

void	check_colors_str(t_main *data, char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			while (tab[i][j] == ' ' || tab[i][j] == '\t')
				j++;
			if (!ft_isdigit(tab[i][j]))
			{
				printf("Error: non digit character in colors : %c\n", tab[i][j]);
				free_tab(tab);
				free_tab(data->parse_map->map_parse);
				free(data->parse_map);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

int	get_colors(t_main *data, char *str)
{
	int		i;
	char	**tab;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (!strncmp(&str[i], "C ", 2))
	{
		i += 2;
		tab = ft_split(&str[i], ',');
		data->colors_ceiling.red = ft_atoi(tab[0]);
		data->colors_ceiling.green = ft_atoi(tab[1]);
		data->colors_ceiling.blue = ft_atoi(tab[2]);
		check_colors_str(data, tab);
		free_tab(tab);
		check_colors(data, data->colors_ceiling);
		return (1);
	}
	if (!strncmp(&str[i], "F ", 2))
	{
		i += 2;
		tab = ft_split(&str[i], ',');
		data->colors_floor.red = ft_atoi(tab[0]);
		data->colors_floor.green = ft_atoi(tab[1]);
		data->colors_floor.blue = ft_atoi(tab[2]);
		check_colors_str(data, tab);
		free_tab(tab);
		check_colors(data, data->colors_floor);
		return (1);
	}
	return (0);
}
