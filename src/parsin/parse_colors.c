/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:44:28 by rmarecar          #+#    #+#             */
/*   Updated: 2023/10/22 09:36:38 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	check_colors(t_main *data, t_colors colors, char **tab)
{
	if (colors.red < 0 || colors.red > 255 || colors.green < 0
		|| colors.green > 255 || colors.blue < 0 || colors.blue > 255)
	{
		printf("Error\nInvalid color value\n");
		free_textures(data);
		free_tab(data->parse_map->map_parse);
		free(data->parse_map);
		free_tab(tab);
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
				printf("Error\nnon digit character in colors : %c\n", tab[i][j]);
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

void	add_colors(t_main *data, char **tab, char c)
{
	if (c == 'C')
	{
		data->colors_ceiling.red = ft_atoi(tab[0]);
		data->colors_ceiling.green = ft_atoi(tab[1]);
		data->colors_ceiling.blue = ft_atoi(tab[2]);
		check_colors(data, data->colors_ceiling, tab);
	}
	if (c == 'F')
	{
		data->colors_floor.red = ft_atoi(tab[0]);
		data->colors_floor.green = ft_atoi(tab[1]);
		data->colors_floor.blue = ft_atoi(tab[2]);
		check_colors(data, data->colors_floor, tab);
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
		add_colors(data, tab, 'C');
		check_colors_str(data, tab);
		free_tab(tab);
		return (1);
	}
	if (!strncmp(&str[i], "F ", 2))
	{
		i += 2;
		tab = ft_split(&str[i], ',');
		add_colors(data, tab, 'F');
		check_colors_str(data, tab);
		free_tab(tab);
		return (1);
	}
	return (0);
}
