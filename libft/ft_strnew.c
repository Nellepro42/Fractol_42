/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 20:23:28 by neprocur          #+#    #+#             */
/*   Updated: 2015/03/17 11:59:45 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnew(size_t size)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)malloc(sizeof(str) * size);
	if (str == NULL)
		return (0);
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
	i = 0;
	return ((char *)str);
}
