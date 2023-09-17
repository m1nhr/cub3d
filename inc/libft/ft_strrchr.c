/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:21:27 by tmorikaw          #+#    #+#             */
/*   Updated: 2022/11/22 18:31:25 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	while (i <= len)
	{
		if (s[len - i] == (unsigned char)c)
			return ((char *)s + len - i);
		i++;
	}
	return (NULL);
}

/* int main()
{
	const char *s = "bonjour";
	int c = 's';
	printf("fake : %s\n", ft_strrchr(s, c));
	printf("legit : %s\n", strrchr(s, c));
}
voir test 5 (war_machine) s = bonjour / c = 's' */