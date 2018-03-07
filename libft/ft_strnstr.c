/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 15:18:49 by neprocur          #+#    #+#             */
/*   Updated: 2015/04/22 17:25:32 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (*s2 == '\0')
		return ((char*)s1);
	len = ft_strlen(s2);
	while (s1[i] && (i + len) <= n)
	{
		if (ft_strncmp(s1 + i, s2, len) == 0)
			return ((char*)s1 + i);
		i++;
	}
	return (NULL);
}
