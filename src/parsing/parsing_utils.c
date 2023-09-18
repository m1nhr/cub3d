/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarecar <rmarecar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:00:47 by rmarecar          #+#    #+#             */
/*   Updated: 2023/09/18 19:19:24 by rmarecar         ###   ########.fr       */
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
