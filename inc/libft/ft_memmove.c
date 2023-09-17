/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:04:36 by tmorikaw          #+#    #+#             */
/*   Updated: 2022/11/23 09:30:46 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest == src)
		return (dest);
	if (dest > src)
	{
		while (n > 0)
		{
			n--;
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

/* int	main(void)
{
	size_t	len;
	char	str[] = "takeshi okok koko";
	len = 0;
	ft_memmove(str + 8, str + 13, 4);
	while (str[len])
	{
		printf("%c", str[len]);
		len++;
	}
	printf("\n");
} */