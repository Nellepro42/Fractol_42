/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 12:28:18 by neprocur          #+#    #+#             */
/*   Updated: 2014/11/26 16:30:58 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char		*new;
	unsigned int		i;

	new = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		new[i] = '\0';
		i++;
	}
}
