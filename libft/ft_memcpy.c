/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 12:42:51 by neprocur          #+#    #+#             */
/*   Updated: 2015/04/23 17:29:56 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*a;

	a = (char *)dst;
	if (ft_poney(dst, src, n) == 1)
		return (NULL);
	return (ft_strncpy(a, src, n));
}
