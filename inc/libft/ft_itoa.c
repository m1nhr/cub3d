/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:57:45 by tmorikaw          #+#    #+#             */
/*   Updated: 2022/11/19 19:20:51 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbn(long long int n)
{
	int	nbr;
	int	nb;

	if (n == -2147483648)
		return (11);
	nbr = n;
	nb = 1;
	if (n < 0)
	{
		nb++;
		nbr = nbr * -1;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		nb++;
	}
	return (nb);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				index;
	long long int	nbr;

	str = malloc(sizeof(char) * (ft_nbn(n) + 1));
	if (!str)
		return (NULL);
	str[ft_nbn(n)] = '\0';
	index = ft_nbn(n) - 1;
	nbr = n;
	if (n < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr >= 10)
	{
		str[index] = (nbr % 10) + '0';
		nbr = nbr / 10;
		index--;
	}
	str[index] = nbr + 48;
	return (str);
}

/* int	main(void)
{
	char	*array;
	array = ft_itoa(-123);
	printf("%s\n", array);
	free(array);
	return (0);
} */