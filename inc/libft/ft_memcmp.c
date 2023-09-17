/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:03:30 by tmorikaw          #+#    #+#             */
/*   Updated: 2022/11/22 18:11:27 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*st1;
	unsigned char	*st2;
	size_t			i;

	i = 0;
	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	while (i < n)
	{
		if (st1[i] != st2[i])
			return (st1[i] - st2[i]);
		i++;
	}
	return (0);
}

/* int main()
{
	char *s1 = "hello";
	char *s2 = "h3lloo";
	size_t n = 3;
	printf(" %d\n", memcmp(s1, s2, n));
	printf(" %d\n", ft_memcmp(s1, s2, n));
}

 int    main()
{
    char s1[6] = "hello";
    char s2[7] = "helloo";
    int    size = 7;

    printf("%d\n", memcmp(s1, s2, size));
    printf("%d\n", ft_memcmp(s1, s2, size));
} */