/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marecarrayan <marecarrayan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:16:28 by rmarecar          #+#    #+#             */
/*   Updated: 2023/09/17 23:32:26 by marecarraya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdint.h>

char	*ft_callocgnl(size_t nmemb, size_t size)
{
	char	*tab;
	size_t	i;

	if (size != 0 && nmemb != 0 && (size * nmemb) / size != nmemb)
		return (NULL);
	tab = malloc(nmemb * size);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

size_t	ft_strlengnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoingnl(char *str, char *buf)
{
	size_t		i;
	size_t		j;
	char		*dest;

	i = 0;
	if (!str)
	{
		str = ft_callocgnl(1, sizeof(char));
	str[0] = '\0';
	}
	dest = ft_callocgnl((ft_strlengnl(str) + ft_strlengnl(buf) + 1), sizeof(char));
	if (!dest)
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	j = 0;
	while (buf[j])
		dest[i++] = buf[j++];
	free(str);
	dest[i] = '\0';
	return (dest);
}
