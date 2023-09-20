/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:40:20 by marecarraya       #+#    #+#             */
/*   Updated: 2023/09/21 00:13:29 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_args(int argc, char *av[])
{
	int	fd;

	if (argc == 1 || argc > 2)
		return (printf("Error: Invalid number of arguments\n"));
	if (!check_format(av[1]))
		return (printf("Error: %s isn't a .cub file\n", av[1]));
	if ((fd = open(av[1], O_DIRECTORY) != -1))
		return (printf("Error: %s is a directory\n", av[1]));
	if ((fd = open(av[1], O_RDONLY) <= 0))
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
	while (str[i])
	{
		if (!strncmp(&str[i], "NO ", 3))
			j++;
		if (!strncmp(&str[i], "SO ", 3))
			j++;
		if (!strncmp(&str[i], "EA ", 3))
			j++;
		if (!strncmp(&str[i], "WE ", 3))
			j++;
		if (!strncmp(&str[i], "F ", 2))
			j++;
		if (!strncmp(&str[i], "C ", 2))
			j++;
		if (j == 6)
			break ;
		i++;
	}
	if (j != 6)
	{
		printf("\nmissing information %d\n", j); 
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

	i = find_map_start(str);
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			printf("Error: empty line in map\n");
			return (-1);
		}
		if (is_not_valid_char(str[i]))
			return (-1);
		i++;
	}
	return (0);
}

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

void	add_space(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
}

char	**fill_map(char **map)
{
	int 	i;
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
		if (y != (int)ft_tablen(map) - 1 && y != 0 && x != 0 && x != (int)ft_strlen(map[y]) - 1)
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

int	check_map(t_parse_map *parser)
{
	parser->map = fill_map(parser->map);
	if (!verif_map(parser->map))
		return (0);	
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
	if (!check_map(parser))
		return (-1);
	return (0);
}

// void	get_textures()
// int	init_textures(t_main *data, char **map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			while (map[i][j] == ' ' || map[i][j] == '\n')
// 				j++;
			
// 			j++;
// 		}
// 	}
// }

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
	// init_textures(data, data->parse_map->map_parse);
	return (0);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int parsing(int argc, char *argv[], t_main *data)
{
	if (check_args(argc, argv) != 0)
		return (-1);
	if (init_data(data, argv[1]) == -1)
		return (-1);
	return (0);
}

