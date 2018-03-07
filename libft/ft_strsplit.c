/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 11:37:38 by neprocur          #+#    #+#             */
/*   Updated: 2014/12/13 20:43:37 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				ft_count_word(char const *s, char c)
{
	unsigned int		i;
	unsigned int		nb_word;

	i = 0;
	nb_word = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			nb_word++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (nb_word);
}

static char				**ft_malloc_tabl(int nb_word)
{
	char				**tabl;

	tabl = (char **)malloc(sizeof(char *) * (nb_word + 1));
	if (!tabl)
		return (NULL);
	return (tabl);
}

static void				ft_fill_tabl(char const *s, char c, char **tabl)
{
	int					i;
	int					j;
	int					k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j = i;
			while (s[i] && s[i] != c)
				i++;
			tabl[k] = ft_strsub(s, j, (i - j));
			k++;
		}
	}
	tabl[k] = NULL;
}

char					**ft_strsplit(char const *s, char c)
{
	char				**tabl;
	int					nb_word;

	if (!s)
		return (NULL);
	nb_word = ft_count_word(s, c);
	tabl = ft_malloc_tabl(nb_word);
	if (tabl == NULL)
		return (NULL);
	ft_fill_tabl(s, c, tabl);
	return (tabl);
}
