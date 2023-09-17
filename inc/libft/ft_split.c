/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarecar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:20:42 by rmarecar          #+#    #+#             */
/*   Updated: 2022/11/21 11:39:54 by rmarecar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	ft_issep(char cmp, char c)
{
	if (cmp == c)
		return (1);
	return (0);
}

static int	ft_alloctxt(char **tab, const char *s, char c)
{
	int	word_len;
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && ft_issep(*s, c))
			s++;
		word_len = 0;
		while (*s && ft_issep(*s, c) == 0)
		{
			word_len++;
			s++;
		}
		if (word_len != 0)
		{
			tab[i] = malloc(word_len + 1);
			if (tab[i] == 0)
				return (0);
			tab[i++][word_len] = 0;
		}
	}
	return (1);
}

static void	ft_filltab(char **tab, const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	while (*s && tab[i])
	{
		while (*s && ft_issep(*s, c))
			s++;
		j = 0;
		while (*s && ft_issep(*s, c) == 0)
			tab[i][j++] = *(s++);
		i++;
	}
}

static unsigned int	ft_countwords(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] && ft_issep(s[i], c) == 0)
		{
			count++;
			i++;
		}
		while (s[i] && ft_issep(s[i], c) == 0)
			i++;
		while (s[i] && ft_issep(s[i], c))
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char				**tab;
	unsigned int		nb_words;
	unsigned int		i;

	if (!s)
		return (NULL);
	nb_words = ft_countwords(s, c);
	tab = malloc((nb_words + 1) * sizeof(char *));
	if (tab == 0)
		return (0);
	tab[nb_words] = 0;
	if (nb_words > 0)
	{
		if (ft_alloctxt(tab, s, c) == 0)
		{
			i = 0;
			while (tab[i])
				free(tab[i++]);
			free(tab);
			return (0);
		}
		ft_filltab(tab, s, c);
	}
	return (tab);
}
