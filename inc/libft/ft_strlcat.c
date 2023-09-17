/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:54:39 by tmorikaw          #+#    #+#             */
/*   Updated: 2022/11/23 09:36:53 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	res = 0;
	j = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (size < ft_strlen(dest) + 1)
		return (size + ft_strlen(src));
	i = ft_strlen(dest);
	res = ft_strlen(src);
	if (size <= i)
		res = res + size;
	else
		res = res + i;
	while (src[j] != '\0' && i + 1 < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (res);
}

/* int main()
{
	char *dst = "bonjour ";
	const char *src = "ca va ?";
	size_t	i = 5;
	//printf(" %s\n", strncat(dst, src , i));
	printf(" %ld\n", ft_strlcat(dst, src , i));
} */