/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:19:31 by neprocur          #+#    #+#             */
/*   Updated: 2014/12/13 21:08:38 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*new;

	i = 0;
	new = (unsigned char *)b;
	while (i < len)
	{
		new[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
