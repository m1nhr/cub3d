/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshikuro <keshikuro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:56:35 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/08/31 03:08:50 by keshikuro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char		*str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		len = 0;
	else if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	str = malloc(sizeof(char) * len + 2);
	if (!str)
		return (NULL);
	if (len != 0)
		ft_strlcpy(str, s + start, len);
	else
		*str = 0;
	return (str);
}

/* int	main()
{
	char *str = "echo1'okok'";
	//int	start = 2;
	//int	len = 3;
	printf(" %s", ft_substr(str, 5, 5));
} */