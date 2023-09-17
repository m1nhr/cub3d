/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:49:37 by tmorikaw          #+#    #+#             */
/*   Updated: 2022/11/12 18:47:07 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = s;
	while (i < n)
	{
		*str = 0;
		str++;
		i++;
	}
}

/* int	main(void)
{
	int c = 5;
	void *s;
	
	s = malloc(sizeof(int) * 2);
	//printf("%ld\n", sizeof(s));
	size_t n = 5;
	size_t i = 0;
	//bzero(s, 5);
	ft_bzero(s, n);
	while (i < n)
	{
		printf("%d\n", *(char *)s);
		i++;
		s++;
	}
	//printf("%ld\n", sizeof(char*));
} */