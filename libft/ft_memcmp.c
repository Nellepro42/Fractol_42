/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:26:54 by neprocur          #+#    #+#             */
/*   Updated: 2014/12/13 20:56:25 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*a;
	unsigned char		*b;
	unsigned int		i;
	unsigned int		diff;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	i = 0;
	diff = 0;
	if (!s1 || !s2 || s1 == s2 || n == 0)
		return (0);
	while (i < n)
	{
		diff += (a[i] - b[i]);
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (diff);
}
