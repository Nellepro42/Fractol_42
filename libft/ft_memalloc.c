/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 15:59:44 by neprocur          #+#    #+#             */
/*   Updated: 2014/12/13 20:55:26 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*a;

	a = malloc(sizeof(void *) * size);
	if (a == NULL)
		return (NULL);
	if (a)
		ft_bzero(a, size);
	return (a);
}
