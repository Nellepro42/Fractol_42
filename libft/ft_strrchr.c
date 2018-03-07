/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 18:32:55 by neprocur          #+#    #+#             */
/*   Updated: 2014/11/11 13:38:46 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	*a;
	unsigned char	b;

	a = (unsigned char *)s;
	b = c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (a[i] == b)
			return ((char *)&a[i]);
		i--;
	}
	if (a[i] == b && i == 0)
		return ((char *)&a[i]);
	return (0);
}
