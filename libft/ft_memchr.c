/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:09:13 by neprocur          #+#    #+#             */
/*   Updated: 2014/12/13 20:56:02 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*a;
	unsigned int	i;

	a = (unsigned char *)s;
	i = 0;
	if (s == NULL)
		return (NULL);
	while (i < n)
	{
		if (a[i] == (unsigned char)c)
			return ((void *)&a[i]);
		i++;
	}
	return (NULL);
}
