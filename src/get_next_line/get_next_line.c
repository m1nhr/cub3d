/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarecar <rmarecar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:12:34 by rmarecar          #+#    #+#             */
/*   Updated: 2023/09/20 15:59:46 by rmarecar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	has_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_line(char *str)
{
	int		len;
	int		i;
	char	*dest;

	i = 0;
	len = 0;
	if (!str[i])
		return (NULL);
	while (str[len] && str[len] != '\n')
		len++;
	dest = ft_callocgnl((len + 2), sizeof(char));
	if (!dest)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_new_line(int fd, char *str)
{
	int		rd;
	char	*buff;

	rd = 1;
	buff = ft_callocgnl(sizeof(char), (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rd = 1;
	while (rd != 0 && !has_newline(buff))
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd] = '\0';
		str = ft_strjoingnl(str, buff);
	}
	free(buff);
	return (str);
}

char	*left_line(char *str)
{
	int		i;
	int		j;
	char	*dest;

	j = 0;
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	dest = ft_callocgnl((ft_lengnl(str) - i + 1), sizeof(char));
	if (!dest)
		return (NULL);
	i++;
	while (str[i + j])
	{
		dest[j] = str[i + j];
		j++;
	}
	dest[j] = '\0';
	free(str);
	return (dest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	str = get_new_line(fd, str);
	if (!str)
		return (NULL);
	line = get_line(str);
	str = left_line(str);
	return (line);
}

/*
int	main()
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);

	printf("1 %s", get_next_line(fd));
	printf("2 %s", get_next_line(fd));
	printf("3 %s", get_next_line(fd));
	printf("4 %s", get_next_line(fd));
	printf("5 %s", get_next_line(fd));
	printf("6 %s", get_next_line(fd));
	printf("7 %s", get_next_line(fd));
	
}*/
