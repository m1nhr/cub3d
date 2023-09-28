/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 07:31:46 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/09/28 07:32:20 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	what_lentab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

double	get_start_pos(t_cub *cub, int ok)
{
	double	x;
	double	y;
	char	*finder;

	finder = "NESW";
	y = 0;
	while (cub->map[(int)y])
	{
		x = 0;
		while (cub->map[(int)y][(int)x])
		{
			if (ft_strchr(finder, cub->map[(int)y][(int)x]))
			{
				if (ok)
					return (x);
				return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}
