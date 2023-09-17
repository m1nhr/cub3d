/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshikuro <keshikuro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:58:01 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/07/19 03:09:02 by keshikuro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	size_t			start;
	size_t			end;
	size_t			i;

	start = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[start] && checkset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && checkset(s1[end - 1], set))
		end--;
	str = malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = 0;
	return (str);
}

/* int main()
{
	char const	s1[] = "\"ok ko\"";
	char const	set[] = "\"";
	printf(" %s\n", ft_strtrim(s1, set));
}
 */