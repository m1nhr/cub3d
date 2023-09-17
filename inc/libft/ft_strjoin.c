/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshikuro <keshikuro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:57:02 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/08/18 02:55:16 by keshikuro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_cpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	ft_cpy(str, (char *)s1, ft_strlen(s1));
	ft_cpy(str + ft_strlen(s1), (char *)s2, ft_strlen(s2));
	return (str);
}

/* int main()
{
	char const s1[] = "lorem ipsum";
	char const s2[] = "\0";
	printf(" %s\n", ft_strjoin(s1, s2));
}
 */