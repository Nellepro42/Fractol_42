/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 14:44:46 by neprocur          #+#    #+#             */
/*   Updated: 2014/12/13 20:57:44 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (s1 && s2)
		new = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s1 && s2)
		return (ft_strdup((char *)s2));
	else if (s1 && !s2)
		return (ft_strdup((char *)s1));
	else if (!new || !s1)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[n])
		new[i++] = s2[n++];
	new[i] = '\0';
	return (new);
}
