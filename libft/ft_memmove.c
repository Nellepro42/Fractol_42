/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 12:15:59 by neprocur          #+#    #+#             */
/*   Updated: 2014/12/13 21:05:26 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	unsigned char	*buffer;
	char			*new;

	new = (char *)dst;
	i = 0;
	buffer = (unsigned char *)malloc(sizeof(src) * len);
	if (buffer == NULL)
		return (NULL);
	while (i < len)
	{
		buffer[i] = *(unsigned char *)(src + i);
		i++;
	}
	i = 0;
	while (i < len)
	{
		new[i] = buffer[i];
		i++;
	}
	free(buffer);
	return ((void *)new);
}
