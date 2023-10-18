/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 07:31:46 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/18 05:18:38 by tmorikaw         ###   ########.fr       */
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

double	start_pos(char **tab, int ok)
{
	double	y;
	double	x;
	char	*finder;

	x = 0;
	finder = "NESW";
	while (tab[(int)x])
	{
		y = 0;
		while (tab[(int)x][(int)y])
		{
			if (ft_strchr(finder, tab[(int)x][(int)y]))
			{
				if (ok)
					return (y);
				return (x);
			}
			y++;
		}
		x++;
	}
	return (0);
}

void	error_void(char *str)
{
	ft_putendl_fd(str, 1);
	exit (1);
}


float	ft_fabs(float i)
{
	if (i < 0)
		return (i *= -1);
	return (i);
}
