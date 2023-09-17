/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:21:22 by tmorikaw          #+#    #+#             */
/*   Updated: 2022/11/16 00:24:45 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;

	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((unsigned char *)s + i);
		i++;
	}
	return (0);
}

/* #include <stdio.h>
int main()
{
	char s[] = {0, 1, 2 ,3 ,4 ,5};

	//int c = 'p';
	//int size = 6;
	printf(" %s\n", memchr(s, 256, 3));
	printf(" %s\n", ft_memchr(s, 256, 3));
} */
