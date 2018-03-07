/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:11:08 by neprocur          #+#    #+#             */
/*   Updated: 2014/12/13 20:59:43 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncat(char *s1, const char *s2, size_t n)
{
	char			*a;
	unsigned int	i;
	unsigned int	j;

	a = (char *)s2;
	i = 0;
	j = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[i])
		i++;
	while (j < n && a[j])
	{
		s1[i + j] = (char)a[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}
