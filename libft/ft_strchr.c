/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:49:09 by neprocur          #+#    #+#             */
/*   Updated: 2014/11/11 13:50:16 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*a;
	unsigned char	b;

	i = 0;
	a = (unsigned char *)s;
	b = c;
	while (a[i])
	{
		if (a[i] == b)
			return ((char *)&a[i]);
		i++;
	}
	if (a[i] == '\0' && a[i] == b)
		return ((char *)&a[i]);
	return (0);
}
