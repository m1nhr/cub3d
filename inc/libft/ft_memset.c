/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:27:31 by tmorikaw          #+#    #+#             */
/*   Updated: 2022/11/13 17:49:43 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = s;
	while (i < n)
	{
		*str = c;
		str++;
		i++;
	}
	return (s);
}

/* int	main(void)
{
	int c = 5;
	void *s;
	
	s = (void *)malloc(sizeof(int));
	printf("%ld\n", sizeof(s));
	size_t n = 5;
	size_t i = 0;
	//memset(s, c, 5);
	ft_memset(s, c, n);
	while (i < n)
	{
		printf("%d\n", *(char *)s);
		i++;
		s++;
	}
	//printf("%ld\n", sizeof(char*));
} */