/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:39:52 by tmorikaw          #+#    #+#             */
/*   Updated: 2022/11/22 18:29:50 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0' || little == NULL)
		return ((char *)big);
	if (len == 0)
		return (0);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (i + j < len && big[i + j] == little[j] && little[j])
				j++;
			if (little[j] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}

/* int main()
{
	const char *big = "lorem ipsum dolor sit amet";
	const char *little = "dolor";
	printf(" %s = legit\n", strnstr(big, little, 8));
	printf(" %s\n", ft_strnstr(big, little, 15));
} */
