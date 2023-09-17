/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:00:56 by tmorikaw          #+#    #+#             */
/*   Updated: 2022/11/24 20:08:29 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (size != 0 && nmemb != 0 && ((size * nmemb) / size != nmemb))
		return (NULL);
	tab = malloc(nmemb * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, (nmemb * size));
	return (tab);
}

/* int main()
{
	size_t	n = 0;
	char *str;
	str = calloc(n, 0);
	size_t i = 0;
	while (i < n)
	{
		printf(" %d\n", str[i]);
		i++;
	}
	free(str);
}  */
