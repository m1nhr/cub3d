/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:12:06 by tmorikaw          #+#    #+#             */
/*   Updated: 2022/11/23 09:08:30 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (n == 0)
		return (dest);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/* int main()
{
	char *src = "123456";
	size_t n = 8;

	char *dest;
	dest = malloc(sizeof(char) * 10);
	int i = 0;
	while (i < 10)
	{
		dest[i] = 'Q';
		i++;
	}
	char *dest1;
	dest1 = malloc(sizeof(char) * 10);
	i = 0;
	while (i < 10)
	{
		dest1[i] = 'Q';
		i++;
	}
	ft_memcpy(dest, src, n);
	memcpy(dest1, src, n);
	printf(" %s\n", dest);
	printf(" %s\n", dest1);
}  */