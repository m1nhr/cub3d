/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarecar <rmarecar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:52:04 by rmarecar          #+#    #+#             */
/*   Updated: 2023/10/03 17:55:07 by rmarecar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	**map_to_tab(int fd)
{
	char	*s1;
	char	*s2;
	char	**tab;

	s1 = malloc(sizeof(char));
	s1[0] = '\0';
	s2 = "a";
	while (s2)
	{
		s2 = get_next_line(fd);
		if (s2)
			s1 = ft_strjoin(s1, s2);
		free(s2);
	}
	close(fd);
	if (check_map_str(s1) == -1)
	{
		free(s1);
		return (NULL);
	}
	tab = ft_split(s1, '\n');
	free(s1);
	return (tab);
}

char	**fill_map(char **map)
{
	int		i;
	char	*tmp;
	int		len;
	int		size;

	len = longest_len(map);
	i = 0;
	while (map[i])
	{
		size = len - ft_strlen(map[i]) + 1;
		tmp = malloc(sizeof(char) * size + 1);
		add_space(tmp, size);
		map[i] = ft_strjoin(map[i], tmp);
		free(tmp);
		i++;
	}
	return (map);
}

int	verif_around(char **map, int x, int y)
{
	if ((y == 0 || y == (int)ft_tablen(map)) && map[y][x] == '0')
		return (printf("Error: map isn't closed\n"));
	if (x == 0 && map[y][x] == '0')
		return (printf("Error: map isn't closed"));
	if (map[y][x] == '0')
	{
		if (y != (int)ft_tablen(map) - 1 && y != 0 && x != 0
			&& x != (int)ft_strlen(map[y]) - 1)
		{
			if (map[y - 1][x] == ' ' || map[y + 1][x] == ' ')
				return (printf("Error: map isn't closed\n"));
			if (map[y][x - 1] == ' ' || map[y][x + 1] == ' ')
				return (printf("Error: map isn't closed\n"));
		}
	}
	return (0);
}

int	verif_map(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (verif_around(map, x, y))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	init_map(t_parse_map *parser, char *map_name)
{
	parser->fd = open(map_name, O_RDWR);
	if (parser->fd < 0)
	{
		perror(map_name);
		return (-1);
	}
	parser->map_parse = map_to_tab(parser->fd);
	if (parser->map_parse == NULL)
		return (-1);
	parser->map = &(parser->map_parse[6]);
	parser->map = fill_map(parser->map);
	if (!verif_map(parser->map))
		return (-1);
	return (0);
}
