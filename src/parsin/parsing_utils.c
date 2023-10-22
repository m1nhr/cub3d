/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:00:47 by rmarecar          #+#    #+#             */
/*   Updated: 2023/10/22 09:51:09 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

size_t	ft_tablen(char **tab)
{
	size_t	len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

char	**ft_tabdup(char **tab)
{
	char	**dest;
	size_t	y;

	y = 0;
	dest = malloc(sizeof(char *) * (ft_tablen(tab) + 1));
	while (y < ft_tablen(tab))
	{
		dest[y] = ft_strdup(tab[y]);
		y++;
	}
	dest[y] = NULL;
	return (dest);
}

int	check_format(char *s)
{
	int		len;
	int		i;
	char	*cub;

	cub = ".cub";
	len = ft_strlen(s) - 1;
	i = 3;
	while (i >= 0)
	{
		if (cub[i] != s[len])
			return (0);
		i--;
		len--;
	}
	return (1);
}

void	init_values(t_main *data)
{
	data->map = NULL;
	data->parse_map = malloc(sizeof(t_parse_map));
	data->parse_map->height = 0;
	data->parse_map->width = 0;
	data->parse_map->map_parse = NULL;
	data->no = NULL;
	data->ea = NULL;
	data->so = NULL;
	data->we = NULL;
}

int	is_not_valid_char(char c)
{
	if (c == ' ' || c == '\n' || c == '0' || c == '1')
		return (0);
	if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
		return (0);
	printf("Error\nMap has invalid char: '%c'\n", c);
	return (1);
}
