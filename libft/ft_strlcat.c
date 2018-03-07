/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 20:20:48 by neprocur          #+#    #+#             */
/*   Updated: 2014/12/13 20:58:02 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	dst_size;
	unsigned int	src_size;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (dst_size >= size)
		return (size + src_size);
	dst = ft_strncat(dst, src, (size - dst_size - 1));
	return (dst_size + src_size);
	if (strlcat(dst, src, size) >= size)
		return (-1);
}
