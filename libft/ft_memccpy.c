/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 20:27:55 by neprocur          #+#    #+#             */
/*   Updated: 2014/12/13 20:55:46 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	unsigned int	i;

	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	i = 0;
	if (src == NULL)
		return (NULL);
	while (i < n)
	{
		if (b[i] == (unsigned char)c)
		{
			a[i] = b[i];
			i++;
			return ((void *)&a[i]);
		}
		else
		{
			a[i] = b[i];
			i++;
		}
	}
	return (NULL);
}
